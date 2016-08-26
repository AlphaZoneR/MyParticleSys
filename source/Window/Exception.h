#pragma once

namespace wnd {
	class WindowException {
	public:
		const char * msg;
		int code;

	public:
		WindowException(const char * m, const int c);
	};
};
