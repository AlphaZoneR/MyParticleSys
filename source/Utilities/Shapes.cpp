#include "Shapes.h"

#include <Utilities/VMath.h>
#include <Window/OpenGL.h>

namespace util {
	void DrawBox(float width, float length, float height) {
		float w = width / 2;
		float l = length / 2;
		float h = height / 2;

		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-w, +l, h);
		glVertex3f(-w, -l, h);
		glVertex3f(+w, +l, h);
		glVertex3f(+w, -l, h);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(-w, -l, 0.0f);
		glVertex3f(-w, +l, 0.0f);
		glVertex3f(+w, -l, 0.0f);
		glVertex3f(+w, +l, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-w, +l, h);
		glVertex3f(+w, +l, h);
		glVertex3f(-w, +l, 0.0f);
		glVertex3f(+w, +l, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(0.0f, -1.0f, 0.0f);
		glVertex3f(+w, -l, h);
		glVertex3f(-w, -l, h);
		glVertex3f(+w, -l, 0.0f);
		glVertex3f(-w, -l, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(+w, +l, h);
		glVertex3f(+w, -l, h);
		glVertex3f(+w, +l, 0.0f);
		glVertex3f(+w, -l, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glVertex3f(-w, -l, h);
		glVertex3f(-w, +l, h);
		glVertex3f(-w, -l, 0.0f);
		glVertex3f(-w, +l, 0.0f);
		glEnd();
	}

	void DrawPyramid(float width, float length, float height) {
		float w = width / 2;
		float l = length / 2;
		float h = height / 2;

		glBegin(GL_TRIANGLE_STRIP);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(-w, -l, 0.0f);
		glVertex3f(-w, +l, 0.0f);
		glVertex3f(+w, -l, 0.0f);
		glVertex3f(+w, +l, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLES);
		glNormal3f(0.0f, h, l);
		glVertex3f(0.0f, 0.0f, h);
		glVertex3f(+w, +l, 0.0f);
		glVertex3f(-w, +l, 0.0f);

		glNormal3f(0.0f, -h, l);
		glVertex3f(0.0f, 0.0f, h);
		glVertex3f(-w, -l, 0.0f);
		glVertex3f(+w, -l, 0.0f);

		glNormal3f(h, 0.0f, w);
		glVertex3f(0.0f, 0.0f, h);
		glVertex3f(+w, -l, 0.0f);
		glVertex3f(+w, +l, 0.0f);

		glNormal3f(-h, 0.0f, w);
		glVertex3f(0.0f, 0.0f, h);
		glVertex3f(-w, +l, 0.0f);
		glVertex3f(-w, -l, 0.0f);
		glEnd();
	}

	void DrawCylinder(float radius, float height) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int h = -180; h <= 180; h += 5) {
			float ih = h * fi;

			float x = sin(ih);
			float y = cos(ih);
			glNormal3f(x, y, 0.0f);

			glVertex3f(x * radius, y * radius, 0.0f);
			glVertex3f(x * radius, y * radius, height);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(0, 0, 0);
		for (int h = -180; h <= 180; h += 5) {
			float ih = h * fi;

			float x = sin(ih);
			float y = cos(ih);

			glVertex3f(x * radius, y * radius, 0.0f);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0, 0, height);
		for (int h = -180; h <= 180; h += 5) {
			float ih = h * fi;

			float x = cos(ih);
			float y = sin(ih);

			glVertex3f(x * radius, y * radius, height);
		}
		glEnd();
	}

	void DrawSphere(float radius) {
		for (int v = 0; v < 180; v += 5) {
			float iv = v * fi;
			float iw = (v + 5) * fi;

			glBegin(GL_TRIANGLE_STRIP);
			for (int h = -180; h <= 180; h += 5) {
				float ih = h * fi;

				float x1 = sin(iv) * cos(ih);
				float y1 = sin(iv) * sin(ih);
				float z1 = cos(iv);

				float x2 = sin(iw) * cos(ih);
				float y2 = sin(iw) * sin(ih);
				float z2 = cos(iw);

				glNormal3f(x1, y1, z1);
				glVertex3f(x1 * radius, y1 * radius, z1 * radius);

				glNormal3f(x2, y2, z2);
				glVertex3f(x2 * radius, y2 * radius, z2 * radius);
			}
			glEnd();
		}
	}

	void DrawCone(float radius1, float radius2, float height) {
		glBegin(GL_TRIANGLE_STRIP);
		for (int h = -180; h <= 180; h += 5) {
			float ih = h * fi;

			float x = sin(ih);
			float y = cos(ih);

			glNormal3f(x, y, 0.0f); // NOT :)
			glVertex3f(x * radius1, y * radius1, 0.0f);
			glVertex3f(x * radius2, y * radius2, height);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0f, 0.0f, -1.0f);
		glVertex3f(0, 0, 0);
		for (int h = -180; h <= 180; h += 5) {
			float ih = h * fi;

			float x = sin(ih);
			float y = cos(ih);

			glVertex3f(x * radius1, y * radius1, 0.0f);
		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0, 0, height);
		for (int h = -180; h <= 180; h += 5) {
			float ih = h * fi;

			float x = cos(ih);
			float y = sin(ih);

			glVertex3f(x * radius2, y * radius2, height);
		}
		glEnd();
	}

	void DrawCircle(float radius, int sides, float edge) {
		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i < sides; ++i) {
			float a = (pi * 2) * i / sides;
			float x = cos(a) * radius;
			float y = sin(a) * radius;
			glVertex2f(x, y);
		}
		glEnd();

		if (edge) {
			float fillColor[4];
			glGetFloatv(GL_CURRENT_COLOR, fillColor);

			float edgeColor[4] = {
				fillColor[0],
				fillColor[1],
				fillColor[2],
				0.0
			};

			glPushAttrib(GL_CURRENT_BIT);
			glBegin(GL_TRIANGLE_STRIP);
			for (int i = 0; i <= sides; ++i) {
				float a = (pi * 2) * i / sides;
				float x1 = cos(a) * radius;
				float y1 = sin(a) * radius;
				float x2 = cos(a) * (radius + edge);
				float y2 = sin(a) * (radius + edge);

				glColor4fv(fillColor);
				glVertex2f(x1, y1);

				glColor4fv(edgeColor);
				glVertex2f(x2, y2);
			}
			glEnd();
			glPopAttrib();
		}
	}

	void DrawCircleEdge(float radius, float thickness, int sides, float edge) {
		float r1 = radius - thickness / 2;
		float r2 = radius + thickness / 2;
		glBegin(GL_TRIANGLE_STRIP);
		for (int i = 0; i <= sides; ++i) {
			float a = (pi * 2) * i / sides;
			float x1 = cos(a) * r1;
			float y1 = sin(a) * r1;
			float x2 = cos(a) * r2;
			float y2 = sin(a) * r2;

			glVertex2f(x1, y1);
			glVertex2f(x2, y2);
		}
		glEnd();

		if (edge) {
			float fillColor[4];
			glGetFloatv(GL_CURRENT_COLOR, fillColor);

			float edgeColor[4] = {
				fillColor[0],
				fillColor[1],
				fillColor[2],
				0.0f
			};

			glPushAttrib(GL_CURRENT_BIT);
			glBegin(GL_TRIANGLE_STRIP);
			for (int i = 0; i <= sides; ++i) {
				float a = (pi * 2) * i / sides;
				float x1 = cos(a) * r1;
				float y1 = sin(a) * r1;
				float x2 = cos(a) * (r1 - edge);
				float y2 = sin(a) * (r1 - edge);

				glColor4fv(fillColor);
				glVertex2f(x1, y1);

				glColor4fv(edgeColor);
				glVertex2f(x2, y2);
			}
			glEnd();
			glBegin(GL_TRIANGLE_STRIP);
			for (int i = 0; i <= sides; ++i) {
				float a = (pi * 2) * i / sides;
				float x1 = cos(a) * r2;
				float y1 = sin(a) * r2;
				float x2 = cos(a) * (r2 + edge);
				float y2 = sin(a) * (r2 + edge);

				glColor4fv(fillColor);
				glVertex2f(x1, y1);

				glColor4fv(edgeColor);
				glVertex2f(x2, y2);
			}
			glEnd();
			glPopAttrib();
		}
	}

	void DrawRectangle(float width, float height, float edge) {
		float sx = -width / 2;
		float ex = +width / 2;
		float sy = -height / 2;
		float ey = +height / 2;
		glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(sx, sy);
		glVertex2f(sx, ey);
		glVertex2f(ex, sy);
		glVertex2f(ex, ey);
		glEnd();

		if (edge) {
			float fillColor[4];
			glGetFloatv(GL_CURRENT_COLOR, fillColor);

			float edgeColor[4] = {
				fillColor[0],
				fillColor[1],
				fillColor[2],
				0.0f
			};

			float r = edge;

			float ax[] = {sx, sx, ex, ex, sx};
			float ay[] = {sy, ey, ey, sy, sy};

			float bx[] = {
				sx - r,
				sx - r,
				ex + r,
				ex + r,
				sx - r
			};
			float by[] = {
				sy - r,
				ey + r,
				ey + r,
				sy - r,
				sy - r
			};

			glPushAttrib(GL_CURRENT_BIT);
			glBegin(GL_TRIANGLE_STRIP);
			for (int i = 0; i < 5; ++i) {
				glColor4fv(edgeColor);
				glVertex2f(bx[i], by[i]);
				glColor4fv(fillColor);
				glVertex2f(ax[i], ay[i]);
			}
			glEnd();
			glPopAttrib();
		}
	}

	void DrawRectangleEdge(float width, float height, float thickness, float edge) {
		float t = thickness / 2;

		float sx[] = {-width / 2 - t, -width / 2 + t};
		float ex[] = {+width / 2 + t, +width / 2 - t};
		float sy[] = {-height / 2 - t, -height / 2 + t};
		float ey[] = {+height / 2 + t, +height / 2 - t};

		float ax[] = {sx[0], sx[0], ex[0], ex[0], sx[0]};
		float ay[] = {sy[0], ey[0], ey[0], sy[0], sy[0]};

		float bx[] = {sx[1], sx[1], ex[1], ex[1], sx[1]};
		float by[] = {sy[1], ey[1], ey[1], sy[1], sy[1]};

		glBegin(GL_TRIANGLE_STRIP);
		for (int i = 0; i < 5; ++i) {
			glVertex2f(bx[i], by[i]);
			glVertex2f(ax[i], ay[i]);
		}
		glEnd();

		if (edge) {
			float fillColor[4];
			glGetFloatv(GL_CURRENT_COLOR, fillColor);

			float edgeColor[4] = {
				fillColor[0],
				fillColor[1],
				fillColor[2],
				0.0f
			};

			float r = edge;

			float ax[] = {sx[0], sx[0], ex[0], ex[0], sx[0]};
			float ay[] = {sy[0], ey[0], ey[0], sy[0], sy[0]};

			float bx[] = {sx[0] - r, sx[0] - r, ex[0] + r, ex[0] + r, sx[0] - r};
			float by[] = {sy[0] - r, ey[0] + r, ey[0] + r, sy[0] - r, sy[0] - r};

			float cx[] = {sx[1], sx[1], ex[1], ex[1], sx[1]};
			float cy[] = {sy[1], ey[1], ey[1], sy[1], sy[1]};

			float dx[] = {sx[1] + r, sx[1] + r, ex[1] - r, ex[1] - r, sx[1] + r};
			float dy[] = {sy[1] + r, ey[1] - r, ey[1] - r, sy[1] + r, sy[1] + r};

			glPushAttrib(GL_CURRENT_BIT);
			glBegin(GL_TRIANGLE_STRIP);
			for (int i = 0; i < 5; ++i) {
				glColor4fv(edgeColor);
				glVertex2f(bx[i], by[i]);
				glColor4fv(fillColor);
				glVertex2f(ax[i], ay[i]);
			}
			glEnd();
			glBegin(GL_TRIANGLE_STRIP);
			for (int i = 0; i < 5; ++i) {
				glColor4fv(edgeColor);
				glVertex2f(dx[i], dy[i]);
				glColor4fv(fillColor);
				glVertex2f(cx[i], cy[i]);
			}
			glEnd();
			glPopAttrib();
		}
	}

	void DrawLine(Vec2f start, Vec2f end, float thickness, float edge) {
		Vec2f dir = vnormal(end - start);
		Vec2f up = Vec2f(-dir.y, dir.x);

		Vec2f vertex[] = {
			start + up * thickness / 2,
			end + up * thickness / 2,
			start - up * thickness / 2,
			end - up * thickness / 2,
		};

		glBegin(GL_TRIANGLE_STRIP);
		glVertex2fv(&vertex[0]);
		glVertex2fv(&vertex[1]);
		glVertex2fv(&vertex[2]);
		glVertex2fv(&vertex[3]);
		glEnd();

		if (edge) {
			float fillColor[4];
			glGetFloatv(GL_CURRENT_COLOR, fillColor);

			float edgeColor[4] = {
				fillColor[0],
				fillColor[1],
				fillColor[2],
				0.0f
			};

			Vec2f a[] = {
				vertex[0],
				vertex[1],
				vertex[3],
				vertex[2],
				vertex[0]
			};

			Vec2f b[] = {
				vertex[0] + up * edge - dir * edge,
				vertex[1] + up * edge + dir * edge,
				vertex[3] - up * edge + dir * edge,
				vertex[2] - up * edge - dir * edge,
				vertex[0] + up * edge - dir * edge
			};

			glPushAttrib(GL_CURRENT_BIT);
			glBegin(GL_TRIANGLE_STRIP);
			for (int i = 0; i < 5; ++i) {
				glColor4fv(edgeColor);
				glVertex2fv(&b[i]);
				glColor4fv(fillColor);
				glVertex2fv(&a[i]);
			}
			glEnd();
			glPopAttrib();
		}
	}
};
