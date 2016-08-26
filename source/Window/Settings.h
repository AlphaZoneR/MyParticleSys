#pragma once

#include <Windows.h>
#include <string>

namespace wnd {
	using std::string;

	class Settings {
		string title;

		bool fullscreen;
		bool centered;

		int x, y;
		int width;
		int height;
		int minWidth;
		int minHeight;
		int maxWidth;
		int maxHeight;

	public:
		Settings();

		void SetMinSize(int width, int height);
		void SetMaxSize(int width, int height);
		void SetSize(int width, int height);

		void SetFullScreen(bool fullscreen);
		void SetPositionCenter();
		void SetPosition(int x, int y);

		void SetTitle(string title);

		bool GetFullScreen();

		int GetMinWidth();
		int GetMinHeight();
		int GetMaxWidth();
		int GetMaxHeight();

		void Set(HWND hwnd);
	};
};
