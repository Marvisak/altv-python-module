#include <main.h>
#include <PythonRuntime.h>
#include <AltObject.h>

PythonRuntime* PythonRuntime::instance = nullptr;

PythonRuntime::PythonRuntime()
{
    pybind11::initialize_interpreter(false);
    instance = this;
}

PythonResource* PythonRuntime::GetPythonResourceFromPath(std::string const &path)
{
    for (PythonResource* resource : resources)
    {
        if (resource->GetFullPath() == path) {
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
    pybind11::finalize_interpreter();
}

std::string PythonRuntime::GetEventType(const alt::CEvent* ev)
{
//    return EventTypes.at(static_cast<int>(ev->GetType()));
    return "anyResourceError";
}

std::string PythonRuntime::GetEventType(alt::CEvent::Type ev)
{
    //return EventTypes.at(static_cast<int>(ev));
    return "anyResourceError";
}

