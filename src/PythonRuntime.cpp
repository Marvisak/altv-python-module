#include "PythonRuntime.hpp"
#include "bindings/bindings.hpp"

PythonRuntime* PythonRuntime::Instance = nullptr;

PythonRuntime::PythonRuntime() {
	py::initialize_interpreter(false);
	Instance = this;
}

PythonResource* PythonRuntime::GetPythonResourceFromPath(std::string const& path) {
	for (PythonResource* resource : Resources)
	{
		if (path.find(resource->Resource->GetPath().ToString() + preferred_separator) != std::string::npos)
		{
			return resource;
		}
	}
	return nullptr;
}

alt::IResource::Impl* PythonRuntime::CreateImpl(alt::IResource* impl) {
	auto* resource = new PythonResource(this, impl);
	Resources.push_back(resource);
	return resource;
}

void PythonRuntime::DestroyImpl(alt::IResource::Impl* impl) {
	auto* resource = dynamic_cast<PythonResource*>(impl);
	for (int i{}; i < Resources.size(); i++)
	{
		if (Resources[i]->Resource->GetName() == resource->Resource->GetName())
		{
			Resources.erase(Resources.begin() + i);
			break;
		}
	}
	delete resource;
}


void PythonRuntime::OnDispose() {
	py::finalize_interpreter();
}

