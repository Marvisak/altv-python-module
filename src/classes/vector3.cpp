#include <classes/vector3.h>

py::dict Vector3::toDict() {
    py::dict dict;
    dict["x"], dict["y"], dict["z"] = x, y, z;
    return dict;
}