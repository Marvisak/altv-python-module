//
// Created by Marlon on 31/07/2021.
//

#pragma once

#include "main.h"

class DlcProps
{

  public:
    uint32_t dlc;
    uint8_t drawableId;
    uint8_t textureId;

    DlcProps(uint32_t dlc, uint8_t drawable, uint8_t texture) : dlc(dlc), drawableId(drawable), textureId(texture)
    {
    }
    DlcProps(alt::DlcProp dlcProp) : dlc(dlcProp.dlc), drawableId(dlcProp.drawableId), textureId(dlcProp.textureId)
    {
    }

    alt::DlcProp toAlt() const
    {
        return alt::DlcProp{dlc, drawableId, textureId};
    }

    std::string toString() const
    {
        return "DlcProp(dlc: " + std::to_string(dlc) + ", drawable: " + std::to_string(drawableId) + ", texture: " + std::to_string(textureId) + ")";
    }
};

void RegisterDlcPropClass(const py::module_ &m);
