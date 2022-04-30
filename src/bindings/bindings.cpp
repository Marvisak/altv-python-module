#include "alt.hpp"
#include "classes/classes.hpp"
#include "events.hpp"
#include "intervals.hpp"
#include "log.hpp"
#include "main.hpp"

PYBIND11_EMBEDDED_MODULE(alt, m){
	m.doc() = "alt:V Python Module";

    RegisterEnums(m);
    RegisterVector2Class(m);
    RegisterVector3Class(m);
    RegisterRGBAClass(m);
	RegisterConnectionInfoClass(m);
	RegisterVehicleModelInfoClass(m);
	RegisterResourceClass(m);

    RegisterBaseObjectClass(m);
    RegisterWorldObjectClass(m);
    RegisterEntityClass(m);
    RegisterVehicleClass(m);
    RegisterPlayerClass(m);
    RegisterColShapeClass(m);
    RegisterBlipClass(m);
    RegisterCheckpointClass(m);
    RegisterVoiceChannelClass(m);

    RegisterLogFunctions(m);
    RegisterEventFunctions(m);
    RegisterHelpersFunctions(m);
	RegisterIntervalFunction(m);
}
