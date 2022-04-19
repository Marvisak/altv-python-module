#include "classes/types/vector3.hpp"
#include "classes/types/enums.hpp"
#include "events.hpp"
#include "utils.hpp"


EventHandler resourceStart(alt::CEvent::Type::RESOURCE_START, [](const alt::CEvent* ev, py::list& args) {
    auto event = dynamic_cast<const alt::CResourceStartEvent*>(ev);
    args.append(event->GetResource()->GetName());
});

EventHandler resourceStop(alt::CEvent::Type::RESOURCE_STOP, [](const alt::CEvent* ev, py::list& args) {
    auto event = dynamic_cast<const alt::CResourceStopEvent*>(ev);
    args.append(event->GetResource()->GetName());
});

EventHandler resourceError(alt::CEvent::Type::RESOURCE_ERROR, [](const alt::CEvent* ev, py::list& args) {
    auto event = dynamic_cast<const alt::CResourceErrorEvent*>(ev);
    args.append(event->GetResource()->GetName());
});

EventHandler fire(alt::CEvent::Type::FIRE_EVENT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CFireEvent*>(ev);
	args.append(event->GetSource().Get());
	py::list fireInfos;
	for (alt::CFireEvent::FireInfo fireInfo : event->GetFires()) {
		py::dict fireInfoDict;
		fireInfoDict["pos"] = Vector3(fireInfo.position);
		fireInfoDict["weapon"] = fireInfo.weaponHash;
		fireInfos.append(fireInfoDict);
	}
	args.append(fireInfos);
});

EventHandler explosion(alt::CEvent::Type::EXPLOSION_EVENT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CExplosionEvent*>(ev);
	args.append(event->GetSource().Get());
	args.append(static_cast<ExplosionType>(event->GetExplosionType()));
	args.append(Vector3(event->GetPosition()));
	args.append(event->GetExplosionFX());
	args.append(Utils::GetBaseObject(event->GetTarget()));
});

EventHandler startProjectile(alt::CEvent::Type::START_PROJECTILE_EVENT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CStartProjectileEvent*>(ev);
	args.append(event->GetSource().Get());
	args.append(Vector3(event->GetStartPosition()));
	args.append(Vector3(event->GetDirection()));
	args.append(event->GetAmmoHash());
	args.append(event->GetWeaponHash());
});

EventHandler weaponDamage(alt::CEvent::Type::WEAPON_DAMAGE_EVENT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CWeaponDamageEvent*>(ev);
	args.append(event->GetSource().Get());
	args.append(Utils::GetBaseObject(event->GetTarget()));
	args.append(event->GetWeaponHash());
	args.append(event->GetDamageValue());
	args.append(Vector3(event->GetShotOffset()));
	args.append(static_cast<BodyPart>(event->GetBodyPart()));
});

EventHandler netOwnerChange(alt::CEvent::Type::NETOWNER_CHANGE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CNetOwnerChangeEvent*>(ev);
	args.append(Utils::GetBaseObject(event->GetTarget()));
	args.append(event->GetNewOwner().Get());
	args.append(event->GetOldOwner().Get());
});

EventHandler removeEntity(alt::CEvent::Type::REMOVE_ENTITY_EVENT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CRemoveEntityEvent*>(ev);
	args.append(Utils::GetBaseObject(event->GetEntity()));
});

EventHandler consoleCommand(alt::CEvent::Type::CONSOLE_COMMAND_EVENT, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CConsoleCommandEvent*>(ev);
	args.append(event->GetName());
	py::list commandArgs;
	for (const auto& arg : event->GetArgs())
		commandArgs.append(arg);
	args.append(commandArgs);
});

EventHandler serverStarted(alt::CEvent::Type::SERVER_STARTED);