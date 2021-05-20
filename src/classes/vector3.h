#pragma once
#include <main.h>

#include <utility>

const double PI = 3.141592653589793238463;

class Vector3
{
private:
public:
    double x, y, z;
    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
    py::dict ToDict();
    py::list ToList();

    std::string ToString()
    {
        return "Vector3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }

    double Length()
    {
        return sqrt(x * x + y * y + z * z);
    }

    double Distance(Vector3& other)
    {
        return sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2));
    }

    Vector3 Add(const Vector3& other)
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 Add(const double num)
    {
        return Vector3(x + num, y + num, z + num);
    }

    Vector3 Add(const double _x, const double _y, const double _z)
    {
        return Vector3(x + _x, y + _y, z + _z);
    }

    Vector3 Add(const py::list& vectorList)
    {
        return Vector3(x + vectorList[0].cast<double>(), y + vectorList[1].cast<double>(), z + vectorList[2].cast<double>());
    }

    Vector3 Sub(const Vector3& other)
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 Sub(const double num)
    {
        return Vector3(x - num, y - num, z - num);
    }

    Vector3 Sub(const double _x, const double _y, const double _z)
    {
        return Vector3(x - _x, y - _y, z - _z);
    }

    Vector3 Sub(const py::list& vectorList)
    {
        return Vector3(x - vectorList[0].cast<double>(), y - vectorList[1].cast<double>(), z - vectorList[2].cast<double>());
    }

    Vector3 Mul(const Vector3& other)
    {
        return Vector3(x * other.x, y * other.y, z * other.z);
    }

    Vector3 Mul(const double num)
    {
        return Vector3(x * num, y * num, z * num);
    }

    Vector3 Mul(const double _x, const double _y, const double _z)
    {
        return Vector3(x * _x, y * _y, z * _z);
    }

    Vector3 Mul(const py::list& vectorList)
    {
        return Vector3(x * vectorList[0].cast<double>(), y * vectorList[1].cast<double>(), z * vectorList[2].cast<double>());
    }


    static void RegisterVector3(pybind11::module_ m)
    {
        py::class_<Vector3>(std::move(m), "vector3")
            .def(py::init([](float _x, float _y, float _z) {return Vector3(_x, _y, _z);}))
            .def_readwrite("x", &Vector3::x)
            .def_readwrite("y", &Vector3::y)
            .def_readwrite("z", &Vector3::z)
            .def("__str__", &Vector3::ToString)

            .def("toDict", &Vector3::ToDict)
            .def("toList", &Vector3::ToList)
            .def("length", &Vector3::Length)
            .def("distance", &Vector3::Distance)

            .def("add", py::overload_cast<const double>(&Vector3::Add))
            .def("add", py::overload_cast<const py::list&>(&Vector3::Add))
            .def("add", py::overload_cast<const double, const double, const double>(&Vector3::Add))
            .def("add", py::overload_cast<const Vector3&>(&Vector3::Add))

            .def("sub", py::overload_cast<const double>(&Vector3::Sub))
            .def("sub", py::overload_cast<const py::list&>(&Vector3::Sub))
            .def("sub", py::overload_cast<const double, const double, const double>(&Vector3::Sub))
            .def("sub", py::overload_cast<const Vector3&>(&Vector3::Sub))

            .def("mul", py::overload_cast<const double>(&Vector3::Mul))
            .def("mul", py::overload_cast<const py::list&>(&Vector3::Mul))
            .def("mul", py::overload_cast<const double, const double, const double>(&Vector3::Mul))
            .def("mul", py::overload_cast<const Vector3&>(&Vector3::Mul));
    }

};
