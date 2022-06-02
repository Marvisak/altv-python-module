#include "classes/types/enums.hpp"
#include "main.hpp"
#include "utils.hpp"

py::cpp_function Event(Event event)
{
	return [event](const py::function& func) {
		PyThreadState* interp = PyThreadState_Get();
		PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
		auto castEvent = static_cast<alt::CEvent::Type>(event);
		resource->AddLocalEvent(castEvent, func);
	};
}

py::cpp_function CustomEvent(const std::string& eventName)
{
	return [eventName](const py::function& func) {
		PyThreadState* interp = PyThreadState_Get();
		PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
		resource->AddLocalCustomEvent(eventName, func);
	};
}

py::cpp_function ClientEvent(const std::string& eventName)
{
	return [eventName](const py::function& func) {
		PyThreadState* interp = PyThreadState_Get();
		PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
		resource->AddRemoteEvent(eventName, func);
	};
}

void Emit(const std::string& eventName, const py::args& args)
{
	alt::MValueArgs eventArgs;
	for (const py::handle& arg : *args)
		eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));

	alt::ICore::Instance().TriggerLocalEvent(eventName, eventArgs);
}

void EmitClient(alt::IPlayer* player, const std::string& eventName, const py::args& args)
{
	alt::MValueArgs eventArgs;
	for (const py::handle& arg : *args)
		eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
	alt::ICore::Instance().TriggerClientEvent(player, eventName, eventArgs);
}

void EmitClient(const std::vector<alt::IPlayer*>& players, const std::string& eventName, const py::args& args)
{
	alt::MValueArgs eventArgs;
	for (const py::handle& arg : *args)
		eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
	for (alt::IPlayer* player : players)
		alt::ICore::Instance().TriggerClientEvent(player, eventName, eventArgs);
}

void EmitAllClients(const std::string& eventName, const py::args& args)
{
	alt::MValueArgs eventArgs;
	for (const py::handle& arg : *args)
		eventArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
	alt::ICore::Instance().TriggerClientEventForAll(eventName, eventArgs);
}

void RegisterEventFunctions(py::module_ m)
{
	m.def("event", &Event, py::arg("event"), "Decorator for registering event listener");
	m.def("custom_event", &CustomEvent, py::arg("event"), "Decorator for registering custom event listener");
	m.def("client_event", &ClientEvent, py::arg("event"), "Decorator for registering client event listener");
	m.def("emit", &Emit, py::arg("event_name"), "Emits event");
	m.def("emit_client", py::overload_cast<alt::IPlayer*, const std::string&, const py::args&>(&EmitClient), py::arg("player"), py::arg("event_name"), "Emits client event");
	m.def("emit_client", py::overload_cast<const std::vector<alt::IPlayer*>&, const std::string&, const py::args&>(&EmitClient), py::arg("players"), py::arg("event_name"), "Emits client event to all clients in the list");
	m.def("emit_all_clients", &EmitAllClients, py::arg("event_name"), "Emits event to all clients");
}
