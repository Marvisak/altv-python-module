#include <main.h>
#include <PythonRuntime.h>
#include <bindings/bindings.h>
#include <utils.h>

PythonRuntime* PythonRuntime::instance = nullptr;

PythonRuntime::PythonRuntime()
{
    py::initialize_interpreter(false);
    instance = this;


    RegisterArgGetter(
            alt::CEvent::Type::SERVER_SCRIPT_EVENT,
            [](const alt::CEvent* ev)
            {
                auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
                py::list args;
                for (const auto &arg : event->GetArgs())
                {
                    Utils::PushMValue(args, arg);
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



