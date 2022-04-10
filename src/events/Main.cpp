#include "events.hpp"

EventHandler resourceStart(alt::CEvent::Type::RESOURCE_START, "resource_start", [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CResourceStartEvent*>(ev);
    args.append(event->GetResource()->GetName().ToString());
    return args;
});

EventHandler resourceStop(alt::CEvent::Type::RESOURCE_STOP, "resource_stop", [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CResourceStopEvent*>(ev);
    args.append(event->GetResource()->GetName().ToString());
    return args;
});

EventHandler resourceError(alt::CEvent::Type::RESOURCE_ERROR, "resource_error", [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CResourceErrorEvent*>(ev);
    args.append(event->GetResource()->GetName().ToString());
    return args;
});

