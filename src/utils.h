#pragma once

#include "PythonRuntime.h"
#include "main.h"

namespace Utils
{
    PythonResource* GetResourceFromFrame(PyFrameObject* frame);
    alt::MValue ValueToMValue(const py::object& arg);
    py::object MValueToValue(const alt::MValueConst& mValue);
    std::string GetTypeOfObject(const py::object& object);
    py::list ArrayToPyList(const alt::Array<uint32_t>& list);

    const std::vector<std::string> EventTypes{
            "NONE",

            "playerConnect",
            "playerDisconnect",

            "anyResourceStart",
            "anyResourceStop",
            "anyResourceError",

            "SERVER_SCRIPT_EVENT",
            "CLIENT_SCRIPT_EVENT",

            "metaChange",
            "syncedMetaChange",
            "streamSyncedMetaChange",
            "globalMetaChange",
            "globalSyncedMetaChange",

            "playerDamage",
            "playerDeath",
            "startFire",
            "explosion",
            "startProjectile",
            "weaponDamage",

            "checkpoint",
            "colshape",
            "playerEnterVehicle",
            "playerEnteringVehicle",
            "playerLeaveVehicle",
            "playerChangeVehicleSeat",
            "playerWeaponChange",

            "vehicleAttach",
            "vehicleDestroy",
            "vehicleDamage",
            "vehicleDetach",

            "netOwnerChange",

            "removeEntity",
            "createBaseObject",
            "removeBaseObject",

            "dataNodeReceived",

            "consoleCommand",
    };
}


