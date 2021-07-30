#include "classes/vector2.h"

py::dict Vector2::ToDict() {
    py::dict dict;
    dict["x"] = x;
    dict["y"] = y;
    return dict;
}

py::list Vector2::ToList()
{
    py::list list;
    list.append(x);
    list.append(y);
    return list;
}

void RegisterVector2Class(const pybind11::module_& m) {
    auto pyClass = py::class_<Vector2>(m, "Vector2");
    pyClass.def(py::init([](float _x, float _y) {return Vector2(_x, _y);}));
    pyClass.def_readwrite("x", &Vector2::x);
    pyClass.def_readwrite("y", &Vector2::y);
    pyClass.def("__str__", &Vector2::ToString);

    pyClass.def("toDict", &Vector2::ToDict);
    pyClass.def("toList", &Vector2::ToList);
    pyClass.def("length", &Vector2::Length);
    pyClass.def("distance", &Vector2::Distance);

    pyClass.def("toDegrees", &Vector2::ToDegrees);
    pyClass.def("toRadians", &Vector2::ToRadians);

    pyClass.def("add", py::overload_cast<const double>(&Vector2::Add));
    pyClass.def("add", py::overload_cast<const py::list&>(&Vector2::Add));
    pyClass.def("add", py::overload_cast<const double, const double>(&Vector2::Add));
    pyClass.def("add", py::overload_cast<const Vector2&>(&Vector2::Add));

    pyClass.def("sub", py::overload_cast<const double>(&Vector2::Sub));
    pyClass.def("sub", py::overload_cast<const py::list&>(&Vector2::Sub));
    pyClass.def("sub", py::overload_cast<const double, const double>(&Vector2::Sub));
    pyClass.def("sub", py::overload_cast<const Vector2&>(&Vector2::Sub));

    pyClass.def("mul", py::overload_cast<const double>(&Vector2::Mul));
    pyClass.def("mul", py::overload_cast<const py::list&>(&Vector2::Mul));
    pyClass.def("mul", py::overload_cast<const double, const double>(&Vector2::Mul));
    pyClass.def("mul", py::overload_cast<const Vector2&>(&Vector2::Mul));
}
