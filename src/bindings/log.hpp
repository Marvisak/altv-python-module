#pragma once

#include "main.hpp"

void Log(const py::args& args, const std::string& separator = " ") {
	std::string str;
	for (const py::handle& arg : args) {
		if (!str.empty())
			str += separator;
		str += py::str(arg).cast<std::string>();
	}
	alt::ICore::Instance().LogColored(str);
}

void LogError(const py::args& args, const std::string& separator = " ") {
	std::string str;
	for (const py::handle& arg : args) {
		if (!str.empty())
			str += separator;
		str += py::str(arg).cast<std::string>();
	}
	alt::ICore::Instance().LogError(str);
}

void LogWarning(const py::args& args, const std::string& separator = " ") {
	std::string str;
	for (const py::handle& arg : args) {
		if (!str.empty())
			str += separator;
		str += py::str(arg).cast<std::string>();
	}
	alt::ICore::Instance().LogWarning(str);
}

void RegisterLogFunctions(py::module_ m) {
	m.def("log", &Log, py::arg("sep") = " ", "Logs text to the console");
	m.def("log_error", &LogError, py::arg("sep") = " ", "Logs error to the console");
	m.def("log_warning", &LogWarning, py::arg("sep") = " ", "Logs warning to the console");
}
