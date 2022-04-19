#pragma once
#include "main.hpp"

class Vector3 {
    double GetAngle(const Vector3& other, const bool& boolean);
public:
    double x, y, z;

    Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
    explicit Vector3(alt::Position position) : x{position[0]}, y{position[1]}, z{position[2]} {}
    explicit Vector3(alt::Rotation rotation) : x{rotation[0]}, y{rotation[1]}, z{rotation[2]} {}
    explicit Vector3(alt::Vector3f vector) : x{vector[0]}, y{vector[1]}, z{vector[2]} {}
    explicit Vector3(const py::list& vectorList) : x{vectorList[0].cast<float>()}, y{vectorList[1].cast<float>()}, z{vectorList[2].cast<float>()} {}

    py::dict ToDict();
    py::list ToList();

    alt::Position ToAltPos();
    alt::Rotation ToAltRot();
    std::string ToString();

    Vector3 ToDegrees();
    Vector3 ToRadians();

    double Length();
    double Distance(Vector3& other);
    bool IsInRange(const Vector3& other, double range);

    Vector3 Add(const Vector3& other);
    Vector3 Add(double num);
    Vector3 Add(double _x, double _y, double _z);
    Vector3 Add(const py::list& vectorList);

    Vector3 Cross(const Vector3& other);
    Vector3 Cross(double num);
    Vector3 Cross(double _x, double _y, double _z);
    Vector3 Cross(const py::list& vectorList);

    Vector3 Div(const Vector3& other);
    Vector3 Div(double num);
    Vector3 Div(double _x, double _y, double _z);
    Vector3 Div(const py::list& vectorList);

    double Dot(const Vector3& other);
    double Dot(double num);
    double Dot(double _x, double _y, double _z);
    double Dot(const py::list& vectorList);

    Vector3 Sub(const Vector3& other);
    Vector3 Sub(double num);
    Vector3 Sub(double _x, double _y, double _z);
    Vector3 Sub(const py::list& vectorList);

    Vector3 Mul(const Vector3& other);
    Vector3 Mul(double num);
    Vector3 Mul(double _x, double _y, double _z);
    Vector3 Mul(const py::list& vectorList);

    Vector3 Negative();
    Vector3 Normalize();

    static Vector3 Zero(const py::object& _this);
    static Vector3 One(const py::object& _this);
    static Vector3 Up(const py::object& _this);
    static Vector3 Down(const py::object& _this);
    static Vector3 Left(const py::object& _this);
    static Vector3 Right(const py::object& _this);
    static Vector3 Back(const py::object& _this);
    static Vector3 Forward(const py::object& _this);

    static Vector3 PositiveInfinity(const py::object& _this);
    static Vector3 NegativeInfinity(const py::object& _this);

    double AngleTo(const Vector3& other, const bool& boolean);
    double AngleToDegrees(const Vector3& other, const bool& boolean);
};