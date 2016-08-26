#include "Cursor.h"

#include <Windows.h>

namespace wnd {
	Cursor::Cursor() {
		visible = true;
		Update(true);
	}

	void Cursor::Lock(int x, int y) {
		SetCursorPos(x, y);
	}

	void Cursor::Update(bool visible) {
		if (this->visible != visible) {
			this->visible = visible;
			ShowCursor(visible);
		}
		POINT cursor;
		GetCursorPos(&cursor);
		x = cursor.x;
		y = cursor.y;
	}

	int Cursor::GetX() {
		return(x);
	}

	int Cursor::GetY() {
		return(y);
	}
};

