#include "enum.h"
#include <magic_enum.hpp>

template <typename E>
py::enum_<E> export_enum(const pybind11::handle &scope, const char* enumName) {
    py::enum_<E> enum_type(scope, enumName);
    for (const auto &[value, name] : magic_enum::enum_entries<E>()) {
        enum_type.value(name.data(), value);
    }
    std::cout << "Enum Registered : " << enumName << std::endl;
    return enum_type;
}

void RegisterEnums(const py::module_& m) {
    export_enum<RadioStation>(m, "RadioStation");
    export_enum<alt::IBaseObject::Type>(m, "BaseObjectType");
}
