#include "Window.h"
#include "Resource.h"

#include <cstdio>

namespace wnd {
	const char * ClassName = "GLWindow";

	Window::Window() {
		thread = 0;

		hwnd = 0;
		hdc = 0;

		hglrc = 0;
		format = 0;

		x = 0;
		y = 0;
		width = 0;
		height = 0;

		active = false;
		relative = false;
		moving = false;
		visible = true;

		timer = new Timer();
		cursor = new Cursor();
		keyboard = new Keyboard();

		hinst = GetModuleHandle(0);
		if (!hinst) {
            throw(WindowException("GetModuleHandle failed!", GetLastError()));
		}

		device = alcOpenDevice(0);
		if (!device) {
            throw(WindowException("alcOpenDevice failed!", alGetError()));
		}

		context = alcCreateContext(device, 0);
		if (!context) {
            throw(WindowException("alcCreateContext failed!", alGetError()));
		}

		if(!alcMakeContextCurrent(context)) {
            throw(WindowException("alcMakeContextCurrent failed!", alGetError()));
		}

		LPCSTR largeIcon = MAKEINTRESOURCE(RC_LARGE_ICON);
		LPCSTR smallIcon = MAKEINTRESOURCE(RC_SMALL_ICON);

		WNDCLASSEX wndClass = {
			sizeof(WNDCLASSEX),				// cbSize
			CS_OWNDC,						// style
			WindowProc,						// lpfnWndProc
			0,								// cbClsExtra
			0,								// cbWndExtra
			hinst,							// hInstance
			LoadIcon(hinst, largeIcon),		// hIcon
			LoadCursor(0, IDC_ARROW),		// hCursor
			0,								// hbrBackground
			0,								// lpszMenuName
			ClassName,						// lpszClassName
			LoadIcon(hinst, smallIcon),		// hIconSm
		};

		if (!RegisterClassEx(&wndClass)) {
            throw(WindowException("RegisterClassEx failed!", GetLastError()));
		}
	}

	void Window::RenderLoop() {
		SendMessage(hwnd, WM_INIT, 0, 0);
		while (true) {
			SendMessage(hwnd, WM_RENDER, 0, 0);
		}
	}

	void Window::RenderThread() {
		Window * window = Window::Instance();
		window->RenderLoop();
	}

	LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		Window * window = Window::Instance();
		switch (uMsg) {
			case WM_GETMINMAXINFO:
				if (window->settings) {
					MINMAXINFO * info = (MINMAXINFO *)lParam;

					unsigned style = GetWindowLong(hwnd, GWL_STYLE);
					Settings * settings = window->GetSettings();

					RECT minRect = {
						0,							// left
						0,							// top
						settings->GetMinWidth(),	// right
						settings->GetMinHeight()	// bottom
					};

					RECT maxRect = {
						0,							// left
						0,							// top
						settings->GetMaxWidth(),	// right
						settings->GetMaxHeight()	// bottom
					};

					AdjustWindowRect(&minRect, style, 0);
					AdjustWindowRect(&maxRect, style, 0);

					info->ptMinTrackSize.x = minRect.right - minRect.left;
					info->ptMinTrackSize.y = minRect.bottom - minRect.top;
					info->ptMaxTrackSize.x = maxRect.right - maxRect.left;
					info->ptMaxTrackSize.y = maxRect.bottom - maxRect.top;
				}
				break;

			case WM_ACTIVATE:
				window->active = (bool)wParam;
				break;

			case WM_ENTERSIZEMOVE:
				window->moving = true;
				break;

			case WM_EXITSIZEMOVE:
				window->moving = false;
				break;

			case WM_MOVE:
				window->x = (short)LOWORD(lParam);
				window->y = (short)HIWORD(lParam);
				break;

			case WM_SIZE:
				window->width = (short)LOWORD(lParam);
				window->height = (short)HIWORD(lParam);
				break;

			case WM_INIT:
				window->Init();
				break;

			case WM_RENDER:
				window->Render();
				break;

			case WM_CLOSE:
				PostQuitMessage(0);
				break;
		}
		return(DefWindowProc(hwnd, uMsg, wParam, lParam));
	}

	void Window::Init() {
		if (!wglMakeCurrent(hdc, hglrc)) {
            throw(WindowException("wglMakeCurrent failed!", GetLastError()));
		}
		LoadExtensionsCurrentContext();
		content->Init();
	}

	void Window::Render() {
		keyboard->Update(active);
		cursor->Update(!active || (!relative && visible));

		if (active && relative && !moving) {
			int cx = x + width / 2;
			int cy = y + height / 2;
			cursor->Lock(cx, cy);
		}

		timer->Update();
		content->Update();
		content->Render();

		SwapBuffers(hdc);
	}

	int Window::GetWidth() {
		return(width);
	}

	int Window::GetHeight() {
		return(height);
	}

	float Window::GetAspect() {
		return((float)width / height);
	}

	float Window::GetTime() {
		return((float)timer->GetTime());
	}

	float Window::GetTick() {
		return((float)timer->GetTick());
	}

	Settings * Window::GetSettings() {
		return(settings);
	}

	KeyState Window::GetKey(int key) {
		return(keyboard->GetKey(key));
	}

	int Window::GetCursorX() {
		int cx = cursor->GetX();
		if (relative) {
			cx -= x + width / 2;
		} else {
			cx = cx - x;
		}
		return(cx);
	}

	int Window::GetCursorY() {
		int cy = cursor->GetY();
		if (relative) {
			cy = y + height / 2 - cy;
		} else {
			cy = y + height - cy - 1;
		}
		return(cy);
	}

	void Window::SetCursorVisible(bool visible) {
		this->visible = visible;
	}

	void Window::SetCursorRelative(bool relative) {
		this->relative = relative;
		if (relative) {
			int cx = x + width / 2;
			int cy = y + height / 2;
			cursor->Lock(cx, cy);
		}
	}

	void Window::Set(Settings * settings) {
		this->settings = settings;
		settings->Set(hwnd);
	}

	void Window::SwitchFullScreen() {
		bool fullscreen = settings->GetFullScreen();
		settings->SetFullScreen(!fullscreen);
		settings->Set(hwnd);
	}

	void Window::BuildWindow(Content * content, int multiSample) {
		this->content = content;

		if (thread && hwnd && hdc && hglrc) {
			TerminateThread(thread, 0);
			wglMakeCurrent(0, 0);
			wglDeleteContext(hglrc);
			ReleaseDC(hwnd, hdc);
			DestroyWindow(hwnd);
		}

		format = 0;
		thread = 0;
		hglrc = 0;
		hwnd = 0;
		hdc = 0;

		hwnd = CreateWindow(
			ClassName,				// lpClassName
			0,						// lpWindowName
			0,						// dwStyle
			0,						// x
			0,						// y
			0,						// nWidth
			0,						// nHeight
			0,						// hWndParent
			0,						// hMenu
			hinst,					// hInstance
			0						// lpParam
		);

		if (!hwnd) {
            throw(WindowException("CreateWindow failed!", GetLastError()));
		}

		hdc = GetDC(hwnd);

		if (!hdc) {
            throw(WindowException("GetDC failed!", GetLastError()));
		}

		LoadExtensions();

		if (Supported(wglChoosePixelFormatARB)) {
			while (multiSample) {
				float fAttributes[] = {0, 0};
				int iAttributes[] = {
					WGL_DRAW_TO_WINDOW_ARB, 1,
					WGL_SUPPORT_OPENGL_ARB, 1,
					WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
					WGL_COLOR_BITS_ARB, 24,
					WGL_ALPHA_BITS_ARB, 8,
					WGL_DEPTH_BITS_ARB, 16,
					WGL_STENCIL_BITS_ARB, 1,
					WGL_DOUBLE_BUFFER_ARB, 1,
					WGL_SAMPLE_BUFFERS_ARB, 1,
					WGL_SAMPLES_ARB, multiSample,
					0, 0
				};

				unsigned numFormats = 0;

				wglChoosePixelFormatARB(
					hdc,				// hdc
					iAttributes,		// iAttributes
					fAttributes,		// fAttributes
					1,					// one
					&format,			// format
					&numFormats			// formats
				);

				if (format) {
					break;
				}

				multiSample /= 2;
			}
		}

		PIXELFORMATDESCRIPTOR pfd = {
			sizeof(PIXELFORMATDESCRIPTOR),	// nSize
			1,								// nVersion
			PFD_DRAW_TO_WINDOW |
			PFD_SUPPORT_OPENGL |
			PFD_GENERIC_ACCELERATED |
			PFD_DOUBLEBUFFER,				// dwFlags
			0,								// iPixelType
			32,								// cColorBits
			0,								// cRedBits
			0,								// cRedShift
			0,								// cGreenBits
			0,								// cGreenShift
			0,								// cBlueBits
			0,								// cBlueShift
			0,								// cAlphaBits
			0,								// cAlphaShift
			32,								// cAccumBits
			0,								// cAccumRedBits
			0,								// cAccumGreenBits
			0,								// cAccumBlueBits
			0,								// cAccumAlphaBits
			32,								// cDepthBits
			32,								// cStencilBits
			0,								// cAuxBuffers
			0,								// iLayerType
			0,								// bReserved
			0,								// dwLayerMask
			0,								// dwVisibleMask
			0								// dwDamageMask
		};

		if (!format) {
			format = ChoosePixelFormat(hdc, &pfd);
		}

		if (!SetPixelFormat(hdc, format, &pfd)) {
            throw(WindowException("SetPixelFormat failed!", GetLastError()));
		}

		hglrc = wglCreateContext(hdc);

		if (!hglrc) {
            throw(WindowException("wglCreateContext failed!", GetLastError()));
		}

		thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)RenderThread, 0, 0, 0);
		if (!thread) {
            throw(WindowException("CreateThread failed!", GetLastError()));
		}
	}

	void Window::CloseWindow() {
		PostQuitMessage(0);
	}

	void Window::MainLoop() {
		MSG message;
		while (GetMessage(&message, 0, 0, 0)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	Window * Window::Instance() {
		static Window * instance = new Window();
		return(instance);
	}
};
