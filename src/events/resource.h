#pragma once

#include <PythonRuntime.h>
#include <main.h>

PythonRuntime::RegisterArgGetter(
        alt::CEvent::Type::RESOURCE_ERROR,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CResourceErrorEvent*>(ev);
            auto resourceName = event->GetResource()->GetName().ToString();
            return py::make_tuple(resourceName);
        }
);

PythonRuntime::RegisterArgGetter(
        alt::CEvent::Type::RESOURCE_START,
        [](const alt::CEvent* ev)
        {
            auto event = dynamic_cast<const alt::CResourceStartEvent*>(ev);
            auto resourceName = event->GetResource()->GetName().ToString();
            return py::make_tuple(resourceName);
        }
);