#pragma once

#include <main.h>
#include <utils.h>

void On()
{
    PyFrameObject* frame = PyEval_GetFrame();
    PythonResource* resource = GetResourceFromFrame(frame);
}

