#pragma once

#include <main.h>
#include <bindings/log.h>
#include <bindings/events.h>
#include <classes/classes.h>

PYBIND11_EMBEDDED_MODULE(alt, m)
{
    m.doc() = "AltV Python Module";
    m.def("log", &Log, "Logs text to the console");
    m.def("logError", &LogError, "Logs error to the console");
    m.def("logDebug", &LogDebug, "Logs debug message to the console");
    m.def("logWarning", &LogWarning, "Logs warning to the console");
    m.def("on", &On, "Listens to event");
    m.def("emit", &Emit, "Emits event");

    py::class_<Player>(m, "player")
            .def_property("health", &Player::get_health, &Player::set_health);

}