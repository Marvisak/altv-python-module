#include "enums.hpp"
#include "classes/classes.hpp"
#include "magic_enum.hpp"

template<typename E>
void export_enum(const py::module_& m, const char* enumName)
{
	py::enum_<E> enum_type(m, enumName);
	for (const auto& [value, name] : magic_enum::enum_entries<E>())
	{
		enum_type.value(name.data(), value);
	}
}

void RegisterEnums(const py::module_& m)
{
	export_enum<BaseObjectType>(m, "BaseObjectType");
	export_enum<WeatherType>(m, "WeatherType");
	export_enum<WeaponTint>(m, "WeaponTint");
	export_enum<VehicleModType>(m, "VehicleModType");
	export_enum<WindowTint>(m, "WindowTint");
	export_enum<RadioStation>(m, "RadioStation");
	export_enum<VehicleLockState>(m, "VehicleLockState");
	export_enum<VehicleDoorState>(m, "VehicleDoorState");
	export_enum<VehicleDoor>(m, "VehicleDoor");
	export_enum<VehiclePart>(m, "VehiclePart");
	export_enum<VehiclePartDamage>(m, "VehiclePartDamage");
	export_enum<VehicleBumper>(m, "VehicleBumper");
	export_enum<VehicleBumperDamage>(m, "VehicleBumperDamage");
	export_enum<NumberPlateStyle>(m, "NumberPlateStyle");
	export_enum<Event>(m, "Event");
	export_enum<ExplosionType>(m, "ExplosionType");
	export_enum<BodyPart>(m, "BodyPart");
	export_enum<VehicleType>(m, "VehicleType");
	export_enum<ColShapeType>(m, "ColShapeType");
	export_enum<BlipColor>(m, "BlipColor");
	export_enum<BlipSprite>(m, "BlipSprite");
	export_enum<CheckpointType>(m, "CheckpointType");
	export_enum<ConnectDeniedReason>(m, "ConnectDeniedReason");
}
