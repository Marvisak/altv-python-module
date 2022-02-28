#pragma once

#include "main.h"
#include "utils.h"

void On(const std::string& eventName, const py::function& func)
{
	PyFrameObject* frame = PyEval_GetFrame();
	PythonResource* resource = Utils::GetResourceFromFrame(frame);
	resource->AddLocalEvent(eventName, func);
}

void OnClient(const std::string& eventName, const py::function& func)
{
	PyFrameObject* frame = PyEval_GetFrame();
	PythonResource* resource = Utils::GetResourceFromFrame(frame);
	resource->AddRemoteEvent(eventName, func);
}

void Emit(const std::string& eventName, const py::args& args)
{
	alt::MValueArgs eventArgs;
	for (const py::handle& arg : *args)
	{
		eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
	}
	alt::ICore::Instance().TriggerLocalEvent(eventName, eventArgs);
}

void EmitClient(alt::IPlayer* player, const std::string& eventName, const py::args& args)
{
	alt::MValueArgs eventArgs;
	for (const py::handle& arg : *args)
	{
		eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
	}
    alt::ICore::Instance().TriggerClientEvent(player, eventName, eventArgs);
}


void RegisterEventFunctions(py::module_ m)
{
	m.def("on", &On, "Listens to event");
	m.def("onClient", &OnClient, "Listens to client event");
	m.def("emit", &Emit, "Emits event");
	m.def("emitClient", &EmitClient, "Emits client event");
}
