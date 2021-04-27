#include <main.h>
#include <PythonRuntime.h>
#include <AltObject.h>

PythonRuntime* PythonRuntime::instance = nullptr;

PythonRuntime::PythonRuntime()
{
    pybind11::initialize_interpreter(false);
    instance = this;
}

alt::IResource::Impl* PythonRuntime::CreateImpl(alt::IResource* impl) {
    auto* resource = new PythonResource(this, impl);
    resources.insert(resource);
    return resource;
}

void PythonRuntime::DestroyImpl(alt::IResource::Impl *impl) {
    auto* resource = dynamic_cast<PythonResource*>(impl);
    delete resource;
}

void PythonRuntime::OnDispose()
{
    pybind11::finalize_interpreter();
}

