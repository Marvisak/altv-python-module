#include "PythonRuntime.hpp"

PythonRuntime* PythonRuntime::instance = nullptr;

PythonRuntime::PythonRuntime() {
	py::initialize_interpreter(false);
	py::module_::import("alt");
	mainInterpreter = PyThreadState_Get();
	instance = this;
}

PythonResource* PythonRuntime::GetPythonResourceFromInterp(PyThreadState* interp) {
	for (PythonResource* resource : resources)
		if (resource->GetInterpreter() == interp)
			return resource;
	return nullptr;
}

alt::IResource::Impl* PythonRuntime::CreateImpl(alt::IResource* impl) {
	auto* resource = new PythonResource(this, impl);
	resources.push_back(resource);
	return resource;
}

void PythonRuntime::DestroyImpl(alt::IResource::Impl* impl) {
	auto* resource = dynamic_cast<PythonResource*>(impl);
	for (int i{}; i < resources.size(); i++)
	{
		if (resources[i]->GetResource()->GetName() == resource->GetResource()->GetName())
		{
			resources.erase(resources.begin() + i);
			break;
		}
	}
	delete resource;
}


void PythonRuntime::OnDispose() {
	PyThreadState_Swap(mainInterpreter);
	py::finalize_interpreter();
}

