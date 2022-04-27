#include "classes/classes.hpp"
#include "classes/types/vector3.hpp"


Vector3 GetPosition(alt::IWorldObject* _this) {
    return Vector3(_this->GetPosition());
}

void SetPosition(alt::IWorldObject* _this, Vector3 pos) {
    _this->SetPosition(pos.ToAlt());
}

void RegisterWorldObjectClass(const py::module_& m) {
    auto pyClass = py::class_<alt::IWorldObject, alt::IBaseObject, alt::Ref<alt::IWorldObject>>(m, "WorldObject");

    pyClass.def_property("pos", &GetPosition, &SetPosition);
    pyClass.def_property("dimension", &alt::IWorldObject::GetDimension, &alt::IWorldObject::SetDimension);
}