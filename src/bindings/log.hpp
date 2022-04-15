#pragma once

#include "main.hpp"

void Log(const py::object& object)
{
    alt::ICore::Instance().LogColored(py::str(object).cast<std::string>());
}

void LogError(const py::object& object)
{
    alt::ICore::Instance().LogError(py::str(object).cast<std::string>());
}

void LogWarning(const py::object& object)
{
    alt::ICore::Instance().LogWarning(py::str(object).cast<std::string>());
}

void RegisterLogFunctions(py::module_ m)
{
	m.def("log", &Log, "Logs text to the console");
	m.def("log_error", &LogError, "Logs error to the console");
	m.def("log_warning", &LogWarning, "Logs warning to the console");
}
