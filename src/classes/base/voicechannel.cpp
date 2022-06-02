#include "classes/classes.hpp"

void RegisterVoiceChannelClass(const py::module_& m)
{
	auto pyClass = py::class_<alt::IVoiceChannel, alt::IBaseObject, alt::Ref<alt::IVoiceChannel>>(m, "VoiceChannel");

	pyClass.def(py::init<>([](bool spatial, float maxDistance) {
					auto voiceChannel = alt::ICore::Instance().CreateVoiceChannel(spatial, maxDistance);
					if (voiceChannel)
						return voiceChannel.Get();
					throw std::runtime_error("Failed to create VoiceChannel, make sure voice chat is enabled");
				}),
				py::arg("spatial"), py::arg("max_distance"));

	pyClass.def_property_readonly("player_count", &alt::IVoiceChannel::GetPlayerCount);
	pyClass.def_property_readonly("players", &alt::IVoiceChannel::GetPlayers);
	pyClass.def_property_readonly("max_distance", &alt::IVoiceChannel::GetMaxDistance);
	pyClass.def_property_readonly("spatial", &alt::IVoiceChannel::IsSpatial);

	pyClass.def("add_player", &alt::IVoiceChannel::AddPlayer, py::arg("player"));
	pyClass.def("has_player", &alt::IVoiceChannel::HasPlayer, py::arg("player"));
	pyClass.def("is_player_muted", &alt::IVoiceChannel::IsPlayerMuted, py::arg("player"));
	pyClass.def("mute_player", &alt::IVoiceChannel::MutePlayer, py::arg("player"));
	pyClass.def("remove_player", &alt::IVoiceChannel::RemovePlayer);
	pyClass.def("unmute_player", &alt::IVoiceChannel::UnmutePlayer);
}
