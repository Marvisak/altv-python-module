#pragma once
#include "main.h"

class Vector3
{
 private:
	double GetAngle(const Vector3& other, const bool& boolean) const
	{
		double xy = x * other.x + y * other.y;
		double posALength = sqrt(std::pow(x, 2) + std::pow(y, 2));
		double posBLength = sqrt(std::pow(other.x, 2) + std::pow(other.y, 2));

		if (posALength == 0 || posBLength == 0)
		{
			return -1;
		}

		double cos = xy / (posALength * posBLength);

		if (boolean) {
			return std::acos(cos);
		} else {
			return std::acos(cos) * (180 / alt::PI);
		}
	}
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
        return Vector3(std::round(x * (180 / alt::PI)), std::round(y * (180 / alt::PI)), std::round(z * (180 / alt::PI)));
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

    bool IsInRange(const Vector3& other, const double range) const
    {
    	double dx = abs(x - other.x);
    	double dy = abs(y - other.y);
    	double dz = abs(z - other.z);

    	return dx <= range && dy <= range && dz <= range && dx * dx + dy * dy + dz * dz <= range * range;;
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

    Vector3 Cross(const Vector3& other)
    {
    	return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }

    Vector3 Cross(const double num)
    {
    	return Vector3(y * num - z * num, z * num - x * num, x * num - y * num);
    }

    Vector3 Cross(const double _x, const double _y, const double _z)
    {
    	return Vector3(y * _z - z * _y, z * _x - x * _z, x * _y - y * _x);
    }

    Vector3 Cross(const py::list& vectorList)
    {
    	double _x = vectorList[0].cast<double>();
    	double _y = vectorList[1].cast<double>();
    	double _z = vectorList[2].cast<double>();

    	return Vector3(y * _z - z * _y, z * _x - x * _z, x * _y - y * _x);
    }

    Vector3 Div(const Vector3& other)
    {
    	return Vector3(x / other.x, y / other.y, z / other.z);
    }

    Vector3 Div(const double num)
    {
    	return Vector3(x / num, y / num, z / num);
    }

    Vector3 Div(const double _x, const double _y, const double _z)
    {
    	return Vector3(x / _x, y / _y, z / _z);
    }

    Vector3 Div(const py::list& vectorList)
    {
    	return Vector3(x / vectorList[0].cast<double>(), y / vectorList[1].cast<double>(), z / vectorList[2].cast<double>());
    }

    double Dot(const Vector3& other)
    {
    	return x * other.x + y * other.y + z * other.z;
    }

    double Dot(const double num)
    {
    	return x * num + y * num + z * num;
    }

    double Dot(const double _x, const double _y, const double _z)
    {
    	return x * _x + y * _y + z * _z;
    }

    double Dot(const py::list& vectorList)
    {
    	return x * vectorList[0].cast<double>() + y * vectorList[1].cast<double>(), z * vectorList[2].cast<double>();
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

    Vector3 Negative() const
    {
    	return Vector3(-x, -y, -z);
    }

    Vector3 Normalize() const
    {
    	double length = sqrt(x * x + y * y + z * z);
    	return Vector3(x / length, y / length, z / length);
    }

    Vector3 zeroVector() {
        return Vector3(0, 0, 0);
    }

    Vector3 oneVector() {
        return Vector3(1, 1, 1);
    }

    Vector3 upVector() {
        return Vector3(0, 1, 0);
    }

    Vector3 downVector() {
        return Vector3(0, -1, 0);
    }

    Vector3 leftVector() {
        return Vector3(-1, 0, 0);
    }

    Vector3 rightVector() {
        return Vector3(1, 0, 0);
    }

    Vector3 backVector() {
        return Vector3(0, 0, -1);
    }

    Vector3 forwardVector() {
        return Vector3(0, 0, 1);
    }

    double AngleTo(const Vector3& other, const bool& boolean) const
    {
    	return GetAngle(other, false);
    }

    double AngleToDegrees(const Vector3& other, const bool& boolean) const
    {
    	return GetAngle(other, true);
    }
};

void RegisterVector3Class(const pybind11::module_& m);
