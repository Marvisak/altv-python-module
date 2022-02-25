#pragma once

#include "PythonRuntime.h"
#include "main.h"

namespace Utils
{
	PythonResource* GetResourceFromFrame(PyFrameObject* frame);
	alt::MValue ValueToMValue(const py::object& arg);
	py::object MValueToValue(const alt::MValueConst& mValue);
	std::string GetTypeOfObject(const py::object& object);
	py::list ArrayToPyList(const alt::Array<uint32_t>& list);
}
