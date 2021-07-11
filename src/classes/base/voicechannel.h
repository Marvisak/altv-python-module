#pragma once

#include "main.h"
#include "baseobject.h"
#include "player.h"

class VoiceChannel : public BaseObject {
private:
    alt::Ref<alt::IVoiceChannel> voiceChannel;
public:
    VoiceChannel(alt::Ref<alt::IVoiceChannel> voiceChannel) : voiceChannel(voiceChannel), BaseObject(voiceChannel) {}

    static alt::Ref<alt::IVoiceChannel> CreateChannel(bool isSpatial, float maxDistance)
    {
        return Core->CreateVoiceChannel(isSpatial, maxDistance);
    }

    bool HasPlayer(Player player) { return voiceChannel->HasPlayer(player.GetBaseObject()); }
    void AddPlayer(Player player) { voiceChannel->AddPlayer(player.GetBaseObject()); }
    void RemovePlayer(Player player) { voiceChannel->RemovePlayer(player.GetBaseObject()); }

    bool IsPlayerMuted(Player player) { return voiceChannel->IsPlayerMuted(player.GetBaseObject()); }
    void MutePlayer(Player player) { voiceChannel->MutePlayer(player.GetBaseObject()); }
    void UnmutePlayer(Player player) { voiceChannel->UnmutePlayer(player.GetBaseObject()); }
};

void RegisterVoiceChannelClass(const py::module_& m);