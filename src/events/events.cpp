#include "events.hpp"

#include <utility>

EventHandler::EventHandler(alt::CEvent::Type eventType, NameGetter nameGetter, ArgsGetter argsGetter) : nameGetter{std::move(nameGetter)}, argsGetter{std::move(argsGetter)} {
    all()[eventType] = this;
}

EventHandler::EventHandler(alt::CEvent::Type eventType, std::string name, ArgsGetter argsGetter) : name{name}, argsGetter{argsGetter} {
    all()[eventType] = this;
}

EventHandler::EventHandler(alt::CEvent::Type eventType, NameGetter nameGetter) : nameGetter{std::move(nameGetter)} {
    all()[eventType] = this;
}


EventHandler::EventHandler(alt::CEvent::Type eventType, std::string name) : name{std::move(name)} {
    all()[eventType] = this;
}

EventHandler* EventHandler::Get(const alt::CEvent* event) {
    return all()[event->GetType()];
}

std::string EventHandler::GetEventName(const alt::CEvent* event) {
    if (name.has_value()) {
        return name.value();
    } else {
        return nameGetter.value()(event);
    }
}

py::list EventHandler::GetEventArgs(const alt::CEvent* event) {
    if (argsGetter.has_value()) {
        return argsGetter.value()(event);
    }
    return py::list {};
}