#include "classes/classes.hpp"


void RegisterConnectionInfoClass(const py::module_& m) {
	auto pyClass = py::class_<alt::IConnectionInfo, alt::Ref<alt::IConnectionInfo>>(m, "ConnectionInfo");
	pyClass.def_property_readonly("name", &alt::IConnectionInfo::GetName);
	pyClass.def_property_readonly("social_id", &alt::IConnectionInfo::GetSocialId);
	pyClass.def_property_readonly("hwid_hash", &alt::IConnectionInfo::GetHwIdHash);
	pyClass.def_property_readonly("hwid_ex_hash", &alt::IConnectionInfo::GetHwIdExHash);
	pyClass.def_property_readonly("auth_token", &alt::IConnectionInfo::GetAuthToken);
	pyClass.def_property_readonly("is_debug", &alt::IConnectionInfo::GetIsDebug);
	pyClass.def_property_readonly("branch", &alt::IConnectionInfo::GetBranch);
	pyClass.def_property_readonly("build", &alt::IConnectionInfo::GetBuild);
	pyClass.def_property_readonly("cdn_url", &alt::IConnectionInfo::GetCdnUrl);
	pyClass.def_property_readonly("password_hash", &alt::IConnectionInfo::GetPasswordHash);
	pyClass.def_property_readonly("ip", &alt::IConnectionInfo::GetIp);
	pyClass.def_property_readonly("discord_user_id", &alt::IConnectionInfo::GetDiscordUserID);
	pyClass.def_property_readonly("accepted", &alt::IConnectionInfo::IsAccepted);

	pyClass.def("accept", &alt::IConnectionInfo::Accept);
	pyClass.def("decline", &alt::IConnectionInfo::Decline, py::arg("reason"));
}
