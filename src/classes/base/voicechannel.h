#pragma once

#include "main.h"
#include "baseobject.h"
#include "player.h"

class VoiceChannel : public BaseObject {
private:
    alt::Ref<alt::IVoiceChannel> voiceChannel;
public:
    VoiceChannel(const alt::Ref<alt::IVoiceChannel> voiceChannel) : voiceChannel(voiceChannel), BaseObject(voiceChannel) {}


    bool HasPlayer(const Player& player) { return voiceChannel->HasPlayer(player.GetBaseObject()); }
    void AddPlayer(const Player& player) { voiceChannel->AddPlayer(player.GetBaseObject()); }
    void RemovePlayer(const Player& player) { voiceChannel->RemovePlayer(player.GetBaseObject()); }

    bool IsPlayerMuted(const Player& player) { return voiceChannel->IsPlayerMuted(player.GetBaseObject()); }
    void MutePlayer(const Player& player) { voiceChannel->MutePlayer(player.GetBaseObject()); }
    void UnmutePlayer(const Player& player) { voiceChannel->UnmutePlayer(player.GetBaseObject()); }
};

void RegisterVoiceChannelClass(const py::module_& m);