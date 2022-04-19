#pragma once

#include "PythonRuntime.hpp"
#include "main.hpp"

namespace Utils
{
	alt::MValue ValueToMValue(const py::object& arg);
	py::object MValueToValue(const alt::MValueConst& mValue);
    py::object GetBaseObject(const alt::Ref<alt::IBaseObject>& baseObject);
    template <class T>
    py::list ArrayToPyList(const alt::Array<T>& array) {
        py::list pyList;
        for (auto element : array) {
            pyList.append(element);
        }
        return pyList;
    }
}
