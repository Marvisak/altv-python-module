#include "voicechannel.h"

void RegisterVoiceChannelClass(const py::module_& m) {
    auto pyClass = py::class_<VoiceChannel, BaseObject>(m, "VoiceChannel");
    pyClass.def(py::init([](bool isSpatial, float maxDistance) {
        return VoiceChannel(VoiceChannel::CreateChannel(isSpatial, maxDistance));
    }));

    // Methods
    pyClass.def("hasPlayer", &VoiceChannel::HasPlayer, py::arg("player"));
    pyClass.def("addPlayer", &VoiceChannel::AddPlayer, py::arg("player"));
    pyClass.def("removePlayer", &VoiceChannel::RemovePlayer, py::arg("player"));
    pyClass.def("isPlayerMuted", &VoiceChannel::IsPlayerMuted, py::arg("player"));
    pyClass.def("mutePlayer", &VoiceChannel::MutePlayer, py::arg("player"));
    pyClass.def("unmutePlayer", &VoiceChannel::UnmutePlayer, py::arg("player"));

}