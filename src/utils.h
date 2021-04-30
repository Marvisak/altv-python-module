#pragma once

#include <main.h>
#include <PythonRuntime.h>

PythonResource* GetResourceFromFrame(PyFrameObject* frame)
{
    PyObject *filename = frame->f_code->co_filename;
    PyObject* byteStr = PyUnicode_AsEncodedString(filename, "utf-8", "~E~");
    std::string fullPath = PyBytes_AS_STRING(byteStr);
    PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromPath(fullPath);
    return resource;
}
