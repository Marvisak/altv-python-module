#pragma once

#include "alt.h"
#include "classes/classes.h"
#include "classes/enums/enum.h"
#include "events.h"
#include "log.h"
#include "main.h"

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
    RegisterVector2Class(m);
    RegisterVector3Class(m);
    RegisterRGBAClass(m);
    RegisterVoiceChannelClass(m);

    // Clothing / Props
    RegisterClothesClass(m);
    RegisterDlcClothesClass(m);
    RegisterPropClass(m);
    RegisterDlcPropClass(m);

    // Colshapes
    RegisterColshapeClass(m);
    RegisterColshapeCircleClass(m);
    RegisterColshapeCuboidClass(m);
    RegisterColshapeCylinderClass(m);
    RegisterColshapeRectangleClass(m);
    RegisterColshapeSphereClass(m);
}
