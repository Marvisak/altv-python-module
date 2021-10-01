#pragma once

#include "main.h"

class Vector2
        {
        private:
            double GetAngle(const Vector2& other, const bool& boolean) const
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
                }
                else {
                    return std::acos(cos) * (180 / alt::PI);
                }
            }

        public:
            double x, y;
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

            Vector2 ToDegrees() const
            {
                return Vector2(std::round(x * (180 / alt::PI)), std::round(y * (180 / alt::PI)));
            }

            Vector2 ToRadians() const
            {
                return Vector2(x * (alt::PI / 180), y * (alt::PI / 180));
            }

            double Length() const
            {
                return sqrt((x * x) + (y * y));
            }

            double Distance(Vector2& other) const
            {
                return sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
            }

            bool IsInRange(const Vector2& other, const double range) const
            {
                double dx = abs(x - other.x);
                double dy = abs(y - other.y);

                return dx <= range && dy <= range && dx * dx + dy * dy <= range * range;
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

            Vector2 Div(const Vector2& other)
            {
                return Vector2(x / other.x, y / other.y);
            }

            Vector2 Div(const double num)
            {
                return Vector2(x / num, y / num);
            }

            Vector2 Div(const double _x, const double _y)
            {
                return Vector2(x / _x, y / _y);
            }

            Vector2 Div(const py::list& vectorList)
            {
                return Vector2(x / vectorList[0].cast<double>(), y / vectorList[1].cast<double>());
            }

            double Dot(const Vector2& other)
            {
                return x * other.x + y * other.y;
            }

            double Dot(const double num)
            {
                return x * num + y * num;
            }

            double Dot(const double _x, const double _y)
            {
                return x * _x + y * _y;
            }

            double Dot(const py::list& vectorList)
            {
                return x * vectorList[0].cast<double>() + y * vectorList[1].cast<double>();
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

            Vector2 Negative() const
            {
                return Vector2(-x, -y);
            }

            Vector2 Normalize() const
            {
                double length = sqrt(x * x + y * y);
                return Vector2(x / length, y / length);
            }

            Vector2 zero() {
                return Vector2(0, 0);
            }

            Vector2 one() {
                return Vector2(1, 1);
            }

            Vector2 up() {
                return Vector2(0, 1);
            }

            Vector2 down() {
                return Vector2(0, -1);
            }

            Vector2 left() {
                return Vector2(-1, 0);
            }

            Vector2 right() {
                return Vector2(1, 0);
            }

            Vector2 positiveInfinity() {
                return Vector2(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity());
            }

            Vector2 negativeInfinty() {
                return Vector2(-std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity());
            }

            double AngleTo(const Vector2& other, const bool& boolean) const
            {
                return GetAngle(other, false);
            }

            double AngleToDegrees(const Vector2& other, const bool& boolean) const
            {
                return GetAngle(other, true);
            }
        };

void RegisterVector2Class(const pybind11::module_& m);
