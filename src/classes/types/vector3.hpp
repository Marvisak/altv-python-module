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

    alt::Position ToAltPos() const;
    alt::Rotation ToAltRot() const;
    std::string ToString() const;

    Vector3 ToDegrees() const;
    Vector3 ToRadians() const;

    double Length() const;
    double Distance(Vector3& other) const;
    bool IsInRange(const Vector3& other, double range) const;

	Vector3 operator+(const Vector3& other) const;
	Vector3 operator+(double num) const;
	Vector3 operator+(const py::list& vectorList) const;

	Vector3 operator-(const Vector3& other) const;
	Vector3 operator-(double num) const;
	Vector3 operator-(const py::list& vectorList) const;

	Vector3 operator/(const Vector3& other) const;
	Vector3 operator/(double num) const;
	Vector3 operator/(const py::list& vectorList) const;

	Vector3 operator*(const Vector3& other) const;
	Vector3 operator*(double num) const;
	Vector3 operator*(const py::list& vectorList) const;


	Vector3 Cross(const Vector3& other) const;
	Vector3 Cross(double num) const;
	Vector3 Cross(const py::list& vectorList) const;

	double Dot(const Vector3& other) const;
	double Dot(double num) const;
	double Dot(const py::list& vectorList) const;

    Vector3 Negative() const;
    Vector3 Normalize() const;

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