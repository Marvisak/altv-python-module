#pragma once

#include "main.hpp"
#include "utils.hpp"

uint32_t Hash(const std::string& str) {
    return alt::ICore::Instance().Hash(str);
}

py::object GetMeta(const std::string& key) {
	return Utils::MValueToValue(alt::ICore::Instance().GetMetaData(key));
}

void SetMeta(const std::string& key, const py::object& value) {
	alt::ICore::Instance().SetMetaData(key, Utils::ValueToMValue(value));
}

bool HasMeta(const std::string& key) {
	return alt::ICore::Instance().HasMetaData(key);
}

void DeleteMeta(const std::string& key) {
	return alt::ICore::Instance().DeleteMetaData(key);
}

py::object GetSyncedMeta(const std::string& key) {
	return Utils::MValueToValue(alt::ICore::Instance().GetSyncedMetaData(key));
}

void SetSyncedMeta(const std::string& key, const py::object& value) {
	alt::ICore::Instance().SetSyncedMetaData(key, Utils::ValueToMValue(value));
}

bool HasSyncedMeta(const std::string& key) {
	return alt::ICore::Instance().HasSyncedMetaData(key);
}

void DeleteSyncedMeta(const std::string& key) {
	return alt::ICore::Instance().DeleteSyncedMetaData(key);
}

void RegisterHelpersFunctions(py::module_ m) {
    m.def("hash", &Hash);

	m.def("get_meta", &GetMeta);
	m.def("set_meta", &SetMeta);
	m.def("has_meta", &HasMeta);
	m.def("delete_meta", &DeleteMeta);

	m.def("get_synced_meta", &GetSyncedMeta);
	m.def("set_synced_meta", &SetSyncedMeta);
	m.def("has_synced_meta", &HasSyncedMeta);
	m.def("delete_synced_meta", &DeleteSyncedMeta);
}
