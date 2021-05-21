#pragma once

#include <main.h>
#include <bindings/log.h>
#include <bindings/events.h>
#include <classes/classes.h>

PYBIND11_EMBEDDED_MODULE(alt, m)
{
    m.doc() = "AltV Python Module";
    RegisterLogFunctions(m);
    RegisterEventFunctions(m);

    Player::RegisterPlayerClass(m);
    Vector3::RegisterVector3Class(m);
}