#pragma once

#include <main.h>
#include <utils.h>

void On(const std::string &eventName, const py::function &func)
{
    PyFrameObject* frame = PyEval_GetFrame();
    PythonResource* resource = GetResourceFromFrame(frame);
    resource->AddEvent(eventName, func);
}

void Emit(const std::string &eventName, const py::args &args)
{
    alt::MValueArgs eventArgs;
    for (auto arg : args)
    {
        eventArgs.Push(ArgToMValue(arg));
    }
    alt::ICore::Instance().TriggerLocalEvent(eventName, eventArgs);
}

