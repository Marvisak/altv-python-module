//
// Created by Marlon on 30/07/2021.
//
#pragma once

#include "main.h"

class DlcClothes {

public:
    uint32_t dlc;
    uint16_t drawableId;
    uint8_t textureId, paletteId;

    DlcClothes(uint32_t dlc, uint16_t drawable, uint8_t texture, uint8_t palette) : dlc(dlc), drawableId(drawable), textureId(texture), paletteId(palette) { }
    DlcClothes(alt::DlcCloth dlcCloth) : dlc(dlcCloth.dlc), drawableId(dlcCloth.drawableId), textureId(dlcCloth.textureId), paletteId(dlcCloth.paletteId) { }

    alt::DlcCloth toAlt() const {
        return alt::DlcCloth {dlc, drawableId, textureId, paletteId};
    }

    std::string toString() const {
        return "DlcCloth(dlc: " + std::to_string(dlc) + ", drawable: " + std::to_string(drawableId) + ", texture: " + std::to_string(textureId) + ", palette: " + std::to_string(paletteId) + ")";
    }
};

void RegisterDlcClothesClass(const py::module_& m);

