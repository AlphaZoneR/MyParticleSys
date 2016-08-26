#pragma once

#include "Timer.h"
#include "Cursor.h"
#include "Keyboard.h"
#include "Content.h"
#include "Settings.h"
#include "Exception.h"

#include "OpenGL.h"

#define WM_INIT		WM_USER + 0x0001
#define WM_RENDER	WM_USER + 0x0002

#include <Windows.h>

#include <AL/al.h>
#include <AL/alc.h>

#include <string>

using std::string;

namespace wnd {
	class Window {
		ALCdevice * device;
		ALCcontext * context;

		HINSTANCE hinst;
		HANDLE thread;

		HWND hwnd;
		HDC hdc;

		HGLRC hglrc;
		int format;

		int x, y;
		int width;
		int height;

		bool active;
		bool relative;
		bool moving;
		bool visible;

		Timer * timer;
		Cursor * cursor;
		Keyboard * keyboard;

		Content * content;
		Settings * settings;

		Window();

		void Init();
		void Render();
		void RenderLoop();

		static void RenderThread();
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	public:
		static Window * Instance();

		int GetWidth();
		int GetHeight();
		float GetAspect();
		float GetTime();
		float GetTick();

		Settings * GetSettings();
		KeyState GetKey(int key);

		int GetCursorX();
		int GetCursorY();
		void SetCursorVisible(bool visible);
		void SetCursorRelative(bool relative);

		void SetMultiSample(int sample);
		void Set(Settings * settings);

		void SwitchFullScreen();
		void BuildWindow(Content * content, int multiSample);

		void CloseWindow();
		void MainLoop();
	};
};
