#pragma once

namespace wnd {
	const int KEYS = 256;

	enum KeyState {
		KEY_UP,
		KEY_PRESSED,
		KEY_DOWN,
		KEY_RELEASED,
	};

	class Keyboard {
		KeyState key[KEYS];

	public:
		Keyboard();
		void Update(bool active);
		KeyState GetKey(int code);
	};
};
