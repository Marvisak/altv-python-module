#include "main.h"
#include "PythonRuntime.h"
#include "bindings/bindings.h"

PythonRuntime* PythonRuntime::instance = nullptr;


PythonRuntime::PythonRuntime()
{
    py::initialize_interpreter(false);

    instance = this;

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

    RegisterArgGetter(
            alt::CEvent::Type::SERVER_SCRIPT_EVENT,
            [](const alt::CEvent* ev)
            {
                auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
                py::list args;
                for (const auto &arg : event->GetArgs())
                {
                    auto value = Utils::MValueToValue(arg);
                    args.append(value);
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
                auto player = event->GetTarget();
                args.append(Player(player));
                for (const auto &arg : event->GetArgs())
                {
                    auto value = Utils::MValueToValue(arg);
                    args.append(value);
                }
                return args;
            }
    );

    RegisterArgGetter(
            alt::CEvent::Type::PLAYER_CONNECT,
            [](const alt::CEvent* ev)
            {
                auto event = dynamic_cast<const alt::CPlayerConnectEvent*>(ev);
                Player player {event->GetTarget()};
                return py::make_tuple(player);
            }
    );

    RegisterArgGetter(
        alt::CEvent::Type::PLAYER_ENTER_VEHICLE,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CPlayerEnterVehicleEvent*>(ev);
            
            Vehicle vehicle {event->GetTarget()};
            Player player {event->GetPlayer()};
            uint8_t seat {event->GetSeat()};
        
            py::list args;

            args.append(player);
            args.append(vehicle);
            args.append(seat);

            return args;
        }
    );

    RegisterArgGetter(
        alt::CEvent::Type::PLAYER_LEAVE_VEHICLE,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CPlayerLeaveVehicleEvent*>(ev);
            
            Vehicle vehicle {event->GetTarget()};
            Player player {event->GetPlayer()};
            uint8_t seat {event->GetSeat()};
        
            py::list args;

            args.append(player);
            args.append(vehicle);
            args.append(seat);

            return args;
        }
    );

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



