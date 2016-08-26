#include "Keyboard.h"

#include <Windows.h>

namespace wnd {
	Keyboard::Keyboard() {
		for (int i = 0; i < KEYS; ++i) {
			key[i] = KEY_UP;
		}
	}

	void Keyboard::Update(bool active) {
		for (int i = 0; i < KEYS; ++i) {
			if (active && GetAsyncKeyState(i)) {
				switch (key[i]) {
					case 0: key[i] = KEY_PRESSED; break;
					case 1: key[i] = KEY_DOWN; break;
					case 2: key[i] = KEY_DOWN; break;
					case 3: key[i] = KEY_PRESSED; break;
				}
			} else {
				switch (key[i]) {
					case 0: key[i] = KEY_UP; break;
					case 1: key[i] = KEY_RELEASED; break;
					case 2: key[i] = KEY_RELEASED; break;
					case 3: key[i] = KEY_UP; break;
				}
			}
		}
	}

	KeyState Keyboard::GetKey(int code) {
		return(key[code]);
	}
};
