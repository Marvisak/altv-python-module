#pragma once

#include "version/version.h"
#include "utils.hpp"
#include "main.hpp"

uint32_t Hash(const std::string& str) {
    return alt::ICore::Instance().Hash(str);
}

py::list GetAllResources() {
	std::vector<alt::IResource*> resources = alt::ICore::Instance().GetAllResources();
	py::list list;
	for (auto resource : resources) {
		py::dict dict;
		dict["name"] = resource->GetName();
		dict["type"] = resource->GetType();
		list.append(dict);
	}
	return list;
}

uint32_t GetNetTime() {
	return alt::ICore::Instance().GetNetTime();
}

py::object GetResourceExports(const std::string& resourceName) {
	alt::IResource* resource = alt::ICore::Instance().GetResource(resourceName);
	if (resource != nullptr)
		return Utils::MValueToValue(resource->GetExports());
	throw std::runtime_error("Resource does not exist");
}

std::string GetResourceMain(const std::string& resourceName) {
	alt::IResource* resource = alt::ICore::Instance().GetResource(resourceName);
	if (resource != nullptr)
		return resource->GetMain();
	throw std::runtime_error("Resource does not exist");
}

std::string GetResourcePath(const std::string& resourceName) {
	alt::IResource* resource = alt::ICore::Instance().GetResource(resourceName);
	if (resource != nullptr)
		return resource->GetPath();
	throw std::runtime_error("Resource does not exist");
}

py::object GetServerConfig() {
	alt::config::Node config = alt::ICore::Instance().GetServerConfig();
	return Utils::ConfigNodeToValue(config);
}

alt::VehicleModelInfo GetVehicleModelInfoByHash(uint32_t vehicleHash) {
	return alt::ICore::Instance().GetVehicleModelByHash(vehicleHash);
}

bool HasResource(const std::string& resourceName) {
	alt::IResource* resource = alt::ICore::Instance().GetResource(resourceName);
	return resource && resource->IsStarted();
}

uint64_t HashServerPassword(const std::string& password) {
	return alt::ICore::Instance().HashServerPassword(password);
}

void RestartResource(const std::string& resourceName) {
	alt::ICore::Instance().RestartResource(resourceName);
}

void StartResource(const std::string& resourceName) {
	alt::ICore::Instance().StartResource(resourceName);
}

void StopResource(const std::string& resourceName) {
	alt::ICore::Instance().StopResource(resourceName);
}

void SetPassword(const std::string& password) {
	return alt::ICore::Instance().SetPassword(password);
}

void StopServer() {
	alt::ICore::Instance().StopServer();
}

std::string GetResourceName() {
	PyThreadState* interp = PyThreadState_Get();
	PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromInterp(interp);
	return resource->GetResource()->GetName();
}

std::string StringToSHA256(const std::string& str) {
	return alt::ICore::Instance().StringToSHA256(str);
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
	m.attr("branch") = alt::ICore::Instance().GetBranch();
	m.attr("debug") = alt::ICore::Instance().IsDebug();
	m.attr("default_dimension") = alt::DEFAULT_DIMENSION;
	m.attr("global_dimension") = alt::GLOBAL_DIMENSION;
	m.attr("root_dir") = alt::ICore::Instance().GetRootDirectory();
	m.attr("sdk_version") = ALT_SDK_VERSION;
	m.attr("version") = alt::ICore::Instance().GetVersion();

    m.def("hash", &Hash, py::arg("str"));
	m.def("get_net_time", &GetNetTime);
	m.def("get_server_config", &GetServerConfig);
	m.def("get_vehicle_model_info_by_hash", &GetVehicleModelInfoByHash, py::arg("vehicle_hash"));
	m.def("hash_server_password", &HashServerPassword, py::arg("password"));
	m.def("set_password", &SetPassword, py::arg("password"));
	m.def("stop_server", &StopServer);
	m.def("string_to_sha256", &StringToSHA256, py::arg("str"));

	m.def("get_all_resources", &GetAllResources);
	m.def("get_resource_exports", &GetResourceExports, py::arg("resource_name"));
	m.def("get_resource_main", &GetResourceMain, py::arg("resource_name"));
	m.def("get_resource_path", &GetResourcePath, py::arg("resource_name"));
	m.def("has_resource", &HasResource, py::arg("resource_name"));
	m.def("restart_resource", &RestartResource, py::arg("resource_name"));
	m.def("start_resource", &StartResource, py::arg("resource_name"));
	m.def("stop_resource", &StopResource, py::arg("resource_name"));
	m.def("get_resource_name", &GetResourceName);

	m.def("get_meta", &GetMeta, py::arg("key"));
	m.def("set_meta", &SetMeta, py::arg("key"), py::arg("value"));
	m.def("has_meta", &HasMeta, py::arg("key"));
	m.def("delete_meta", &DeleteMeta, py::arg("key"));

	m.def("get_synced_meta", &GetSyncedMeta, py::arg("key"));
	m.def("set_synced_meta", &SetSyncedMeta, py::arg("key"), py::arg("value"));
	m.def("has_synced_meta", &HasSyncedMeta, py::arg("key"));
	m.def("delete_synced_meta", &DeleteSyncedMeta, py::arg("key"));
}
