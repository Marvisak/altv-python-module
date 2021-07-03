#pragma once

#include "main.h"

enum RadioStation {
    RadioOff = 1,
    LosSantosRockRadio,
    NonStopPopFm,
    RadioLosSantos,
    ChannelX,
    WestCoastTalkRadio,
    RebelRadio,
    SoulwaxFm,
    EastLosFm,
    WestCoastClassics,
    TheMusicLocker,
    TheBlueArk,
    WorldWideFm,
    FlyloFm,
    TheLowdown,
    TheLab,
    RadioMirrorPark,
    KultFM,
    Space,
    VinewoodBoulevardRadio,
    BlondedLosSantosFM,
    LosSantosUndergroundRadio,
    IFruitRadio,
    SelfRadio
};

void RegisterEnums(const py::module_& m);