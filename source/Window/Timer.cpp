#include "Timer.h"

#include <Windows.h>

namespace wnd {
	long long Timer::PerformanceCounter() {
		long long counter;
		QueryPerformanceCounter((LARGE_INTEGER *)&counter);
		return(counter);
	}

	long long Timer::PerformanceFrequency() {
		long long frequency;
		QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
		return(frequency);
	}

	Timer::Timer() {
		frequency =	PerformanceFrequency();
		start = PerformanceCounter();
		last = start;
		end = start;
	}

	void Timer::Update() {
		last = end;
		end = PerformanceCounter();
	}

	double Timer::GetTime() {
		return((double)(end - start) / frequency);
	}

	double Timer::GetTick() {
		return((double)(end - last) / frequency);
	}
};

