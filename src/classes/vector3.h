#pragma once
#include "main.h"

class Vector3
{
public:
    double x, y, z;
    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
    Vector3(alt::Position position) : x(position[0]), y(position[1]), z(position[2]) {}
    Vector3(alt::Rotation rotation) : x(rotation[0]), y(rotation[1]), z(rotation[2]) {}
    Vector3(alt::Vector3f vector) : x(vector[0]), y(vector[1]), z(vector[2]) {}

    py::dict ToDict();
    py::list ToList();


    alt::Position toAltPos() const {
        return alt::Position{x, y, z};
    }

    alt::Rotation toAltRot() const {
        return alt::Rotation{x, y, z};
    }

    std::string ToString() const
    {
        return "Vector3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    }

    Vector3 ToDegrees() const
    {
        return Vector3(x * (180 / alt::PI), y * (180 / alt::PI), z * (180 / alt::PI));
    }

    Vector3 ToRadians() const
    {
        return Vector3(x * (alt::PI / 180), y * (alt::PI / 180), z * (alt::PI / 180));
    }

    double Length() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    double Distance(Vector3& other) const
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
};

void RegisterVector3Class(const pybind11::module_& m);
