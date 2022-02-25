#pragma once
#include "main.h"

class EventHandler {
    static std::unordered_map<alt::CEvent::Type, EventHandler*>& all()
    {
        static std::unordered_map<alt::CEvent::Type, EventHandler*> _all;
        return _all;
    }
    using NameGetter = std::function<std::string(const alt::CEvent*)>;
    using ArgsGetter = std::function<py::list(const alt::CEvent*)>;
    std::optional<NameGetter> nameGetter;
    std::optional<ArgsGetter> argsGetter;
    std::optional<std::string> name;
public:
    EventHandler(alt::CEvent::Type eventType, NameGetter nameGetter, ArgsGetter argsGetter);
    EventHandler(alt::CEvent::Type eventType, std::string name, ArgsGetter argsGetter);
    EventHandler(alt::CEvent::Type eventType, NameGetter nameGetter);
    EventHandler(alt::CEvent::Type eventType, std::string  name);
    std::string GetEventName(const alt::CEvent* event);
    py::list GetEventArgs(const alt::CEvent* event);

    static EventHandler* Get(const alt::CEvent* event);
};