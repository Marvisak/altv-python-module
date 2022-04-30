#include "interval.hpp"

Interval::Interval(double milliseconds, py::function function) : milliseconds(milliseconds), function(std::move(function)) {
	nextTime = alt::ICore::Instance().GetNetTime() + (long)milliseconds;
}

void Interval::TimeWarning(long time, const std::string& resourceName) {
	auto inspect = py::module_::import("inspect");
	auto path = inspect.attr("getfile")(function).cast<std::string>();
	std::stringstream ss = std::stringstream() << "Interval at " << resourceName << ":" << path.substr(path.find_last_of("/\\") + 1) << " at function " << function.attr("__name__").cast<std::string>() << " was too long " << alt::ICore::Instance().GetNetTime() - time << "ms";
	alt::ICore::Instance().LogWarning(ss.str());
}

bool Interval::Update(long time) {
	if (time >= nextTime && running) {
		try {
			function();
		} catch (const py::error_already_set& e) {
			py::print(e.what());
		}
		nextTime = time + (long)milliseconds;
		return true;
	}
	return false;
}
