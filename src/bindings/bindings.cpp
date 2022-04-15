#include "alt.hpp"
#include "classes/classes.hpp"
#include "events.hpp"
#include "log.hpp"
#include "main.hpp"


PYBIND11_EMBEDDED_MODULE(alt, m){
	m.doc() = "alt:V Python Module";

    RegisterEnums(m);
    RegisterVehicleNeonStruct(m);
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
