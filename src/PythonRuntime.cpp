#include "main.h"
#include "PythonRuntime.h"
#include "bindings/bindings.h"

PythonRuntime* PythonRuntime::instance = nullptr;


PythonRuntime::PythonRuntime()
{
    py::initialize_interpreter(false);

    instance = this;

    #pragma region ResourceEvents
    RegisterArgGetter(
            alt::CEvent::Type::RESOURCE_ERROR,
            [](const alt::CEvent* ev)
            {
                auto event = dynamic_cast<const alt::CResourceErrorEvent*>(ev);
                auto resourceName = event->GetResource()->GetName().ToString();
                return py::make_tuple(resourceName);
            }
    );

    RegisterArgGetter(
            alt::CEvent::Type::RESOURCE_START,
            [](const alt::CEvent* ev)
            {
                auto event = dynamic_cast<const alt::CResourceStartEvent*>(ev);
                auto resourceName = event->GetResource()->GetName().ToString();
                return py::make_tuple(resourceName);
            }
    );

    RegisterArgGetter(
            alt::CEvent::Type::RESOURCE_STOP,
            [](const alt::CEvent* ev)
            {
                auto event = dynamic_cast<const alt::CResourceStopEvent*>(ev);
                auto resourceName = event->GetResource()->GetName().ToString();
                return py::make_tuple(resourceName);
            }
    );
#pragma endregion

    #pragma region ScriptEvents

    RegisterArgGetter(
        alt::CEvent::Type::SERVER_SCRIPT_EVENT,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);

            py::list args;

            alt::MValueArgs serverArgs = event->GetArgs();
            uint64_t size = serverArgs.GetSize();
            if (size == 0) {
                args.append(event->GetName().CStr());
                args.append(nullptr);
                args.append(0);
            }
            else {
#ifdef _WIN32
                auto constArgs = new alt::MValueConst * [size];
#endif
                for (uint64_t i = 0; i < size; i++) {
                    constArgs[i] = &serverArgs[i];
                }
                args.append(event->GetName().CStr());
                args.append(constArgs);
                args.append(size);
#ifdef _WIN32
                delete[] constArgs;
#endif
            }
            return args;
        }
    );

    RegisterArgGetter(
        alt::CEvent::Type::CLIENT_SCRIPT_EVENT,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CClientScriptEvent*>(ev);

            py::list args;

            alt::MValueArgs clientArgs = event->GetArgs();
            uint64_t size = clientArgs.GetSize();
            if (size == 0) {
                args.append(event->GetName().CStr());
                args.append(nullptr);
                args.append(0);
            }
            else {
#ifdef _WIN32
                auto constArgs = new alt::MValueConst * [size];
#endif
                for (uint64_t i = 0; i < size; i++) {
                    constArgs[i] = &clientArgs[i];
                }
                args.append(event->GetName().CStr());
                args.append(constArgs);
                args.append(size);
#ifdef _WIN32
                delete[] constArgs;
#endif
            }
            return args;
        }
    );

    #pragma endregion

    #pragma region PlayerEvents

    RegisterArgGetter(
        alt::CEvent::Type::PLAYER_CONNECT,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CPlayerConnectEvent*>(ev);
            Player player{ event->GetTarget() };
            return py::make_tuple(player);
        }
    );

    RegisterArgGetter(
        alt::CEvent::Type::PLAYER_DISCONNECT,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CPlayerDisconnectEvent*>(ev);
            Player player{ event->GetTarget() };
            alt::StringView reason{ event->GetReason() };
            py::list args;

            args.append(player);
            args.append(reason);

            return args;
        }
    );

    RegisterArgGetter(
        alt::CEvent::Type::PLAYER_DAMAGE,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CPlayerDamageEvent*>(ev);
            Player player{ event->GetTarget() };
            Entity attacker{ event->GetAttacker() };
            alt::IBaseObject::Type attackerType { attacker.GetType() };
            uint16_t attackerId {attacker.GetID()};
            uint32_t weapon{ event->GetWeapon() };
            int16_t healthDamage{ event->GetHealthDamage() };
            int16_t armourDamage{ event->GetArmourDamage() };

            py::list args;

            args.append(player);
            args.append(attacker);
            args.append(attackerType);
            args.append(attackerId);
            args.append(weapon);
            args.append(healthDamage);
            args.append(armourDamage);

            return args;
        }
    );

    #pragma endregion

    #pragma region VehicleEvents

    RegisterArgGetter(
        alt::CEvent::Type::PLAYER_ENTER_VEHICLE,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CPlayerEnterVehicleEvent*>(ev);

            Vehicle vehicle{ event->GetTarget() };
            Player player{ event->GetPlayer() };
            uint8_t seat{ event->GetSeat() };

            py::list args;

            args.append(player);
            args.append(vehicle);
            args.append(seat);

            return args;
        }
    );

    RegisterArgGetter(
        alt::CEvent::Type::PLAYER_ENTERING_VEHICLE,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CPlayerEnteringVehicleEvent*>(ev);

            Vehicle vehicle{ event->GetTarget() };
            Player player{ event->GetPlayer() };
            uint8_t seat{ event->GetSeat() };

            py::list args;

            args.append(player);
            args.append(vehicle);
            args.append(seat);

            return args;
        }
    );

    RegisterArgGetter(
        alt::CEvent::Type::PLAYER_CHANGE_VEHICLE_SEAT,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CPlayerChangeVehicleSeatEvent*>(ev);

            Vehicle vehicle{ event->GetTarget() };
            Player player{ event->GetPlayer() };
            uint8_t oldSeat{ event->GetOldSeat() };
            uint8_t newSeat{ event->GetNewSeat() };

            py::list args;

            args.append(player);
            args.append(vehicle);
            args.append(oldSeat);
            args.append(newSeat);

            return args;
        }
    );

    RegisterArgGetter(
        alt::CEvent::Type::PLAYER_LEAVE_VEHICLE,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CPlayerLeaveVehicleEvent*>(ev);

            Vehicle vehicle{ event->GetTarget() };
            Player player{ event->GetPlayer() };
            uint8_t seat{ event->GetSeat() };

            py::list args;

            args.append(player);
            args.append(vehicle);
            args.append(seat);

            return args;
        }
    );
    #pragma endregion

    #pragma region ColshapeEvents

    RegisterArgGetter(
        alt::CEvent::Type::COLSHAPE_EVENT,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CColShapeEvent*>(ev);

            Colshape colshape{ event->GetTarget() };
            Entity entity{ event->GetEntity() };

            py::list args;

            args.append(colshape);
            args.append(entity);

            // TODO - Remove when the event system is updated to support more than one name
            args.append(event->GetState());

            return args;
        }
    );

    #pragma endregion

    #pragma region OtherEvents

    RegisterArgGetter(
        alt::CEvent::Type::CONSOLE_COMMAND_EVENT,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CConsoleCommandEvent*>(ev);
            auto args = event->GetArgs();
            auto name = event->GetName();
            py::list pyArgs;
            pyArgs.append(name.ToString());
            for (auto arg : args)
            {
                pyArgs.append(arg.ToString());
            }
            return pyArgs;
        }
    );

    #pragma endregion

}

PythonResource* PythonRuntime::GetPythonResourceFromPath(std::string const &path)
{
    for (PythonResource* resource : resources)
    {
        if (path.find(resource->resource->GetPath().ToString() + preferred_separator) != std::string::npos) {
            return resource;
        }
    }
    return nullptr;
}

alt::IResource::Impl* PythonRuntime::CreateImpl(alt::IResource* impl) {
    auto* resource = new PythonResource(this, impl);
    resources.push_back(resource);
    return resource;
}

void PythonRuntime::DestroyImpl(alt::IResource::Impl *impl) {
    auto* resource = dynamic_cast<PythonResource*>(impl);
    for (unsigned int i{}; i<resources.size(); i++)
    {
        if (resources[i]->resource->GetName() == resource->resource->GetName())
        {
            resources.erase( resources.begin() + i );
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



