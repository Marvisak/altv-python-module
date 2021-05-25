#pragma once

#include <main.h>


class PythonRuntime;
class PythonResource : public alt::IResource::Impl
{
    PythonRuntime* runtime;
    alt::IResource* resource;
    typedef std::vector<py::function> EventsVector;
    typedef std::map<std::string, EventsVector> EventsMap;
    EventsMap ServerEvents;
    EventsMap ClientEvents;

    friend PythonRuntime;
public:
    PythonResource(PythonRuntime* runtime, alt::IResource* resource) : runtime(runtime), resource(resource) {};

    bool Start() override;

    bool Stop() override;

    bool OnEvent(const alt::CEvent* ev) override;

    alt::String GetFullPath();

    void OnCreateBaseObject(alt::Ref<alt::IBaseObject> object) override;

    void OnRemoveBaseObject(alt::Ref<alt::IBaseObject> object) override;

    void AddEvent(const std::string &eventName, const py::function &eventFunc);

    EventsVector GetEventList(const alt::CEvent* &ev, const std::string &eventName)
    {
        if (eventName == "SERVER_SCRIPT_EVENT")
        {
            auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
            return ServerEvents[event->GetName().ToString()];
        }
        else if (eventName == "CLIENT_SCRIPT_EVENT") {
            auto event = dynamic_cast<const alt::CClientScriptEvent*>(ev);
            return ClientEvents[event->GetName().ToString()];
        } else {
            return ServerEvents[eventName];
        }
    }

    class PythonFunction : public alt::IMValueFunction::Impl {
    private:
        py::function func;
    public:
        explicit PythonFunction(py::function func) : func(std::move(func)) {};

        alt::MValue Call(alt::MValueArgs args) const override;
    };

    bool MakeClient(alt::IResource::CreationInfo* info, alt::Array<alt::String> files) override;

};

