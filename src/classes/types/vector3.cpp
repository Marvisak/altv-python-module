#include "classes/classes.hpp"
#include "vector3.hpp"

double Vector3::GetAngle(const Vector3 &other, const bool& degrees) const {
    double xy = x * other.x + y * other.y;
    double posALength = sqrt(std::pow(x, 2) + std::pow(y, 2));
    double posBLength = sqrt(std::pow(other.x, 2) + std::pow(other.y, 2));

    if (posALength == 0 || posBLength == 0) {
        return -1;
    }

    double cos = xy / (posALength * posBLength);

    if (degrees)
        return std::acos(cos);
    else
        return std::acos(cos) * (180 / alt::PI);
}


py::dict Vector3::ToDict() {
    py::dict dict;
    dict["x"] = x;
    dict["y"] = y;
    dict["z"] = z;
    return dict;
}

py::list Vector3::ToList() {
    py::list list;
    list.append(x);
    list.append(y);
    list.append(z);
    return list;
}

alt::Position Vector3::ToAlt() const {
    return alt::Position{x, y, z};
}

std::string Vector3::ToString() const {
    return "Vector3(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
}

Vector3 Vector3::ToDegrees() const {
    return {x * (180 / alt::PI), y * (180 / alt::PI), z * (180 / alt::PI)};
}

Vector3 Vector3::ToRadians() const {
    return {x * (alt::PI / 180), y * (alt::PI / 180), z * (alt::PI / 180)};
}

double Vector3::Length() const {
    return sqrt(x * x + y * y + z * z);
}

double Vector3::Distance(Vector3& other) const {
	return sqrt(DistanceSquared(other));
}

double Vector3::DistanceSquared(Vector3& other) const {
	return std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2);
}

bool Vector3::IsInRange(const Vector3 &other, double range) const {
    double dx = abs(x - other.x);
    double dy = abs(y - other.y);
    double dz = abs(z - other.z);

    return dx <= range && dy <= range && dz <= range && dx * dx + dy * dy + dz * dz <= range * range;
}

Vector3 Vector3::Lerp(Vector3 other, double ratio) const {
	double x1 = x + (other.x - x) * ratio;
	double y1 = y + (other.y - y) * ratio;
	double z1 = z + (other.z - z) * ratio;
	return {x1, y1, z1};
}

Vector3 Vector3::operator+(const Vector3 &other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Vector3 Vector3::operator+(double num) const {
    return {x + num, y + num, z + num};
}

Vector3 Vector3::operator+(const py::list &vectorList) const {
    return {x + vectorList[0].cast<double>(), y + vectorList[1].cast<double>(), z + vectorList[2].cast<double>()};
}

Vector3 Vector3::operator-(const Vector3 &other) const {
	return {x - other.x, y - other.y, z - other.z};
}

Vector3 Vector3::operator-(double num) const {
	return {x - num, y - num, z - num};
}

Vector3 Vector3::operator-(const py::list &vectorList) const {
	return {x - vectorList[0].cast<double>(), y - vectorList[1].cast<double>(), z - vectorList[2].cast<double>()};
}

Vector3 Vector3::operator-() const {
	return {-x, -y, -z};
}

Vector3 Vector3::operator/(const Vector3 &other) const {
    return {x / other.x, y / other.y, z / other.z};
}

Vector3 Vector3::operator/(double num) const {
    return {x / num, y / num, z / num};
}

Vector3 Vector3::operator/(const py::list &vectorList) const {
    return {x / vectorList[0].cast<double>(), y / vectorList[1].cast<double>(), z / vectorList[2].cast<double>()};
}

Vector3 Vector3::operator*(const Vector3 &other) const {
    return {x * other.x, y * other.y, z * other.z};
}

Vector3 Vector3::operator*(double num) const {
    return {x * num, y * num, z * num};
}

Vector3 Vector3::operator*(const py::list &vectorList) const {
    return {x * vectorList[0].cast<double>(), y * vectorList[1].cast<double>(), z * vectorList[2].cast<double>()};
}

bool Vector3::operator==(const Vector3& other) const {
	return x == other.x && y == other.y && z == other.z;
}

Vector3 Vector3::Cross(const Vector3 &other) const {
	return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x};
}

Vector3 Vector3::Cross(double num) const {
	return {y * num - z * num, z * num - x * num, x * num - y * num};
}

Vector3 Vector3::Cross(const py::list &vectorList) const {
	auto _x = vectorList[0].cast<double>();
	auto _y = vectorList[1].cast<double>();
	auto _z = vectorList[2].cast<double>();

	return {y * _z - z * _y, z * _x - x * _z, x * _y - y * _x};
}

double Vector3::Dot(const Vector3 &other) const {
	return x * other.x + y * other.y + z * other.z;
}

double Vector3::Dot(double num) const {
	return x * num + y * num + z * num;
}

double Vector3::Dot(const py::list &vectorList) const {
	return x * vectorList[0].cast<double>() + y * vectorList[1].cast<double>() + z * vectorList[2].cast<double>();
}

Vector3 Vector3::Normalize() const {
    double length = sqrt(x * x + y * y + z * z);
    return {x / length, y / length, z / length};
}

Vector3 Vector3::Zero(const py::object& _this) {
    return {0, 0, 0};
}

Vector3 Vector3::One(const py::object& _this) {
    return {1, 1, 1};
}

Vector3 Vector3::Up(const py::object& _this) {
    return {0, 1, 0};
}

Vector3 Vector3::Down(const py::object& _this) {
    return {0, -1, 0};
}

Vector3 Vector3::Left(const py::object& _this) {
    return {-1, 0, 0};
}

Vector3 Vector3::Right(const py::object& _this) {
    return {1, 0, 0};
}

Vector3 Vector3::Back(const py::object& _this) {
    return {0, 0, -1};
}

Vector3 Vector3::Forward(const py::object& _this) {
    return {0, 0, 1};
}

Vector3 Vector3::PositiveInfinity(const py::object& _this) {
    return {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(),
            std::numeric_limits<double>::infinity()};
}

Vector3 Vector3::NegativeInfinity(const py::object& _this) {
    return {-std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity(),
            -std::numeric_limits<double>::infinity()};
}

double Vector3::AngleTo(const Vector3 &other) {
    return GetAngle(other, false);
}

double Vector3::AngleToDegrees(const Vector3 &other) {
    return GetAngle(other, true);
}

void RegisterVector3Class(const py::module_ &m) {
    auto pyClass = py::class_<Vector3>(m, "Vector3");
    pyClass.def(py::init([](double _x, double _y, double _z) { return Vector3(_x, _y, _z); }), py::arg("x"), py::arg("y"), py::arg("z"));
    pyClass.def(py::init([](const py::list &vectorList) { return Vector3(vectorList); }), py::arg("vector_list"));

    pyClass.def_readwrite("x", &Vector3::x);
    pyClass.def_readwrite("y", &Vector3::y);
    pyClass.def_readwrite("z", &Vector3::z);
    pyClass.def("__str__", &Vector3::ToString);

    pyClass.def("to_dict", &Vector3::ToDict);
    pyClass.def("to_list", &Vector3::ToList);
    pyClass.def("length", &Vector3::Length);
    pyClass.def("distance", &Vector3::Distance, py::arg("vector"));
    pyClass.def("distance_squared", &Vector3::DistanceSquared, py::arg("vector"));

    pyClass.def("to_degrees", &Vector3::ToDegrees);
    pyClass.def("to_radians", &Vector3::ToRadians);
    pyClass.def("is_in_range", &Vector3::IsInRange, py::arg("vector"), py::arg("range"));
	pyClass.def("lerp", &Vector3::Lerp, py::arg("vector"), py::arg("ratio"));

	pyClass.def(py::self + py::self);
	pyClass.def(py::self + double());
	pyClass.def(py::self + py::list());

	pyClass.def(py::self - py::self);
	pyClass.def(py::self - double());
	pyClass.def(py::self - py::list());
	pyClass.def(-py::self);

	pyClass.def(py::self * py::self);
	pyClass.def(py::self * double());
	pyClass.def(py::self * py::list());

	pyClass.def(py::self / py::list());
	pyClass.def(py::self / double());
	pyClass.def(py::self / py::self);

	pyClass.def(py::self == py::self);

    pyClass.def("cross", py::overload_cast<const Vector3&>(&Vector3::Cross, py::const_), py::arg("vector"));
    pyClass.def("cross", py::overload_cast<double>(&Vector3::Cross, py::const_), py::arg("num"));
    pyClass.def("cross", py::overload_cast<const py::list&>(&Vector3::Cross, py::const_), py::arg("vector_list"));

	pyClass.def("dot", py::overload_cast<const Vector3&>(&Vector3::Dot, py::const_), py::arg("vector"));
	pyClass.def("dot", py::overload_cast<double>(&Vector3::Dot, py::const_), py::arg("num"));
	pyClass.def("dot", py::overload_cast<const py::list&>(&Vector3::Dot, py::const_), py::arg("vector_list"));

    pyClass.def_property_readonly_static("zero", &Vector3::Zero);
    pyClass.def_property_readonly_static("one", &Vector3::One);
    pyClass.def_property_readonly_static("up", &Vector3::Up);
    pyClass.def_property_readonly_static("down", &Vector3::Down);
    pyClass.def_property_readonly_static("left", &Vector3::Left);
    pyClass.def_property_readonly_static("right", &Vector3::Right);
    pyClass.def_property_readonly_static("back", &Vector3::Back);
    pyClass.def_property_readonly_static("forward", &Vector3::Forward);
    pyClass.def_property_readonly_static("positive_infinity", &Vector3::PositiveInfinity);
    pyClass.def_property_readonly_static("negative_infinity", &Vector3::NegativeInfinity);

    pyClass.def("normalize", &Vector3::Normalize);
    pyClass.def("angle_to", &Vector3::AngleTo, py::arg("vector"));
    pyClass.def("angle_to_degrees", &Vector3::AngleToDegrees, py::arg("vector"));
}