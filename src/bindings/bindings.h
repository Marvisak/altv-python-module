#pragma once

#include <main.h>
#include <bindings/log.h>
#include <bindings/events.h>
#include <classes/classes.h>
#include <bindings/alt.h>
#include <classes/enum.h>


PYBIND11_EMBEDDED_MODULE(alt, m)
{
    m.doc() = "AltV Python Module";
    RegisterLogFunctions(m);
    RegisterEventFunctions(m);
    RegisterHelpersFunctions(m);
    RegisterEnums(m);

    BaseObject::RegisterBaseObjectClass(m);
    Entity::RegisterEntityClass(m);
    Player::RegisterPlayerClass(m);
    Vector3::RegisterVector3Class(m);
    RGBA::RegisterRGBAClass(m);
}