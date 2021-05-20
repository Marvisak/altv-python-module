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
            .def("spawn", &Player::Spawn)
            .def_property("health", &Player::GetHealth, &Player::SetHealth);
    py::class_<Vector3>(m, "vector3")
            .def(py::init([](float x, float y, float z) {return new Vector3(x, y, z);}))
            .def_readwrite("x", &Vector3::x)
            .def_readwrite("y", &Vector3::y)
            .def_readwrite("z", &Vector3::z)
            .def("toDict", &Vector3::toDict)
            .def("toList", &Vector3::toList);
}