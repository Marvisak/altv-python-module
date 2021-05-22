#pragma once
#include <PythonRuntime.h>
#include <main.h>
#include <events/player.h>
#include <events/resource.h>


PythonRuntime::RegisterArgGetter(
        alt::CEvent::Type::SERVER_SCRIPT_EVENT,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
            py::list args;
            for (const auto &arg : event->GetArgs())
            {
            auto value = Utils::MValueToValue(arg);
            args.append(value);
            }
            return args;
        }
);

