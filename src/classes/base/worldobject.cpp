#include "worldobject.h"

void RegisterWorldObjectClass(const py::module_ &m)
{
    auto pyClass = py::class_<WorldObject, BaseObject>(m, "WorldObject");
    pyClass.def_property("pos", &WorldObject::GetPosition, &WorldObject::SetPosition);
    pyClass.def_property("dimension", &WorldObject::GetDimension, &WorldObject::SetDimension);
}
