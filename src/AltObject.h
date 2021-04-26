#pragma once
#include <main.h>
#include <Methods/methods.h>

PYBIND11_EMBEDDED_MODULE(alt, m)
{
    m.doc() = "AltV Python Module";
    m.def("log", &log_info);
    m.def("log_error", &log_error);
    m.def("log_debug", &log_debug);
    m.def("log_warning", &log_warning);
    m.def("log_colored", &log_colored);
}