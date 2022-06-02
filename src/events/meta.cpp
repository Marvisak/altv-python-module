#include "events.hpp"
#include "utils.hpp"

EventHandler syncedMetaChange(alt::CEvent::Type::SYNCED_META_CHANGE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CSyncedMetaDataChangeEvent*>(ev);
	args.append(Utils::GetBaseObject(event->GetTarget().Get()));
	args.append(event->GetKey());
	args.append(Utils::MValueToValue(event->GetVal()));
	args.append(Utils::MValueToValue(event->GetOldVal()));
});

EventHandler streamSyncedMetaChange(alt::CEvent::Type::STREAM_SYNCED_META_CHANGE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CStreamSyncedMetaDataChangeEvent*>(ev);
	args.append(Utils::GetBaseObject(event->GetTarget().Get()));
	args.append(event->GetKey());
	args.append(Utils::MValueToValue(event->GetVal()));
	args.append(Utils::MValueToValue(event->GetOldVal()));
});

EventHandler globalMetaChange(alt::CEvent::Type::GLOBAL_META_CHANGE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CGlobalMetaDataChangeEvent*>(ev);
	args.append(event->GetKey());
	args.append(Utils::MValueToValue(event->GetVal()));
	args.append(Utils::MValueToValue(event->GetOldVal()));
});

EventHandler globalSyncedMetaChange(alt::CEvent::Type::GLOBAL_SYNCED_META_CHANGE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CGlobalSyncedMetaDataChangeEvent*>(ev);
	args.append(event->GetKey());
	args.append(Utils::MValueToValue(event->GetVal()));
	args.append(Utils::MValueToValue(event->GetOldVal()));
});

EventHandler localMetaChange(alt::CEvent::Type::LOCAL_SYNCED_META_CHANGE, [](const alt::CEvent* ev, py::list& args) {
	auto event = dynamic_cast<const alt::CLocalMetaDataChangeEvent*>(ev);
	args.append(event->GetTarget().Get());
	args.append(event->GetKey());
	args.append(Utils::MValueToValue(event->GetVal()));
	args.append(Utils::MValueToValue(event->GetOldVal()));
});
