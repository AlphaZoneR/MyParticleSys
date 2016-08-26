#include "Exception.h"

namespace wnd {
	WindowException::WindowException(const char * m, const int c) {
		code = c;
		msg = m;
	}
};
