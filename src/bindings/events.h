#pragma once

#include <main.h>
#include <utils.h>

void On(const std::string &eventName, const py::function &func)
{
    PyFrameObject* frame = PyEval_GetFrame();
    PythonResource* resource = Utils::GetResourceFromFrame(frame);
    resource->AddEvent(eventName, func);
}

void Emit(const std::string &eventName, const py::args &args)
{
    // If trying to emit native event, return
    if (std::find(Utils::EventTypes.begin(), Utils::EventTypes.end(), eventName) != Utils::EventTypes.end())
        return;
    alt::MValueArgs eventArgs;
    for (auto arg : *args)
    {
        eventArgs.Push(Utils::ArgToMValue(arg));
    }
    Core->TriggerLocalEvent(eventName, eventArgs);
}

