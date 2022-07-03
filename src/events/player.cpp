#include "events.hpp"
#include "utils.hpp"

EventHandler playerConnect(alt::CEvent::Type::PLAYER_CONNECT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerConnectEvent*>(ev);
	args.append(event->GetTarget().Get());
});

EventHandler playerBeforeConnect(alt::CEvent::Type::PLAYER_BEFORE_CONNECT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerBeforeConnectEvent*>(ev);
	args.append(event->GetConnectionInfo().Get());
});

EventHandler playerDisconnect(alt::CEvent::Type::PLAYER_DISCONNECT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerDisconnectEvent*>(ev);
	args.append(event->GetTarget().Get());
	args.append(event->GetReason());
});

EventHandler connectionQueueAdd(alt::CEvent::Type::CONNECTION_QUEUE_ADD, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CConnectionQueueAddEvent*>(ev);
	args.append(event->GetConnectionInfo().Get());
});

EventHandler connectionQueueRemove(alt::CEvent::Type::CONNECTION_QUEUE_REMOVE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CConnectionQueueRemoveEvent*>(ev);
	args.append(event->GetConnectionInfo().Get());
});

EventHandler playerDamage(alt::CEvent::Type::PLAYER_DAMAGE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerDamageEvent*>(ev);
	args.append(event->GetTarget().Get());
	args.append(Utils::GetBaseObject(event->GetAttacker()));
	args.append(event->GetHealthDamage());
	args.append(event->GetArmourDamage());
	args.append(event->GetWeapon());
});

EventHandler playerDeath(alt::CEvent::Type::PLAYER_DEATH, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerDeathEvent*>(ev);
	args.append(event->GetTarget().Get());
	args.append(Utils::GetBaseObject(event->GetKiller()));
	args.append(event->GetWeapon());
});

EventHandler playerEnterVehicle(alt::CEvent::Type::PLAYER_ENTER_VEHICLE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerEnterVehicleEvent*>(ev);
	args.append(event->GetPlayer().Get());
	args.append(event->GetTarget().Get());
	args.append(event->GetSeat());
});

EventHandler playerEnteringVehicle(alt::CEvent::Type::PLAYER_ENTERING_VEHICLE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerEnteringVehicleEvent*>(ev);
	args.append(event->GetPlayer().Get());
	args.append(event->GetTarget().Get());
	args.append(event->GetSeat());
});

EventHandler playerLeftVehicle(alt::CEvent::Type::PLAYER_LEAVE_VEHICLE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerLeaveVehicleEvent*>(ev);
	args.append(event->GetPlayer().Get());
	args.append(event->GetTarget().Get());
	args.append(event->GetSeat());
});

EventHandler playerChangeVehicleSeat(alt::CEvent::Type::PLAYER_CHANGE_VEHICLE_SEAT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerChangeVehicleSeatEvent*>(ev);
	args.append(event->GetPlayer().Get());
	args.append(event->GetTarget().Get());
	args.append(event->GetOldSeat());
	args.append(event->GetNewSeat());
});

EventHandler playerWeaponChange(alt::CEvent::Type::PLAYER_WEAPON_CHANGE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerWeaponChangeEvent*>(ev);
	args.append(event->GetTarget().Get());
	args.append(event->GetOldWeapon());
	args.append(event->GetNewWeapon());
});

EventHandler playerRequestControl(alt::CEvent::Type::PLAYER_REQUEST_CONTROL, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerRequestControlEvent*>(ev);
	args.append(event->GetPlayer().Get());
	args.append(Utils::GetBaseObject(event->GetTarget().Get()));
});

EventHandler playerAnimationChange(alt::CEvent::Type::PLAYER_CHANGE_ANIMATION_EVENT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerChangeAnimationEvent*>(ev);
	args.append(event->GetTarget().Get());
	args.append(event->GetOldAnimationDict());
	args.append(event->GetNewAnimationDict());
	args.append(event->GetOldAnimationName());
	args.append(event->GetNewAnimationName());
});


EventHandler playerInteriorChange(alt::CEvent::Type::PLAYER_CHANGE_INTERIOR_EVENT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CPlayerChangeInteriorEvent*>(ev);
	args.append(event->GetTarget().Get());
	args.append(event->GetNewInteriorLocation());
	args.append(event->GetOldInteriorLocation());
});
