#pragma once
#include <main.h>
#include <bindings/bindings.h>

PYBIND11_EMBEDDED_MODULE(alt, m)
{
    m.doc() = "AltV Python Module";
    m.def("log", &Log);
    m.def("logError", &LogError);
    m.def("logDebug", &LogDebug);
    m.def("logWarning", &LogWarning);
    m.def("logColored", &LogColored);
    m.def("on", &On);
}