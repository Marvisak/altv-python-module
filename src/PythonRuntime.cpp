#include "PythonRuntime.h"
#include "bindings/bindings.h"
#include "main.h"

PythonRuntime *PythonRuntime::instance = nullptr;

PythonRuntime::PythonRuntime()
{
    py::initialize_interpreter(false);

    instance = this;

#pragma region ResourceEvents
    RegisterArgGetter(alt::CEvent::Type::RESOURCE_ERROR, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CResourceErrorEvent *>(ev);
        auto resourceName = event->GetResource()->GetName().ToString();
        return py::make_tuple(resourceName);
    });

    RegisterArgGetter(alt::CEvent::Type::RESOURCE_START, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CResourceStartEvent *>(ev);
        auto resourceName = event->GetResource()->GetName().ToString();
        return py::make_tuple(resourceName);
    });

    RegisterArgGetter(alt::CEvent::Type::RESOURCE_STOP, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CResourceStopEvent *>(ev);
        auto resourceName = event->GetResource()->GetName().ToString();
        return py::make_tuple(resourceName);
    });
#pragma endregion

#pragma region ScriptEvents

    RegisterArgGetter(alt::CEvent::Type::SERVER_SCRIPT_EVENT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CServerScriptEvent *>(ev);
        py::list args;
        for (const auto &arg : event->GetArgs())
        {
            auto value = Utils::MValueToValue(arg);
            args.append(value);
        }
        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::CLIENT_SCRIPT_EVENT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CClientScriptEvent *>(ev);
        py::list args;
        auto player = event->GetTarget();
        args.append(Player(player));
        for (const auto &arg : event->GetArgs())
        {
            auto value = Utils::MValueToValue(arg);
            args.append(value);
        }
        return args;
    });

#pragma endregion

#pragma region EntityEvents

    RegisterArgGetter(alt::CEvent::Type::REMOVE_ENTITY_EVENT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CRemoveEntityEvent *>(ev);
        Entity entity{event->GetEntity()};

        return py::make_tuple(entity);
    });

#pragma endregion

#pragma region BaseObjectEvent

    RegisterArgGetter(alt::CEvent::Type::CREATE_BASE_OBJECT_EVENT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CCreateBaseObjectEvent *>(ev);
        BaseObject object{event->GetObject()};

        return py::make_tuple(object);
    });

    RegisterArgGetter(alt::CEvent::Type::REMOVE_BASE_OBJECT_EVENT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CRemoveBaseObjectEvent *>(ev);
        BaseObject object{event->GetObject()};

        return py::make_tuple(object);
    });

#pragma endregion

#pragma region PlayerEvents

    RegisterArgGetter(alt::CEvent::Type::PLAYER_CONNECT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CPlayerConnectEvent *>(ev);
        Player player{event->GetTarget()};
        return py::make_tuple(player);
    });

    RegisterArgGetter(alt::CEvent::Type::PLAYER_DISCONNECT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CPlayerDisconnectEvent *>(ev);
        Player player{event->GetTarget()};
        alt::String reason{event->GetReason().ToString()};

        py::list args;

        args.append(player);
        args.append(reason);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::PLAYER_DAMAGE, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CPlayerDamageEvent *>(ev);
        Player player{event->GetTarget()};
        Entity attacker{event->GetAttacker()};
        uint32_t weapon{event->GetWeapon()};
        uint16_t healthDamage{event->GetHealthDamage()};
        uint16_t armourDamage{event->GetArmourDamage()};

        py::list args;

        args.append(player);
        args.append(attacker);
        args.append(weapon);
        args.append(healthDamage);
        args.append(armourDamage);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::PLAYER_DEATH, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CPlayerDeathEvent *>(ev);
        Player player{event->GetTarget()};
        Entity killer{event->GetKiller()};
        uint32_t weapon{event->GetWeapon()};

        py::list args;

        args.append(player);
        args.append(killer);
        args.append(weapon);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::PLAYER_WEAPON_CHANGE, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CPlayerWeaponChangeEvent *>(ev);
        Player target{event->GetTarget()};
        uint32_t oldWeapon{event->GetOldWeapon()};
        uint32_t newWeapon{event->GetNewWeapon()};

        py::list args;

        args.append(target);
        args.append(oldWeapon);
        args.append(newWeapon);

        return args;
    });

#pragma endregion

#pragma region VehicleEvents

    RegisterArgGetter(alt::CEvent::Type::PLAYER_ENTER_VEHICLE, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CPlayerEnterVehicleEvent *>(ev);

        Vehicle vehicle{event->GetTarget()};
        Player player{event->GetPlayer()};
        uint8_t seat{event->GetSeat()};

        py::list args;

        args.append(player);
        args.append(vehicle);
        args.append(seat);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::PLAYER_ENTERING_VEHICLE, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CPlayerEnteringVehicleEvent *>(ev);

        Vehicle vehicle{event->GetTarget()};
        Player player{event->GetPlayer()};
        uint8_t seat{event->GetSeat()};

        py::list args;

        args.append(player);
        args.append(vehicle);
        args.append(seat);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::PLAYER_CHANGE_VEHICLE_SEAT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CPlayerChangeVehicleSeatEvent *>(ev);

        Vehicle vehicle{event->GetTarget()};
        Player player{event->GetPlayer()};
        uint8_t oldSeat{event->GetOldSeat()};
        uint8_t newSeat{event->GetNewSeat()};

        py::list args;

        args.append(player);
        args.append(vehicle);
        args.append(oldSeat);
        args.append(newSeat);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::PLAYER_LEAVE_VEHICLE, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CPlayerLeaveVehicleEvent *>(ev);

        Vehicle vehicle{event->GetTarget()};
        Player player{event->GetPlayer()};
        uint8_t seat{event->GetSeat()};

        py::list args;

        args.append(player);
        args.append(vehicle);
        args.append(seat);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::VEHICLE_ATTACH, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CVehicleAttachEvent *>(ev);
        Vehicle vehicle{event->GetTarget()};
        Vehicle attached{event->GetAttached()};

        py::list args;

        args.append(vehicle);
        args.append(attached);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::VEHICLE_DAMAGE, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CVehicleDamageEvent *>(ev);
        Vehicle vehicle{event->GetTarget()};
        Entity damager{event->GetDamager()};

        uint32_t bodyHealthDamage{event->GetBodyHealthDamage()};
        uint32_t bodyAdditionalHealthDamage{event->GetBodyAdditionalHealthDamage()};
        uint32_t engineHealthDamage{event->GetEngineHealthDamage()};
        uint32_t petrolTankHealthDamage{event->GetPetrolTankHealthDamage()};
        uint32_t damagedWith{event->GetDamagedWith()};

        py::list args;

        args.append(vehicle);
        args.append(damager);

        args.append(bodyHealthDamage);
        args.append(bodyAdditionalHealthDamage);
        args.append(engineHealthDamage);
        args.append(petrolTankHealthDamage);
        args.append(damagedWith);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::VEHICLE_DESTROY, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CVehicleDestroyEvent *>(ev);
        Vehicle vehicle{event->GetTarget()};
        return py::make_tuple(vehicle);
    });

    RegisterArgGetter(alt::CEvent::Type::VEHICLE_DETACH, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CVehicleDetachEvent *>(ev);
        Vehicle vehicle{event->GetTarget()};
        Vehicle detached{event->GetDetached()};

        py::list args;

        args.append(vehicle);
        args.append(detached);

        return args;
    });

#pragma endregion

#pragma region ColshapeEvents

    RegisterArgGetter(alt::CEvent::Type::COLSHAPE_EVENT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CColShapeEvent *>(ev);

        Colshape colshape{event->GetTarget()};
        Entity entity{event->GetEntity()};

        py::list args;

        args.append(colshape);
        args.append(entity);

        // TODO - Remove when the event system is updated to support more than one name
        args.append(event->GetState());

        return args;
    });

#pragma endregion

#pragma region WorldEvents

    RegisterArgGetter(alt::CEvent::Type::EXPLOSION_EVENT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CExplosionEvent *>(ev);
        Player source{event->GetSource()};
        alt::CExplosionEvent::ExplosionType explosionType{event->GetExplosionType()};
        alt::Position position{event->GetPosition()};
        uint32_t explosionFX{event->GetExplosionFX()};
        Entity target{event->GetTarget()};

        py::list args;

        args.append(source);
        args.append(target);
        args.append(explosionType);
        args.append(position);
        args.append(explosionFX);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::FIRE_EVENT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CFireEvent *>(ev);
        Player source{event->GetSource()};
        alt::Array<alt::CFireEvent::FireInfo> fireInfo{event->GetFires()};

        py::list args;

        args.append(source);
        args.append(fireInfo);

        return args;
    });

    RegisterArgGetter(alt::CEvent::Type::START_PROJECTILE_EVENT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CStartProjectileEvent *>(ev);
        Player source{event->GetSource()};
        alt::Position startPosition{event->GetStartPosition()};
        alt::Vector3f direction{event->GetDirection()};
        uint32_t ammoHash{event->GetAmmoHash()};
        uint32_t weaponHash{event->GetWeaponHash()};

        py::list args;

        args.append(source);
        args.append(startPosition);
        args.append(direction);
        args.append(ammoHash);
        args.append(weaponHash);

        return args;
    });

#pragma endregion

#pragma region OtherEvents

    RegisterArgGetter(alt::CEvent::Type::CONSOLE_COMMAND_EVENT, [](const alt::CEvent *ev) {
        auto event = dynamic_cast<const alt::CConsoleCommandEvent *>(ev);
        auto args = event->GetArgs();
        auto name = event->GetName();
        py::list pyArgs;
        pyArgs.append(name.ToString());
        for (auto arg : args)
        {
            pyArgs.append(arg.ToString());
        }
    );

    RegisterArgGetter(
        alt::CEvent::Type::WEAPON_DAMAGE_EVENT,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CWeaponDamageEvent*>(ev);
            Player player{event->GetSource()};
            Entity target{event->GetTarget()};
            uint32_t weaponHash{event->GetWeaponHash()};
            uint16_t damageValue{event->GetDamageValue()};
            alt::Vector3f shotOffset{ event->GetShotOffset() };
            alt::CWeaponDamageEvent::BodyPart bodyPart{event->GetBodyPart()};

            py::list args;

            args.append(player);
            args.append(target);
            args.append(weaponHash);
            args.append(damageValue);
            args.append(shotOffset);
            args.append(bodyPart);

            return args;
        }
    );

     #pragma endregion
}

PythonResource *PythonRuntime::GetPythonResourceFromPath(std::string const &path)
{
    for (PythonResource *resource : resources)
    {
        if (path.find(resource->resource->GetPath().ToString() + preferred_separator) != std::string::npos)
        {
            return resource;
        }
    }
    return nullptr;
}

alt::IResource::Impl *PythonRuntime::CreateImpl(alt::IResource *impl)
{
    auto *resource = new PythonResource(this, impl);
    resources.push_back(resource);
    return resource;
}

void PythonRuntime::DestroyImpl(alt::IResource::Impl *impl)
{
    auto *resource = dynamic_cast<PythonResource *>(impl);
    for (unsigned int i{}; i < resources.size(); i++)
    {
        if (resources[i]->resource->GetName() == resource->resource->GetName())
        {
            resources.erase(resources.begin() + i);
            break;
        }
    }
    delete resource;
}

void PythonRuntime::OnDispose()
{
    py::finalize_interpreter();
}

std::string PythonRuntime::GetEventType(alt::CEvent::Type ev)
{
    return Utils::EventTypes.at(static_cast<int>(ev));
}
