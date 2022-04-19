#pragma once
#include "main.hpp"


class EventHandler {
    static std::unordered_map<alt::CEvent::Type, EventHandler*>& all() {
        static std::unordered_map<alt::CEvent::Type, EventHandler*> _all;
        return _all;
    }
    using ArgsGetter = std::function<void(const alt::CEvent*, py::list&)>;
    std::optional<ArgsGetter> argsGetter;
public:
    EventHandler(alt::CEvent::Type eventType, ArgsGetter argsGetter);
	// TODO probably remove this
	explicit EventHandler(alt::CEvent::Type eventType); // This is kinda useless, currently it's only used to know that the event is registered, might be removed in the future, but I'll keep it here now
    void GetEventArgs(const alt::CEvent* event, py::list& args);

    static EventHandler* Get(const alt::CEvent* event);
};