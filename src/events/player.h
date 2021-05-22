#pragma once
#include <main.h>
#include <PythonRuntime.h>

PythonRuntime::RegisterArgGetter(
        alt::CEvent::Type::PLAYER_CONNECT,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CPlayerConnectEvent*>(ev);
            Player player {event->GetTarget()};
            return py::make_tuple(player);
        }
);