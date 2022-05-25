#pragma once
#include "main.hpp"

class Interval {
 private:
	double milliseconds;
	py::function function;
	uint32_t nextTime;
	bool running = true;
	PyThreadState* interpreter;
 public:
	Interval(double milliseconds, py::function function, PyThreadState* interpreter);

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

	void TimeWarning(uint32_t time, const std::string& resourceName);

	bool Update(uint32_t time);
};