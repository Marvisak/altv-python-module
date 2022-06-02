#include "PythonRuntime.hpp"
#ifdef __linux__
#include <dlfcn.h>
#endif

PythonRuntime* PythonRuntime::instance = nullptr;

PythonRuntime::PythonRuntime()
{
#ifdef __linux__
	// Without this, python doesn't recognize the shared lib, should be linux only issue
	std::string so = std::string("libpython") + std::to_string(PY_MAJOR_VERSION) + "." + std::to_string(PY_MINOR_VERSION) + ".so.1.0";
	python = dlopen(so.c_str(), RTLD_NOW | RTLD_NOLOAD | RTLD_GLOBAL);
#endif
	// For compatibility reasons disable site packages, if user wants to use 3rd party modules they should create venv
	Py_IsolatedFlag = 1;

	std::string path = alt::ICore::Instance().GetRootDirectory() + SEPARATOR + "modules" + SEPARATOR + "python-module" + SEPARATOR + "python";

	// Venv should get recognized automatically, but if it doesn't, here is a config option for it
	alt::config::Node venv = alt::ICore::Instance().GetServerConfig()["python-venv"];
	if (venv)
	{
#ifdef _WIN32
		std::string separator = ";";
#else
		std::string separator = ":";
#endif
		path.append(separator + alt::ICore::Instance().GetRootDirectory() + SEPARATOR + venv.ToString());
	}

	Py_SetPath(std::wstring(path.begin(), path.end()).c_str());
	py::initialize_interpreter(false);
	py::module_::import("alt");
	mainInterpreter = PyThreadState_Get();
	instance = this;
}

PythonResource* PythonRuntime::GetPythonResourceFromInterp(PyThreadState* interp)
{
	for (PythonResource* resource : resources)
		if (resource->GetInterpreter() == interp)
			return resource;
	if (interp->interp == PyInterpreterState_Main())
		alt::ICore::Instance().LogError("Main Interpreter Passed");
	return nullptr;
}

alt::IResource::Impl* PythonRuntime::CreateImpl(alt::IResource* impl)
{
	auto* resource = new PythonResource(this, impl);
	resources.push_back(resource);
	return resource;
}

void PythonRuntime::DestroyImpl(alt::IResource::Impl* impl)
{
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

void PythonRuntime::OnDispose()
{
	PyThreadState_Swap(mainInterpreter);
	py::finalize_interpreter();
#ifdef __linux__
	dlclose(python);
#endif
}
