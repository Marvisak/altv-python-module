#pragma once

void RegisterEnums(const py::module_& m) {
    auto pyEnum = py::enum_<alt::IBaseObject::Type>(m, "BaseObjectType");
    pyEnum.value("Player", alt::IBaseObject::Type::PLAYER);
    pyEnum.value("Vehicle", alt::IBaseObject::Type::VEHICLE);
    pyEnum.value("Blip", alt::IBaseObject::Type::BLIP);
    pyEnum.value("WebView", alt::IBaseObject::Type::WEBVIEW);
    pyEnum.value("VoiceChannel", alt::IBaseObject::Type::VOICE_CHANNEL);
    pyEnum.value("Colshape", alt::IBaseObject::Type::COLSHAPE);
    pyEnum.value("Checkpoint", alt::IBaseObject::Type::CHECKPOINT);
    pyEnum.value("WebSocketClient", alt::IBaseObject::Type::WEBSOCKET_CLIENT);
    pyEnum.value("HttpClient", alt::IBaseObject::Type::HTTP_CLIENT);
    pyEnum.value("Audio", alt::IBaseObject::Type::AUDIO);
}