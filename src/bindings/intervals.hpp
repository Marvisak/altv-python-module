#pragma once

#include "main.hpp"

void CreateAttrsForTaskFunction(PythonResource* resource, const py::function& func) {
	Interval* task = resource->GetInterval(func);
	func.attr("stop") = py::cpp_function([task, func] {
		task->SetRunning(false);
	});

	func.attr("start") = py::cpp_function([task, func] {
		task->SetRunning(true);
	});

	func.attr("is_running") = py::cpp_function([task, func] {
		return task->IsRunning();
	});

	func.attr("change_interval") = py::cpp_function([task, func](double milliseconds=0, double seconds=0, double minutes=0, double hours=0) {
		if (seconds > 0) milliseconds += seconds * 1000;
		if (minutes > 0) milliseconds += minutes * 60 * 1000;
		if (hours > 0) milliseconds += hours * 60 * 60 * 1000;
		task->SetMilliseconds(milliseconds);
	}, py::arg("milliseconds") = 0, py::arg("seconds") = 0, py::arg("minutes") = 0, py::arg("hours") = 0);
}

py::cpp_function Task(double milliseconds=0, double seconds=0, double minutes=0, double hours=0) {
	if (seconds > 0) milliseconds += seconds * 1000;
	if (minutes > 0) milliseconds += minutes * 60 * 1000;
	if (hours > 0) milliseconds += hours * 60 * 60 * 1000;
	return [milliseconds](const py::function& func) {
		PyThreadState* interp = PyThreadState_Get();
		PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
		resource->AddTask(milliseconds, func);
		CreateAttrsForTaskFunction(resource, func);
		return func;
	};
}

void RegisterIntervalFunction(py::module_ m) {
	m.def("task", &Task, py::kw_only(), py::arg("milliseconds") = 0, py::arg("seconds") = 0, py::arg("minutes") = 0, py::arg("hours") = 0);
}