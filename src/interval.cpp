#include "interval.hpp"

Interval::Interval(double milliseconds, py::function function) : milliseconds(milliseconds), function(std::move(function)) {
	nextTime = alt::ICore::Instance().GetNetTime() + (long)milliseconds;
}

void Interval::TimeWarning(long time, const std::string& resourceName) {
	auto inspect = py::module_::import("inspect");
	auto path = inspect.attr("getfile")(function).cast<std::string>();
	std::string str = std::string("Interval at ").append(resourceName).append(":").append(path.substr(path.find_last_of("/\\") + 1)).append(" at function ").append(function.attr("__name__").cast<std::string>()).append(" was too long ").append(std::to_string(alt::ICore::Instance().GetNetTime() - time)).append("ms");
	alt::ICore::Instance().LogWarning(str);
}

bool Interval::Update(long time) {
	if (time >= nextTime && running) {
		try {
			function();
		} catch (py::error_already_set& e) {
			py::print(e.what());
			e.restore();
		}
		nextTime = time + (long)milliseconds;
		return true;
	}
	return false;
}
