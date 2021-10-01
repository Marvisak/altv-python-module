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

    pyClass.def("toDegrees", &Vector3::ToDegrees);
    pyClass.def("toRadians", &Vector3::ToRadians);
    pyClass.def("isInRange", &Vector3::IsInRange);

    pyClass.def("add", py::overload_cast<const double>(&Vector3::Add));
    pyClass.def("add", py::overload_cast<const py::list&>(&Vector3::Add));
    pyClass.def("add", py::overload_cast<const double, const double, const double>(&Vector3::Add));
    pyClass.def("add", py::overload_cast<const Vector3&>(&Vector3::Add));

    pyClass.def("cross", py::overload_cast<const double>(&Vector3::Cross));
    pyClass.def("cross", py::overload_cast<const py::list&>(&Vector3::Cross));
    pyClass.def("cross", py::overload_cast<const double, const double, const double>(&Vector3::Cross));
    pyClass.def("cross", py::overload_cast<const Vector3&>(&Vector3::Cross));

    pyClass.def("div", py::overload_cast<const double>(&Vector3::Div));
    pyClass.def("div", py::overload_cast<const py::list&>(&Vector3::Div));
    pyClass.def("div", py::overload_cast<const double, const double, const double>(&Vector3::Div));
    pyClass.def("div", py::overload_cast<const Vector3&>(&Vector3::Div));

    pyClass.def("dot", py::overload_cast<const double>(&Vector3::Dot));
    pyClass.def("dot", py::overload_cast<const py::list&>(&Vector3::Dot));
    pyClass.def("dot", py::overload_cast<const double, const double, const double>(&Vector3::Dot));
    pyClass.def("dot", py::overload_cast<const Vector3&>(&Vector3::Dot));

    pyClass.def("sub", py::overload_cast<const double>(&Vector3::Sub));
    pyClass.def("sub", py::overload_cast<const py::list&>(&Vector3::Sub));
    pyClass.def("sub", py::overload_cast<const double, const double, const double>(&Vector3::Sub));
    pyClass.def("sub", py::overload_cast<const Vector3&>(&Vector3::Sub));

    pyClass.def("mul", py::overload_cast<const double>(&Vector3::Mul));
    pyClass.def("mul", py::overload_cast<const py::list&>(&Vector3::Mul));
    pyClass.def("mul", py::overload_cast<const double, const double, const double>(&Vector3::Mul));
    pyClass.def("mul", py::overload_cast<const Vector3&>(&Vector3::Mul));

    pyClass.def_property_readonly("zero", &Vector3::zero);
    pyClass.def_property_readonly("one", &Vector3::one);
    pyClass.def_property_readonly("up", &Vector3::up);
    pyClass.def_property_readonly("down", &Vector3::down);
    pyClass.def_property_readonly("left", &Vector3::left);
    pyClass.def_property_readonly("right", &Vector3::right);
    pyClass.def_property_readonly("back", &Vector3::back);
    pyClass.def_property_readonly("forward", &Vector3::forward);

    pyClass.def_property_readonly("postiveInfinity", &Vector3::positiveInfinity);
    pyClass.def_property_readonly("negativeInfinity", &Vector3::negativeInfinty);

    pyClass.def("negative", &Vector3::Negative);
    pyClass.def("normalize", &Vector3::Normalize);
    pyClass.def("angleTo", &Vector3::AngleTo);
    pyClass.def("angleToDegrees", &Vector3::AngleToDegrees);
}
