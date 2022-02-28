#include "classes/classes.hpp"
#include "magic_enum.hpp"
#include "enums.hpp"

template<typename E>
void export_enum(const py::module_& m, const char* enumName)
{
    py::enum_<E> enum_type(m, enumName);
    for (const auto& [value, name] : magic_enum::enum_entries<E>())
    {
        enum_type.value(name.data(), value);
    }
}

void RegisterEnums(const py::module_& m) {
    export_enum<alt::IBaseObject::Type>(m, "BaseObjectType");
    export_enum<WeatherType>(m, "WeatherType");
    export_enum<WeaponTints>(m, "WeaponTints");
    export_enum<VehicleClasses>(m, "VehicleClasses");
}