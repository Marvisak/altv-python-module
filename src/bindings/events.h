#pragma once

#include <main.h>
#include <utils.h>

void On(const std::string &eventName, const pybind11::function &listener)
{
    PyFrameObject* frame = PyEval_GetFrame();
    PythonResource* resource = GetResourceFromFrame(frame);
    resource->AddEvent(eventName, listener);
}

