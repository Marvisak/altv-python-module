#include "events.hpp"

EventHandler playerConnect(alt::CEvent::Type::PLAYER_CONNECT, "playerConnect", [](const alt::CEvent* ev) {
    py::list args;
    auto event = dynamic_cast<const alt::CPlayerConnectEvent*>(ev);
    args.append(event->GetTarget().Get());
    return args;
});