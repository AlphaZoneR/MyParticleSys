#include "Font.h"

#include <Window/OpenGL.h>

#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>

namespace util {
	Font::Font(const char * name, int size) {
		FT_Library library;
		if (FT_Init_FreeType(&library)) {
			throw("Cannot initialize FreeType library!");
		}
		FT_Face face;
		if (FT_New_Face(library, name, 0, &face)) {
			throw("Cannot load the FontFace!");
		}
		int resolution = 96;
		int width = size * 64;
		int height = size * 64;
		FT_Set_Char_Size(face, width, height, resolution, resolution);

		list = glGenLists(count);
		glGenTextures(count, texture);

		for (int i = 0; i < count; ++i) {
			if (FT_Load_Glyph(face, FT_Get_Char_Index(face, i + base), FT_LOAD_DEFAULT)) {
				throw("Cannot load the glyph!");
			}
			FT_Glyph glyph;
			if(FT_Get_Glyph(face->glyph, &glyph)) {
				throw("Cannot get the glyph!");
			}
			FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_NORMAL, 0, true);
			FT_BitmapGlyph glyphBitmap = (FT_BitmapGlyph)glyph;
			FT_Bitmap & bitmap = glyphBitmap->bitmap;

			int width = bitmap.width + 2;
			int height = bitmap.rows + 2;

			int alignment = ((width * 2 + 3) / 4) * 2;

			int size = alignment * height * 2;
			char * data = new char[size];
			memset(data, 0, size);

			for (int y = 0; y < bitmap.rows; ++y)
			for (int x = 0; x < bitmap.width; ++x) {
				int dx = x + 1;
				int dy = y + 1;
				int dest = dy * alignment + dx;
				int src = y * bitmap.width + x;
				data[dest * 2 + 0] = 0xFF;
				data[dest * 2 + 1] = bitmap.buffer[src];
			}

			float left = glyphBitmap->left;
			float right = left + width;
			float bottom = glyphBitmap->top - height;
			float top = bottom + height;

			place[i] = face->glyph->advance.x / 64;

			glBindTexture(GL_TEXTURE_2D, texture[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

			GLenum type = GL_UNSIGNED_BYTE;
			GLenum format = GL_LUMINANCE_ALPHA;
			glTexImage2D(GL_TEXTURE_2D, 0, 2, width, height, 0, format, type, data);
			delete[] data;

			glNewList(list + i, GL_COMPILE);
			glBindTexture(GL_TEXTURE_2D, texture[i]);

			glBegin(GL_TRIANGLE_STRIP);
			glTexCoord2f(0, 0);
			glVertex2f(left, top);
			glTexCoord2f(0, 1);
			glVertex2f(left, bottom);
			glTexCoord2f(1, 0);
			glVertex2f(right, top);
			glTexCoord2f(1, 1);
			glVertex2f(right, bottom);
			glEnd();

			glTranslatef(place[i], 0, 0);
			glEndList();
		}

		FT_Done_Face(face);
		FT_Done_FreeType(library);
	}
	Font::~Font() {
		glDeleteLists(list, count);
		glDeleteTextures(count, texture);
	}
	void Font::Render(float x, float y, float scale, float align, const char * format, ...) {
		if (!format) {
			throw("Invalid Text Format!");
		}

		va_list ap;
		char text[256];
		va_start(ap, format);
		vsprintf(text, format, ap);
		va_end(ap);

		int length = strlen(text);

		float width = 0;
		for (int i = 0; i < length; ++i) {
			int index = text[i] - base;
			width += place[index];
		}

		glPushAttrib(GL_ENABLE_BIT);
		glEnable(GL_BLEND);
		glEnable(GL_TEXTURE_2D);
		glDisable(GL_FOG);
		glDisable(GL_LIGHTING);
		glDisable(GL_CULL_FACE);
		glPushMatrix();
		glListBase(list - base);
		glTranslatef(x - width * align * scale, y, 0);
		glScalef(scale, scale, 1);
		glCallLists(length, GL_UNSIGNED_BYTE, text);
		glPopMatrix();
		glPopAttrib();
	}
};
