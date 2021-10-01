#pragma once

#include "main.h"
#include "utils.h"

unsigned int Hash(const std::string& strToHash)
{
	return Core->Hash(strToHash);
}

uint32_t GetNetTime()
{
	return Core->GetNetTime();
}

void SetPassword(const std::string& password)
{
	Core->SetPassword(password);
}

py::object GetMeta(const std::string& key)
{
	return Utils::MValueToValue(Core->GetMetaData(key));
}

py::object GetSyncedMeta(const std::string& key)
{
	return Utils::MValueToValue(Core->GetSyncedMetaData(key));
}

bool HasMeta(const std::string& key)
{
	return Core->HasMetaData(key);
}

bool HasSyncedMeta(const std::string& key)
{
	return Core->HasSyncedMetaData(key);
}

void SetMeta(const std::string& key, const py::object& value)
{
	Core->SetMetaData(key, Utils::ValueToMValue(value));
}

void SetSyncedMeta(const std::string& key, const py::object& value)
{
	Core->SetSyncedMetaData(key, Utils::ValueToMValue(value));
}

void RegisterHelpersFunctions(py::module_ m)
{
	// Getters
	m.attr("branch") = Core->GetBranch().ToString();
	m.attr("debug") = Core->IsDebug();
	m.attr("defaultDimension") = alt::DEFAULT_DIMENSION;
	m.attr("globalDimension") = alt::GLOBAL_DIMENSION;
	m.attr("rootDir") = Core->GetRootDirectory().ToString();
	m.attr("sdkVersion") = Core->SDK_VERSION;
	m.attr("version") = Core->GetVersion().ToString();

	// Methods
	m.def("hash", &Hash, "Hashes string");
	m.def("getNetTime", &GetNetTime, "Gets the amount of milliseconds since the server was started");
	m.def("setPassword", &SetPassword, "Change the server password at runtime");

	// Metadata
	m.def("getMeta", &GetMeta, "Gets a value using the specified key");
	m.def("getSyncedMeta", &GetSyncedMeta, "Gets a value using the specified key");
	m.def("hasMeta", &HasMeta, "Determines whether contains the specified key");
	m.def("hasSyncedMeta", &HasSyncedMeta, "Determines whether contains the specified key");
	m.def("setMeta", &SetMeta, "Stores the given value with the specified key");
	m.def("setSyncedMeta", &SetSyncedMeta, "Stores the given value with the specified key");
}
