#include <classes/vector3.h>

py::dict Vector3::toDict() {
    py::dict dict;
    dict["x"] = x;
    dict["y"] = y;
    dict["z"] = z;
    return dict;
}

py::list Vector3::toList()
{
    py::list list;
    list.append(x);
    list.append(y);
    list.append(z);
    return list;
}