#include "interval.hpp"

Interval::Interval(double milliseconds, py::function function) : milliseconds(milliseconds), function(std::move(function)) {
	nextTime = GetTime() + (long)milliseconds;
}

void Interval::Update() {
	if (GetTime() >= nextTime && running) {
		function();
		nextTime = GetTime() + (long)milliseconds;
	}
}
