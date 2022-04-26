#include "interval.hpp"

Interval::Interval(double milliseconds, py::function function) : milliseconds(milliseconds), function(std::move(function)) {
	nextTime = alt::ICore::Instance().GetNetTime() + (long)milliseconds;
}

bool Interval::Update() {
	if (alt::ICore::Instance().GetNetTime() >= nextTime && running) {
		function();
		nextTime = alt::ICore::Instance().GetNetTime() + (long)milliseconds;
		return true;
	}
	return false;
}
