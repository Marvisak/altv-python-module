#include "events.hpp"

#include <utility>

#include "PythonRuntime.hpp"

EventHandler::EventHandler(alt::CEvent::Type eventType, std::string name) : name(std::move(name)) {
	all()[eventType] = this;
}

EventHandler::EventHandler(alt::CEvent::Type eventType, std::string name, ArgsGetter argsGetter) : name(std::move(name)), argsGetter(argsGetter) {
	all()[eventType] = this;
}

void EventHandler::RegisterEvents(py::module_ m) {
	for (const auto& eventHandler : all()) {
		auto type = eventHandler.first;
		m.def(eventHandler.second->name.c_str(), [type](const py::function& func) {
			PyThreadState* interp = PyThreadState_Get();
			PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
			resource->AddLocalEvent(type, func);
		});
	}
}

EventHandler* EventHandler::Get(const alt::CEvent* event) {
    return all()[event->GetType()];
}

py::list EventHandler::GetEventArgs(const alt::CEvent* event) {
    if (argsGetter.has_value())
        return argsGetter.value()(event);
    return py::list {};
}