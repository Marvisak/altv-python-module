//
// Created by Marlon on 31/07/2021.
//

#pragma once

#include "main.h"

class Props
{

  public:
    uint16_t drawableId;
    uint8_t textureId;

    Props(uint16_t drawable, uint8_t texture) : drawableId(drawable), textureId(texture)
    {
    }
    Props(alt::Prop prop) : drawableId(prop.drawableId), textureId(prop.textureId)
    {
    }

    alt::Prop toAlt() const
    {
        return alt::Prop{drawableId, textureId};
    }

    std::string toString() const
    {
        return "Prop(drawable: " + std::to_string(drawableId) + ", texture: " + std::to_string(textureId) + ")";
    }
};

void RegisterPropClass(const py::module_ &m);
