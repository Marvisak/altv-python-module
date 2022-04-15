#include "events.hpp"


EventHandler::EventHandler(alt::CEvent::Type eventType) {
	all()[eventType] = this;
}

EventHandler::EventHandler(alt::CEvent::Type eventType, ArgsGetter argsGetter) : argsGetter(argsGetter) {
	all()[eventType] = this;
}

EventHandler* EventHandler::Get(const alt::CEvent* event) {
    return all()[event->GetType()];
}

py::list EventHandler::GetEventArgs(const alt::CEvent* event) {
    if (argsGetter.has_value())
        return argsGetter.value()(event);
    return py::list {};
}