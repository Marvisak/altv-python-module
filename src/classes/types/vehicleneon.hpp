#pragma once
#include "main.hpp"

struct VehicleNeon {
    bool left, right, front, back;
    VehicleNeon(bool left, bool right, bool front, bool back) : left{left}, right{right}, front{front}, back{back} {}
    std::string ToString();
};
