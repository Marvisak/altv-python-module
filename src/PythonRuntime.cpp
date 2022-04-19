#include "PythonRuntime.hpp"

PythonRuntime* PythonRuntime::Instance = nullptr;

PythonRuntime::PythonRuntime() {
	py::initialize_interpreter(false);
	py::module_::import("alt");
	MainInterpreter = PyThreadState_Get();
	Instance = this;
}

PythonResource* PythonRuntime::GetPythonResourceFromInterp(PyThreadState* interp) {
	for (PythonResource* resource : Resources)
		if (resource->Interpreter == interp)
			return resource;
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
	PyThreadState_Swap(MainInterpreter);
	py::finalize_interpreter();
}

