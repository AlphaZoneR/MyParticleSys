#pragma once

namespace wnd {
	class Timer {
		long long frequency;
		long long start;
		long long last;
		long long end;

		long long PerformanceCounter();
		long long PerformanceFrequency();

	public:
		Timer();
		void Update();
		double GetTime();
		double GetTick();
	};
};
