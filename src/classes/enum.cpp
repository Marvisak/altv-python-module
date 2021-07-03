#include "enum.h"

void RegisterEnums(const py::module_& m) {
    auto pyBaseObjectEnum = py::enum_<alt::IBaseObject::Type>(m, "BaseObjectType");
    pyBaseObjectEnum.value("Player", alt::IBaseObject::Type::PLAYER);
    pyBaseObjectEnum.value("Vehicle", alt::IBaseObject::Type::VEHICLE);
    pyBaseObjectEnum.value("Blip", alt::IBaseObject::Type::BLIP);
    pyBaseObjectEnum.value("WebView", alt::IBaseObject::Type::WEBVIEW);
    pyBaseObjectEnum.value("VoiceChannel", alt::IBaseObject::Type::VOICE_CHANNEL);
    pyBaseObjectEnum.value("Colshape", alt::IBaseObject::Type::COLSHAPE);
    pyBaseObjectEnum.value("Checkpoint", alt::IBaseObject::Type::CHECKPOINT);
    pyBaseObjectEnum.value("WebSocketClient", alt::IBaseObject::Type::WEBSOCKET_CLIENT);
    pyBaseObjectEnum.value("HttpClient", alt::IBaseObject::Type::HTTP_CLIENT);
    pyBaseObjectEnum.value("Audio", alt::IBaseObject::Type::AUDIO);

    auto pyRadioEnum = py::enum_<RadioStation>(m, "RadioStation");
    pyRadioEnum.value("RadioOff", RadioStation::RadioOff);
    pyRadioEnum.value("LosSantosRockRadio", RadioStation::LosSantosRockRadio);
    pyRadioEnum.value("NonStopPopFm", RadioStation::NonStopPopFm);
    pyRadioEnum.value("RadioLosSantos", RadioStation::RadioLosSantos);
    pyRadioEnum.value("ChannelX", RadioStation::ChannelX);
    pyRadioEnum.value("WestCoastTalkRadio", RadioStation::WestCoastTalkRadio);
    pyRadioEnum.value("RebelRadio", RadioStation::RebelRadio);
    pyRadioEnum.value("SoulwaxFm", RadioStation::SoulwaxFm);
    pyRadioEnum.value("EastLosFm", RadioStation::EastLosFm);
    pyRadioEnum.value("WestCoastClassics", RadioStation::WestCoastClassics);
    pyRadioEnum.value("TheMusicLocker", RadioStation::TheMusicLocker);
    pyRadioEnum.value("TheBlueArk", RadioStation::TheBlueArk);
    pyRadioEnum.value("WorldWideFm", RadioStation::WorldWideFm);
    pyRadioEnum.value("FlyloFm", RadioStation::FlyloFm);
    pyRadioEnum.value("TheLowdown", RadioStation::TheLowdown);
    pyRadioEnum.value("RadioMirrorPark", RadioStation::RadioMirrorPark);
    pyRadioEnum.value("KultFM", RadioStation::KultFM);
    pyRadioEnum.value("VinewoodBoulevardRadio", RadioStation::VinewoodBoulevardRadio);
    pyRadioEnum.value("SelfRadio", RadioStation::SelfRadio);
    pyRadioEnum.value("TheLab", RadioStation::TheLab);
    pyRadioEnum.value("Space", RadioStation::Space);
    pyRadioEnum.value("BlondedLosSantosFM", RadioStation::BlondedLosSantosFM);
    pyRadioEnum.value("LosSantosUndergroundRadio", RadioStation::LosSantosUndergroundRadio);
    pyRadioEnum.value("IFruitRadio", RadioStation::IFruitRadio);
}