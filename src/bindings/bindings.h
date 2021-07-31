#pragma once

#include "main.h"
#include "log.h"
#include "events.h"
#include "classes/classes.h"
#include "alt.h"
#include "classes/enum.h"


PYBIND11_EMBEDDED_MODULE(alt, m)
{
    m.doc() = "AltV Python Module";
    RegisterLogFunctions(m);
    RegisterEventFunctions(m);
    RegisterHelpersFunctions(m);
    RegisterEnums(m);

    RegisterBaseObjectClass(m);
    RegisterWorldObjectClass(m);
    RegisterEntityClass(m);
    RegisterVehicleClass(m);
    RegisterPlayerClass(m);
    RegisterVector3Class(m);
    RegisterRGBAClass(m);
    RegisterVoiceChannelClass(m);
    RegisterClothesClass(m);
    RegisterDlcClothesClass(m);
    RegisterPropClass(m);
    RegisterDlcPropClass(m);
}