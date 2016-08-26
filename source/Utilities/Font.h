#pragma once

namespace util {
	class Font {
		static const int base = 32;
		static const int count = 95;
		unsigned texture[count];
		float place[count];
		int list;

	public:
		Font(const char * name, int size);
		~Font();
		void Render(float x, float y, float scale, float align, const char * format, ...);
	};
};
