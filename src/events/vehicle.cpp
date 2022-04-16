#include "events.hpp"
#include "utils.hpp"

EventHandler vehicleDestroy(alt::CEvent::Type::VEHICLE_DESTROY, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CVehicleDestroyEvent*>(ev);
	args.append(event->GetTarget().Get());
});

EventHandler vehicleDamage(alt::CEvent::Type::VEHICLE_DAMAGE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CVehicleDamageEvent*>(ev);
	args.append(event->GetTarget().Get());
	args.append(Utils::GetBaseObject(event->GetDamager()));
	args.append(event->GetBodyHealthDamage());
	args.append(event->GetBodyAdditionalHealthDamage());
	args.append(event->GetEngineHealthDamage());
	args.append(event->GetPetrolTankHealthDamage());
	args.append(event->GetDamagedWith());
});

EventHandler vehicleAttach(alt::CEvent::Type::VEHICLE_ATTACH, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CVehicleAttachEvent*>(ev);
	args.append(event->GetTarget().Get());
	args.append(event->GetAttached().Get());
});

EventHandler vehicleDetach(alt::CEvent::Type::VEHICLE_DETACH, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CVehicleDetachEvent*>(ev);
	args.append(event->GetTarget().Get());
	args.append(event->GetDetached().Get());
});
