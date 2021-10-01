//
// Created by Marlon on 30/07/2021.
//

#pragma once

#include "main.h"

class Clothes
{

  public:
    uint16_t drawableId;
    uint8_t textureId, paletteId;

    Clothes(uint16_t drawable, uint8_t texture, uint8_t palette) : drawableId(drawable), textureId(texture), paletteId(palette)
    {
    }
    Clothes(alt::Cloth cloth) : drawableId(cloth.drawableId), textureId(cloth.textureId), paletteId(cloth.paletteId)
    {
    }

    alt::Cloth toAlt() const
    {
        return alt::Cloth{drawableId, textureId, paletteId};
    }

    std::string toString() const
    {
        return "Cloth(drawable: " + std::to_string(drawableId) + ", texture: " + std::to_string(textureId) + ", palette: " + std::to_string(paletteId) + ")";
    }
};

void RegisterClothesClass(const py::module_ &m);
