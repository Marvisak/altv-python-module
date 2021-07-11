#pragma once
#include "main.h"

class Vector2
{
public:
    double x, y, z;
    Vector2(double x, double y) : x(x), y(y) {}
    Vector2(alt::Position position) : x(position[0]), y(position[1]) {}
    Vector2(alt::Rotation rotation) : x(rotation[0]), y(rotation[1]) {}
    Vector2(alt::Vector2f vector) : x(vector[0]), y(vector[1]) {}

    py::dict ToDict();
    py::list ToList();

    std::string ToString() const
    {
        return "Vector2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    double Length() const
    {
        return sqrt(x * x + y * y);
    }

    double Distance(Vector2& other) const
    {
        return sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    Vector2 Add(const Vector2& other)
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 Add(const double num)
    {
        return Vector2(x + num, y + num);
    }

    Vector2 Add(const double _x, const double _y)
    {
        return Vector2(x + _x, y + _y);
    }

    Vector2 Add(const py::list& vectorList)
    {
        return Vector2(x + vectorList[0].cast<double>(), y + vectorList[1].cast<double>());
    }

    Vector2 Sub(const Vector2& other)
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 Sub(const double num)
    {
        return Vector2(x - num, y - num);
    }

    Vector2 Sub(const double _x, const double _y)
    {
        return Vector2(x - _x, y - _y);
    }

    Vector2 Sub(const py::list& vectorList)
    {
        return Vector2(x - vectorList[0].cast<double>(), y - vectorList[1].cast<double>());
    }

    Vector2 Mul(const Vector2& other)
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 Mul(const double num)
    {
        return Vector2(x * num, y * num);
    }

    Vector2 Mul(const double _x, const double _y)
    {
        return Vector2(x * _x, y * _y);
    }

    Vector2 Mul(const py::list& vectorList)
    {
        return Vector2(x * vectorList[0].cast<double>(), y * vectorList[1].cast<double>());
    }
};

void RegisterVector2Class(const pybind11::module_& m);
