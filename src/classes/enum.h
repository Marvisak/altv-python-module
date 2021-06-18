#pragma once

void RegisterEnums(const py::module_& m) {
    py::enum_<alt::IBaseObject::Type>(m, "BaseObjectType")
        .value("Player", alt::IBaseObject::Type::PLAYER)
        .value("Vehicle", alt::IBaseObject::Type::VEHICLE)
        .value("Blip", alt::IBaseObject::Type::BLIP)
        .value("WebView", alt::IBaseObject::Type::WEBVIEW)
        .value("VoiceChannel", alt::IBaseObject::Type::VOICE_CHANNEL)
        .value("Colshape", alt::IBaseObject::Type::COLSHAPE)
        .value("Checkpoint", alt::IBaseObject::Type::CHECKPOINT)
        .value("WebSocketClient", alt::IBaseObject::Type::WEBSOCKET_CLIENT)
        .value("HttpClient", alt::IBaseObject::Type::HTTP_CLIENT)
        .value("Audio", alt::IBaseObject::Type::AUDIO);
}