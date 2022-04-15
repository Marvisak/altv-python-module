#pragma once

#include "main.hpp"
#include "utils.hpp"
#include "classes/types/enums.hpp"

py::cpp_function Event(Event event) {
	return [event](const py::function& func) {
		PyThreadState* interp = PyThreadState_Get();
		PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
		auto castEvent = static_cast<alt::CEvent::Type>(event);
		resource->AddLocalEvent(castEvent, func);
	};
}

py::cpp_function CustomEvent(const std::string& eventName) {
	return [eventName](const py::function& func) {
		PyThreadState* interp = PyThreadState_Get();
		PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
		resource->AddLocalCustomEvent(eventName, func);
	};
}

py::cpp_function ClientEvent(const std::string& eventName) {
	return [eventName](const py::function& func) {
		PyThreadState* interp = PyThreadState_Get();
		PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
		resource->AddRemoteEvent(eventName, func);
	};
}

void Emit(const std::string& eventName, const py::args& args) {
	alt::MValueArgs eventArgs;
	for (const py::handle& arg : *args) {
		eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
	}
	alt::ICore::Instance().TriggerLocalEvent(eventName, eventArgs);
}

void EmitClient(alt::IPlayer* player, const std::string& eventName, const py::args& args) {
	alt::MValueArgs eventArgs;
	for (const py::handle& arg : *args) {
		eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
	}
    alt::ICore::Instance().TriggerClientEvent(player, eventName, eventArgs);
}


void RegisterEventFunctions(py::module_ m) {
	m.def("event", &Event, py::arg("event"), "Decorator for registering event listener");
	m.def("custom_event", &CustomEvent, py::arg("event"), "Decorator for registering custom event listener");
	m.def("client_event", &ClientEvent, py::arg("event"), "Decorator for registering client event listener");
	m.def("emit", &Emit, "Emits event");
	m.def("emit_client", &EmitClient, "Emits client event");
}
