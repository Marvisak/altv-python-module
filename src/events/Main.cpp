#include "events.hpp"

EventHandler resourceStart(alt::CEvent::Type::RESOURCE_START, [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CResourceStartEvent*>(ev);
    args.append(event->GetResource()->GetName());
    return args;
});

EventHandler resourceStop(alt::CEvent::Type::RESOURCE_STOP, [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CResourceStopEvent*>(ev);
    args.append(event->GetResource()->GetName());
    return args;
});

EventHandler resourceError(alt::CEvent::Type::RESOURCE_ERROR, [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CResourceErrorEvent*>(ev);
    args.append(event->GetResource()->GetName());
    return args;
});

