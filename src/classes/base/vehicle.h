#pragma once

#include "classes/enums/enum.h"
#include "classes/rgba.h"
#include "classes/vector3.h"
#include "entity.h"
#include "main.h"

class Vehicle : public Entity
{
  private:
    alt::Ref<alt::IVehicle> vehicle;

  public:
    static alt::Ref<alt::IVehicle> SpawnVehicle(uint32_t modelHash, double x, double y, double z, double rx, double ry, double rz)
    {
        return Core->CreateVehicle(modelHash, alt::Position(x, y, z), alt::Rotation(rx, ry, rz));
    }

    alt::Ref<alt::IVehicle> GetBaseObject()
    {
        return vehicle;
    }

    Vehicle(alt::Ref<alt::IVehicle> vehicle) : vehicle(vehicle), Entity(vehicle)
    {
    }

    static py::list GetAllVehicles(const py::object &self)
    {
        auto vehicles = Core->GetVehicles();
        py::list pyList;
        for (const auto &vehicle : vehicles)
        {
            pyList.append(py::cast(Vehicle(vehicle)));
        }
        return pyList;
    }

    // Getter
    bool IsDestroyed()
    {
        return vehicle->IsDestroyed();
    }
    uint8_t GetMod(uint8_t category)
    {
        return vehicle->GetMod(category);
    }
    uint8_t GetModsCount(uint8_t category)
    {
        return vehicle->GetModsCount(category);
    }
    uint8_t GetModKitsCount()
    {
        return vehicle->GetModKitsCount();
    }
    uint8_t GetModKit()
    {
        return vehicle->GetModKit();
    }
    bool IsPrimaryColorRGB()
    {
        return vehicle->IsPrimaryColorRGB();
    }
    uint8_t GetPrimaryColor()
    {
        return vehicle->GetPrimaryColor();
    }
    RGBA GetPrimaryColorRGB()
    {
        return vehicle->GetPrimaryColorRGB();
    }
    bool IsSecondaryColorRGB()
    {
        return vehicle->IsSecondaryColorRGB();
    }
    uint8_t GetSecondaryColor()
    {
        return vehicle->GetSecondaryColor();
    }
    RGBA GetSecondaryColorRGB()
    {
        return vehicle->GetSecondaryColorRGB();
    }
    uint8_t GetPearlColor()
    {
        return vehicle->GetPearlColor();
    }
    uint8_t GetWheelColor()
    {
        return vehicle->GetWheelColor();
    }
    uint8_t GetInteriorColor()
    {
        return vehicle->GetInteriorColor();
    }
    uint8_t GetDashboardColor()
    {
        return vehicle->GetDashboardColor();
    }
    bool IsTireSmokeColorCustom()
    {
        return vehicle->IsTireSmokeColorCustom();
    }
    RGBA GetTireSmokeColor()
    {
        return vehicle->GetTireSmokeColor();
    }

    Vector3 GetVelocity()
    {
        return vehicle->IsTireSmokeColorCustom();
    }

    uint8_t GetWheelType()
    {
        return vehicle->GetWheelType();
    }
    uint8_t GetWheelVariation()
    {
        return vehicle->GetWheelVariation();
    }
    uint8_t GetRearWheelVariation()
    {
        return vehicle->GetRearWheelVariation();
    }
    bool GetCustomTires()
    {
        return vehicle->GetCustomTires();
    }
    uint8_t GetSpecialDarkness()
    {
        return vehicle->GetSpecialDarkness();
    }
    uint32_t GetNumberplateIndex()
    {
        return vehicle->GetNumberplateIndex();
    }
    std::string GetNumberplateText()
    {
        return vehicle->GetNumberplateText().ToString();
    }
    uint8_t GetWindowTint()
    {
        return vehicle->GetWindowTint();
    }
    uint8_t GetDirtLevel()
    {
        return vehicle->GetDirtLevel();
    }
    bool IsExtraOn(uint8_t extraID)
    {
        return vehicle->IsExtraOn(extraID);
    }
    bool IsNeonActive()
    {
        return vehicle->IsNeonActive();
    }
    void GetNeonActive(bool *left, bool *right, bool *front, bool *back)
    {
        return vehicle->GetNeonActive(left, right, front, back);
    }
    RGBA GetNeonColor()
    {
        return vehicle->GetNeonColor();
    }
    uint8_t GetLivery()
    {
        return vehicle->GetLivery();
    }
    uint8_t GetRoofLivery()
    {
        return vehicle->GetRoofLivery();
    }
    std::string GetAppearanceDataBase64()
    {
        return vehicle->GetAppearanceDataBase64().ToString();
    }
    bool IsEngineOn()
    {
        return vehicle->IsEngineOn();
    }
    bool IsHandbrakeActive()
    {
        return vehicle->IsHandbrakeActive();
    }
    uint8_t GetHeadlightColor()
    {
        return vehicle->GetHeadlightColor();
    }
    RadioStation GetRadioStationIndex()
    {
        return static_cast<RadioStation>(vehicle->GetRadioStationIndex());
    }
    bool IsSirenActive()
    {
        return vehicle->IsSirenActive();
    }
    // TODO document available values. Enum?
    uint8_t GetLockState()
    {
        return vehicle->GetLockState();
    }
    // TODO document available values. Enum?
    uint8_t GetDoorState(uint8_t doorId)
    {
        return vehicle->GetDoorState(doorId);
    }
    bool IsWindowOpened(uint8_t windowId)
    {
        return vehicle->IsWindowOpened(windowId);
    }
    bool IsDaylightOn()
    {
        return vehicle->IsDaylightOn();
    }
    bool IsNightlightOn()
    {
        return vehicle->IsNightlightOn();
    }
    uint8_t GetRoofState()
    {
        return vehicle->GetRoofState();
    }
    bool IsFlamethrowerActive()
    {
        return vehicle->IsFlamethrowerActive();
    }
    float GetLightsMultiplier()
    {
        return vehicle->GetLightsMultiplier();
    }
    std::string GetGameStateBase64()
    {
        return vehicle->GetGameStateBase64().ToString();
    }
    int32_t GetEngineHealth()
    {
        return vehicle->GetEngineHealth();
    }
    int32_t GetPetrolTankHealth()
    {
        return vehicle->GetPetrolTankHealth();
    }
    uint8_t GetWheelsCount()
    {
        return vehicle->GetWheelsCount();
    }
    bool IsWheelBurst(uint8_t wheelId)
    {
        return vehicle->IsWheelBurst(wheelId);
    }
    bool DoesWheelHasTire(uint8_t wheelId)
    {
        return vehicle->DoesWheelHasTire(wheelId);
    }
    bool IsWheelDetached(uint8_t wheelId)
    {
        return vehicle->IsWheelDetached(wheelId);
    }
    bool IsWheelOnFire(uint8_t wheelId)
    {
        return vehicle->IsWheelOnFire(wheelId);
    }
    float GetWheelHealth(uint8_t wheelId)
    {
        return vehicle->GetWheelHealth(wheelId);
    }
    uint8_t GetRepairsCount()
    {
        return vehicle->GetRepairsCount();
    }
    uint32_t GetBodyHealth()
    {
        return vehicle->GetBodyHealth();
    }
    uint32_t GetBodyAdditionalHealth()
    {
        return vehicle->GetBodyAdditionalHealth();
    }
    std::string GetHealthDataBase64()
    {
        return vehicle->GetHealthDataBase64().ToString();
    }
    uint8_t GetPartDamageLevel(uint8_t partId)
    {
        return vehicle->GetPartDamageLevel(partId);
    }
    uint8_t GetPartBulletHoles(uint8_t partId)
    {
        return vehicle->GetPartBulletHoles(partId);
    }
    bool IsLightDamaged(uint8_t lightId)
    {
        return vehicle->IsLightDamaged(lightId);
    }
    bool IsWindowDamaged(uint8_t windowId)
    {
        return vehicle->IsWindowDamaged(windowId);
    }
    bool IsSpecialLightDamaged(uint8_t specialLightId)
    {
        return vehicle->IsSpecialLightDamaged(specialLightId);
    }
    bool HasArmoredWindows()
    {
        return vehicle->HasArmoredWindows();
    }
    float GetArmoredWindowHealth(uint8_t windowId)
    {
        return vehicle->GetArmoredWindowHealth(windowId);
    }
    uint8_t GetArmoredWindowShootCount(uint8_t windowId)
    {
        return vehicle->GetArmoredWindowShootCount(windowId);
    }
    uint8_t GetBumperDamageLevel(uint8_t bumperId)
    {
        return vehicle->GetBumperDamageLevel(bumperId);
    }
    std::string GetDamageDataBase64()
    {
        return vehicle->GetDamageDataBase64().ToString();
    }
    bool IsManualEngineControl()
    {
        return vehicle->IsManualEngineControl();
    }
    std::string GetScriptDataBase64()
    {
        return vehicle->GetScriptDataBase64().ToString();
    }

    Player GetDriver();
    Vehicle GetAttached()
    {
        return vehicle->GetAttached();
    }
    Vehicle GetAttachedTo()
    {
        return vehicle->GetAttachedTo();
    }

    // Setter
    void ToggleExtra(uint8_t extraID, bool state)
    {
        vehicle->ToggleExtra(extraID, state);
    }
    void SetFixed()
    {
        vehicle->SetFixed();
    }
    bool SetMod(uint8_t category, uint8_t id)
    {
        return vehicle->SetMod(category, id);
    }
    bool SetModKit(uint8_t id)
    {
        return vehicle->SetModKit(id);
    }
    void SetPrimaryColor(uint8_t color)
    {
        vehicle->SetPrimaryColor(color);
    }
    void SetPrimaryColorRGB(RGBA color)
    {
        vehicle->SetPrimaryColorRGB(color.toAlt());
    }
    void SetSecondaryColor(uint8_t color)
    {
        vehicle->SetSecondaryColor(color);
    }
    void SetSecondaryColorRGB(RGBA color)
    {
        vehicle->SetSecondaryColorRGB(color.toAlt());
    }
    void SetPearlColor(uint8_t color)
    {
        vehicle->SetPearlColor(color);
    }
    void SetWheelColor(uint8_t color)
    {
        vehicle->SetWheelColor(color);
    }
    void SetInteriorColor(uint8_t color)
    {
        vehicle->SetInteriorColor(color);
    }
    void SetDashboardColor(uint8_t color)
    {
        vehicle->SetDashboardColor(color);
    }
    void SetTireSmokeColor(RGBA color)
    {
        vehicle->SetTireSmokeColor(color.toAlt());
    }
    void SetWheels(uint8_t type, uint8_t variation)
    {
        vehicle->SetWheels(type, variation);
    }
    void SetRearWheels(uint8_t variation)
    {
        vehicle->SetRearWheels(variation);
    }
    void SetCustomTires(bool state)
    {
        vehicle->SetCustomTires(state);
    }
    void SetSpecialDarkness(uint8_t value)
    {
        vehicle->SetSpecialDarkness(value);
    }
    void SetNumberplateIndex(uint32_t index)
    {
        vehicle->SetNumberplateIndex(index);
    }
    void SetNumberplateText(const std::string &text)
    {
        vehicle->SetNumberplateText(text);
    }
    void SetWindowTint(uint8_t tint)
    {
        vehicle->SetWindowTint(tint);
    }
    void SetDirtLevel(uint8_t level)
    {
        vehicle->SetDirtLevel(level);
    }
    void SetNeonActive(bool left, bool right, bool front, bool back)
    {
        vehicle->SetNeonActive(left, right, front, back);
    }
    void SetNeonColor(RGBA color)
    {
        vehicle->SetNeonColor(color.toAlt());
    }
    void SetLivery(uint8_t livery)
    {
        vehicle->SetLivery(livery);
    }
    void SetRoofLivery(uint8_t roofLivery)
    {
        vehicle->SetRoofLivery(roofLivery);
    }
    void LoadAppearanceDataFromBase64(const std::string &base64)
    {
        vehicle->LoadAppearanceDataFromBase64(alt::StringView(base64));
    }
    void SetEngineOn(bool state)
    {
        vehicle->SetEngineOn(state);
    }
    void SetHeadlightColor(uint8_t color)
    {
        vehicle->SetHeadlightColor(color);
    }
    void SetRadioStationIndex(uint32_t stationIndex)
    {
        vehicle->SetRadioStationIndex(stationIndex);
    }
    void SetSirenActive(bool state)
    {
        vehicle->SetSirenActive(state);
    }
    void SetLockState(uint8_t state)
    {
        vehicle->SetLockState(state);
    }
    void SetDoorState(uint8_t doorId, uint8_t state)
    {
        vehicle->SetDoorState(doorId, state);
    }
    void SetWindowOpened(uint8_t windowId, bool state)
    {
        vehicle->SetWindowOpened(windowId, state);
    }
    void SetRoofState(uint8_t state)
    {
        vehicle->SetRoofState(state);
    }
    void SetLightsMultiplier(float multiplier)
    {
        vehicle->SetLightsMultiplier(multiplier);
    }
    void SetEngineHealth(int32_t health)
    {
        vehicle->SetEngineHealth(health);
    }
    void SetPetrolTankHealth(int32_t health)
    {
        vehicle->SetPetrolTankHealth(health);
    }
    void SetWheelBurst(uint8_t wheelId, bool state)
    {
        vehicle->SetWheelBurst(wheelId, state);
    }
    void SetWheelHasTire(uint8_t wheelId, bool state)
    {
        vehicle->SetWheelHasTire(wheelId, state);
    }
    void SetWheelDetached(uint8_t wheelId, bool state)
    {
        vehicle->SetWheelDetached(wheelId, state);
    }
    void SetWheelOnFire(uint8_t wheelId, bool state)
    {
        vehicle->SetWheelOnFire(wheelId, state);
    }
    void SetWheelHealth(uint8_t wheelId, float health)
    {
        vehicle->SetWheelHealth(wheelId, health);
    }
    void SetWheelFixed(uint8_t wheelId)
    {
        vehicle->SetWheelFixed(wheelId);
    }
    void SetBodyHealth(uint32_t health)
    {
        vehicle->SetBodyHealth(health);
    }
    void SetBodyAdditionalHealth(uint32_t health)
    {
        vehicle->SetBodyAdditionalHealth(health);
    }
    void SetPartDamageLevel(uint8_t partId, uint8_t damage)
    {
        vehicle->SetPartDamageLevel(partId, damage);
    }
    void SetPartBulletHoles(uint8_t partId, uint8_t shootsCount)
    {
        vehicle->SetPartBulletHoles(partId, shootsCount);
    }
    void SetLightDamaged(uint8_t lightId, bool isDamaged)
    {
        vehicle->SetLightDamaged(lightId, isDamaged);
    }
    void SetWindowDamaged(uint8_t windowId, bool isDamaged)
    {
        vehicle->SetWindowDamaged(windowId, isDamaged);
    }
    void SetSpecialLightDamaged(uint8_t specialLightId, bool isDamaged)
    {
        vehicle->SetSpecialLightDamaged(specialLightId, isDamaged);
    }
    void SetArmoredWindowHealth(uint8_t windowId, float health)
    {
        vehicle->SetArmoredWindowHealth(windowId, health);
    }
    void SetArmoredWindowShootCount(uint8_t windowId, uint8_t count)
    {
        vehicle->SetArmoredWindowShootCount(windowId, count);
    }
    void SetBumperDamageLevel(uint8_t bumperId, uint8_t damageLevel)
    {
        vehicle->SetBumperDamageLevel(bumperId, damageLevel);
    }
    void SetManualEngineControl(bool state)
    {
        vehicle->SetManualEngineControl(state);
    }
    void LoadDamageDataFromBase64(const std::string &base64)
    {
        vehicle->LoadDamageDataFromBase64(alt::StringView(base64));
    }
    void LoadScriptDataFromBase64(const std::string &base64)
    {
        vehicle->LoadScriptDataFromBase64(alt::StringView(base64));
    }
    void LoadGameStateFromBase64(const std::string &base64)
    {
        vehicle->LoadGameStateFromBase64(alt::StringView(base64));
    }
    void LoadHealthDataFromBase64(const std::string &base64)
    {
        vehicle->LoadHealthDataFromBase64(alt::StringView(base64));
    }
};

void RegisterVehicleClass(const py::module_ &m);
