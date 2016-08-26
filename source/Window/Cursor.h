#pragma once

namespace wnd {
	class Cursor {
		int x, y;
		bool visible;

	public:
		Cursor();
		void Lock(int x, int y);
		void Update(bool visible);
		int GetX();
		int GetY();
	};
};
