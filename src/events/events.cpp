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

void EventHandler::GetEventArgs(const alt::CEvent* event, py::list& args) {
    if (argsGetter.has_value())
		argsGetter.value()(event, args);
}