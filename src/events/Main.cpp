#include "events.h"

EventHandler resourceStart(alt::CEvent::Type::RESOURCE_START, "anyResourceStart", [](const alt::CEvent* ev) {
    auto event = dynamic_cast<const alt::CResourceStartEvent*>(ev);
    py::list args;
    args.append(event->GetResource()->GetName().ToString());
    return args;
});

EventHandler resourceStop(alt::CEvent::Type::RESOURCE_STOP, "anyResourceStop", [](const alt::CEvent* ev) {
    auto event = dynamic_cast<const alt::CResourceStopEvent*>(ev);
    py::list args;
    args.append(event->GetResource()->GetName().ToString());
    return args;
});

EventHandler resourceError(alt::CEvent::Type::RESOURCE_ERROR, "anyResourceError", [](const alt::CEvent* ev) {
    auto event = dynamic_cast<const alt::CResourceErrorEvent*>(ev);
    py::list args;
    args.append(event->GetResource()->GetName().ToString());
    return args;
});

