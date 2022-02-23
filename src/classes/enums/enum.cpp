#include "enum.h"
#include <magic_enum.hpp>



template<typename E>
py::enum_<E> export_enum(const pybind11::handle& scope, const char* enumName)
{
	py::enum_<E> enum_type(scope, enumName);
	for (const auto& [value, name] : magic_enum::enum_entries<E>())
	{
		enum_type.value(name.data(), value);
	}
	return enum_type;
}

void RegisterEnums(const py::module_& m)
{
	export_enum<ExplosionType>(m, "ExplosionType");
	export_enum<BodyPart>(m, "BodyPart");
	export_enum<BlipType>(m, "BlipType");
	export_enum<ColShapeType>(m, "ColShapeType");
	export_enum<CheckpointType>(m, "CheckpointType");
	export_enum<RadioStation>(m, "RadioStation");
	export_enum<NumberPlateStyle>(m, "NumberPlateStyle");
	export_enum<VehicleBumper>(m, "VehicleBumper");
	export_enum<VehicleBumperDamage>(m, "VehicleBumperDamage");
	export_enum<VehicleDoor>(m, "VehicleDoor");
	export_enum<VehicleDoorState>(m, "VehicleDoorState");
	export_enum<VehicleLockState>(m, "VehicleLockState");
	export_enum<VehicleModType>(m, "VehicleModType");
	export_enum<VehiclePart>(m, "VehiclePart");
	export_enum<VehiclePartDamage>(m, "VehiclePartDamage");
	export_enum<WeatherType>(m, "WeatherType");
	export_enum<WindowTint>(m, "WindowTint");
	export_enum<alt::IBaseObject::Type>(m, "BaseObjectType");
}
