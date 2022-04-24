#pragma once
#include "main.hpp"

class Interval {
 private:
	double milliseconds;
	py::function function;
	long nextTime;
	bool running = true;
 public:
	Interval(double milliseconds, py::function function);

	py::function GetFunc() {
		return function;
	}

	void SetRunning(bool start) {
		running = start;
	}

	bool IsRunning() const {
		return running;
	}

	void SetMilliseconds(double newMilliseconds) {
		milliseconds = newMilliseconds;
	}

	bool Update();

	static long GetTime() {
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
	}
};