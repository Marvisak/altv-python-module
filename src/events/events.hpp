#pragma once
#include "main.hpp"


class EventHandler {
    static std::unordered_map<alt::CEvent::Type, EventHandler*>& all() {
        static std::unordered_map<alt::CEvent::Type, EventHandler*> _all;
        return _all;
    }
    using ArgsGetter = std::function<py::list(const alt::CEvent*)>;
    std::optional<ArgsGetter> argsGetter;
    std::string name;
public:
    EventHandler(alt::CEvent::Type eventType, std::string name, ArgsGetter argsGetter);
    EventHandler(alt::CEvent::Type eventType, std::string name);
    py::list GetEventArgs(const alt::CEvent* event);

	static void RegisterEvents(py::module_ m);
    static EventHandler* Get(const alt::CEvent* event);
};