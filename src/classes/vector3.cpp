#include "classes/vector3.h"

py::dict Vector3::ToDict() {
    py::dict dict;
    dict["x"] = x;
    dict["y"] = y;
    dict["z"] = z;
    return dict;
}

py::list Vector3::ToList()
{
    py::list list;
    list.append(x);
    list.append(y);
    list.append(z);
    return list;
}

void RegisterVector3Class(const pybind11::module_& m) {
    auto pyClass = py::class_<Vector3>(m, "Vector3");
    pyClass.def(py::init([](float _x, float _y, float _z) {return Vector3(_x, _y, _z);}));
    pyClass.def_readwrite("x", &Vector3::x);
    pyClass.def_readwrite("y", &Vector3::y);
    pyClass.def_readwrite("z", &Vector3::z);
    pyClass.def("__str__", &Vector3::ToString);

    pyClass.def("toDict", &Vector3::ToDict);
    pyClass.def("toList", &Vector3::ToList);
    pyClass.def("length", &Vector3::Length);
    pyClass.def("distance", &Vector3::Distance);

    pyClass.def("add", py::overload_cast<const double>(&Vector3::Add));
    pyClass.def("add", py::overload_cast<const py::list&>(&Vector3::Add));
    pyClass.def("add", py::overload_cast<const double, const double, const double>(&Vector3::Add));
    pyClass.def("add", py::overload_cast<const Vector3&>(&Vector3::Add));

    pyClass.def("sub", py::overload_cast<const double>(&Vector3::Sub));
    pyClass.def("sub", py::overload_cast<const py::list&>(&Vector3::Sub));
    pyClass.def("sub", py::overload_cast<const double, const double, const double>(&Vector3::Sub));
    pyClass.def("sub", py::overload_cast<const Vector3&>(&Vector3::Sub));

    pyClass.def("mul", py::overload_cast<const double>(&Vector3::Mul));
    pyClass.def("mul", py::overload_cast<const py::list&>(&Vector3::Mul));
    pyClass.def("mul", py::overload_cast<const double, const double, const double>(&Vector3::Mul));
    pyClass.def("mul", py::overload_cast<const Vector3&>(&Vector3::Mul));
}
