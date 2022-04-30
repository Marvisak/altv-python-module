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

	void TimeWarning(long time, const std::string& resourceName);

	bool Update(long time);
};