#include "events.h"
#include "utils.h"

EventHandler serverScriptEvent(alt::CEvent::Type::SERVER_SCRIPT_EVENT, [](const alt::CEvent* ev) {
    auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
    return event->GetName().ToString();
}, [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
    for (const auto& arg : event->GetArgs()) {
        auto value = Utils::MValueToValue(arg);
        args.append(value);
    }
    return args;
});

EventHandler clientScriptEvent(alt::CEvent::Type::CLIENT_SCRIPT_EVENT, [](const alt::CEvent* ev) {
    auto event = dynamic_cast<const alt::CClientScriptEvent*>(ev);
    return event->GetName().ToString();
}, [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CClientScriptEvent*>(ev);
    for (const auto& arg : event->GetArgs()) {
        auto value = Utils::MValueToValue(arg);
        args.append(value);
    }
    return args;
});

EventHandler resourceStart(alt::CEvent::Type::RESOURCE_START, "anyResourceStart", [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CResourceStartEvent*>(ev);
    args.append(event->GetResource()->GetName().ToString());
    return args;
});

EventHandler resourceStop(alt::CEvent::Type::RESOURCE_STOP, "anyResourceStop", [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CResourceStopEvent*>(ev);
    args.append(event->GetResource()->GetName().ToString());
    return args;
});

EventHandler resourceError(alt::CEvent::Type::RESOURCE_ERROR, "anyResourceError", [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CResourceErrorEvent*>(ev);
    args.append(event->GetResource()->GetName().ToString());
    return args;
});

