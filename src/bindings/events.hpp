#pragma once

#include "main.hpp"
#include "utils.hpp"

void On(const std::string& eventName, const py::function& func) {
	PyThreadState* interp = PyThreadState_Get();
	PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
	resource->AddLocalCustomEvent(eventName, func);
}

void OnClient(const std::string& eventName, const py::function& func) {
	PyThreadState* interp = PyThreadState_Get();
	PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
	resource->AddRemoteEvent(eventName, func);
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
	m.def("on", &On, "Listens to event");
	m.def("on_client", &OnClient, "Listens to client event");
	m.def("emit", &Emit, "Emits event");
	m.def("emit_client", &EmitClient, "Emits client event");
}
