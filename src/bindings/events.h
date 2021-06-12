#pragma once

#include <main.h>
#include <utils.h>
#include <classes/base/player.h>

void On(const std::string& eventName, const py::function& func)
{
    PyFrameObject* frame = PyEval_GetFrame();
    PythonResource* resource = Utils::GetResourceFromFrame(frame);
    resource->AddEvent(eventName, func);
}

void OnClient(const std::string& eventName, const py::function& func)
{
    PyFrameObject* frame = PyEval_GetFrame();
    PythonResource* resource = Utils::GetResourceFromFrame(frame);
    resource->AddClientEvent(eventName, func);
}

void Emit(const std::string &eventName, const py::args& args)
{
    // If trying to emit native event, return
    if (std::find(Utils::EventTypes.begin(), Utils::EventTypes.end(), eventName) != Utils::EventTypes.end())
        return;
    alt::MValueArgs eventArgs;
    for (const py::handle& arg : *args)
    {
        eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
    }
    Core->TriggerLocalEvent(eventName, eventArgs);
}

void EmitClient(const Player& player, const std::string& eventName, const py::args& args)
{
    // If trying to emit native event, return
    if (std::find(Utils::EventTypes.begin(), Utils::EventTypes.end(), eventName) != Utils::EventTypes.end())
        return;
    alt::MValueArgs eventArgs;
    for (const py::handle& arg : *args)
    {
        eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
    }
    Core->TriggerClientEvent(player.GetBaseObject(), eventName, eventArgs);
}

void RegisterEventFunctions(py::module_ m)
{
    m.def("on", &On, "Listens to event");
    m.def("onClient", &OnClient, "Listens to client event");
    m.def("emit", &Emit, "Emits event");
    m.def("emitClient", &EmitClient, "Emits client event");
}

