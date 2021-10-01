#include "baseobject.h"

void RegisterBaseObjectClass(const py::module_ &m)
{
    auto pyClass = py::class_<BaseObject>(m, "BaseObject");
    pyClass.def_property_readonly("type", &BaseObject::GetType);
    pyClass.def_property_readonly("valid", &BaseObject::IsValid);
    pyClass.def("deleteMeta", &BaseObject::DeleteMeta);
    pyClass.def("getMeta", &BaseObject::GetMeta);
    pyClass.def("hasMeta", &BaseObject::HasMeta);
    pyClass.def("setMeta", &BaseObject::SetMeta);
    pyClass.def("destroy", &BaseObject::Destroy);
}
