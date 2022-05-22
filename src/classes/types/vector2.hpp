#pragma once
#include "main.hpp"

class Vector2 {
    double GetAngle(const Vector2& other, const bool& degrees) const;
public:
    double x, y;

    Vector2(double x, double y) : x(x), y(y) {}
    explicit Vector2(alt::Position position) : x{position[0]}, y{position[1]} {}
    explicit Vector2(alt::Rotation rotation) : x{rotation[0]}, y{rotation[1]} {}
    explicit Vector2(alt::Vector2f vector) : x{vector[0]}, y{vector[1]} {}
    explicit Vector2(const py::list& vectorList) : x{vectorList[0].cast<float>()}, y{vectorList[1].cast<float>()} {}

    py::dict ToDict();
    py::list ToList();

    alt::Position ToAlt() const;
    std::string ToString() const;

    Vector2 ToDegrees() const;
    Vector2 ToRadians() const;

    double Length() const;
    double Distance(Vector2& other) const;
	double DistanceSquared(Vector2& other) const;
    bool IsInRange(const Vector2& other, double range) const;
	Vector2 Lerp(Vector2 other, double ratio) const;

    Vector2 operator+(const Vector2& other) const;
	Vector2 operator+(double num) const;
	Vector2 operator+(const py::list& vectorList) const;

	Vector2 operator-(const Vector2& other) const;
	Vector2 operator-(double num) const;
	Vector2 operator-(const py::list& vectorList) const;
    Vector2 operator-() const;

	Vector2 operator/(const Vector2& other) const;
	Vector2 operator/(double num) const;
	Vector2 operator/(const py::list& vectorList) const;

	Vector2 operator*(const Vector2& other) const;
	Vector2 operator*(double num) const;
	Vector2 operator*(const py::list& vectorList) const;

	bool operator==(const Vector2& other) const;

	double Dot(const Vector2& other) const;
	double Dot(double num) const;
	double Dot(const py::list& vectorList) const;

    Vector2 Normalize() const;

    static Vector2 Zero(const py::object& _this);
    static Vector2 One(const py::object& _this);
    static Vector2 Up(const py::object& _this);
    static Vector2 Down(const py::object& _this);
    static Vector2 Left(const py::object& _this);
    static Vector2 Right(const py::object& _this);

    static Vector2 PositiveInfinity(const py::object& _this);
    static Vector2 NegativeInfinity(const py::object& _this);

    double AngleTo(const Vector2& other);
    double AngleToDegrees(const Vector2& other);
};
