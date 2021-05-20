#pragma once
#include <main.h>

class Vector3
{
private:
public:
    float x, y, z;
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    py::dict toDict();
};