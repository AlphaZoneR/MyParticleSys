#include "Settings.h"

namespace wnd {
	Settings::Settings() {
		fullscreen = false;
		centered = true;

		title = "";

		minWidth = 0;
		minHeight = 0;

		maxWidth = 0x7FFF;
		maxHeight = 0x7FFF;

		width = 0;
		height = 0;

		x = 0;
		y = 0;
	}

	bool Settings::GetFullScreen() {
		return(fullscreen);
	}

	int Settings::GetMinWidth() {
		return(!fullscreen ? minWidth : 0);
	}

	int Settings::GetMinHeight() {
		return(!fullscreen ? minHeight : 0);
	}

	int Settings::GetMaxWidth() {
		return(!fullscreen ? maxWidth : 0x7FFF);
	}

	int Settings::GetMaxHeight() {
		return(!fullscreen ? maxHeight : 0x7FFF);
	}

	void Settings::SetTitle(string title) {
		this->title = title;
	}

	void Settings::SetMinSize(int width, int height) {
		this->minHeight = height;
		this->minWidth = width;
	}

	void Settings::SetMaxSize(int width, int height) {
		this->maxHeight = height;
		this->maxWidth = width;
	}

	void Settings::SetSize(int width, int height) {
		this->height = height;
		this->width = width;
	}

	void Settings::SetPosition(int x, int y) {
		this->centered = false;
		this->x = x;
		this->y = y;
	}

	void Settings::SetPositionCenter() {
		this->centered = true;
	}

	void Settings::SetFullScreen(bool fullscreen) {
		this->fullscreen = fullscreen;
	}

	void Settings::Set(HWND hwnd) {
		int sx = x;
		int sy = y;
		int ex = width;
		int ey = height;

		unsigned style = WS_OVERLAPPEDWINDOW;

		if (fullscreen) {
			sx = 0;
			sy = 0;
			ex = GetSystemMetrics(SM_CXSCREEN);
			ey = GetSystemMetrics(SM_CYSCREEN);
			style = WS_POPUPWINDOW;
		}

		RECT rect = {
			0,			// left
			0,			// top
			ex,			// right
			ey			// bottom
		};

		AdjustWindowRect(&rect, style, 0);
		int cx = rect.right - rect.left;
		int cy = rect.bottom - rect.top;

		if (centered) {
			sx = (GetSystemMetrics(SM_CXSCREEN) - cx) / 2;
			sy = (GetSystemMetrics(SM_CYSCREEN) - cy) / 2;
		}

		SetWindowText(hwnd, title.c_str());
		SetWindowLong(hwnd, GWL_STYLE, style);
		SetWindowPos(hwnd, HWND_TOP, sx, sy, cx, cy, SWP_SHOWWINDOW | SWP_DRAWFRAME);
	}
};
