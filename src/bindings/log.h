#pragma once

#include <main.h>

void Log(const std::string &eventName)
{
    Core->LogColored(eventName);
}

void LogError(const std::string &eventName)
{
    Core->LogError(eventName);
}

void LogDebug(const std::string &eventName)
{
    Core->LogDebug(eventName);
}

void LogWarning(const std::string &eventName)
{
    Core->LogWarning(eventName);
}

void RegisterLogFunctions(py::module_ m)
{
    m.def("log", &Log, "Logs text to the console");
    m.def("logError", &LogError, "Logs error to the console");
    m.def("logDebug", &LogDebug, "Logs debug message to the console");
    m.def("logWarning", &LogWarning, "Logs warning to the console");
}
