#pragma once

#include "alt.h"
#include "classes/classes.h"
#include "events.h"
#include "log.h"
#include "main.h"

PYBIND11_EMBEDDED_MODULE(alt, m){
	m.doc() = "alt:V Python Module";

    RegisterEnums(m);
    RegisterVector3Class(m);
    RegisterRGBAClass(m);
    RegisterHeadOverlayClass(m);
    RegisterHeadBlendData(m);
    RegisterWeaponClass(m);
    RegisterClothClass(m);
    RegisterDlcClothClass(m);
    RegisterPropClass(m);
    RegisterDlcPropClass(m);

    RegisterBaseObjectClass(m);
    RegisterWorldObjectClass(m);
    RegisterEntityClass(m);
    RegisterVehicleClass(m);
    RegisterPlayerClass(m);

    RegisterLogFunctions(m);
    RegisterEventFunctions(m);
    RegisterHelpersFunctions(m);
}
