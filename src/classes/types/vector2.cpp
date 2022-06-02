#include "vector2.hpp"
#include "classes/classes.hpp"

double Vector2::GetAngle(const Vector2& other, const bool& degrees) const
{
	double xy = x * other.x + y * other.y;
	double posALength = sqrt(std::pow(x, 2) + std::pow(y, 2));
	double posBLength = sqrt(std::pow(other.x, 2) + std::pow(other.y, 2));

	if (posALength == 0 || posBLength == 0)
	{
		return -1;
	}

	double cos = xy / (posALength * posBLength);

	if (degrees)
		return std::acos(cos);
	else
		return std::acos(cos) * (180 / alt::PI);
}

py::dict Vector2::ToDict()
{
	py::dict dict;
	dict["x"] = x;
	dict["y"] = y;
	return dict;
}

py::list Vector2::ToList()
{
	py::list list;
	list.append(x);
	list.append(y);
	return list;
}

alt::Position Vector2::ToAlt() const
{
	return {x, y, 0};
}

std::string Vector2::ToString() const
{
	return "Vector2(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2 Vector2::ToDegrees() const
{
	return {x * (180 / alt::PI), y * (180 / alt::PI)};
}

Vector2 Vector2::ToRadians() const
{
	return {x * (alt::PI / 180), y * (alt::PI / 180)};
}

double Vector2::Length() const
{
	return sqrt(x * x + y * y);
}

double Vector2::Distance(Vector2& other) const
{
	return sqrt(DistanceSquared(other));
}

double Vector2::DistanceSquared(Vector2& other) const
{
	return std::pow(x - other.x, 2) + std::pow(y - other.y, 2);
}

Vector2 Vector2::Lerp(Vector2 other, double ratio) const
{
	double x1 = x + (other.x - x) * ratio;
	double y1 = y + (other.y - y) * ratio;
	return {x1, y1};
}

bool Vector2::IsInRange(const Vector2& other, double range) const
{
	double dx = abs(x - other.x);
	double dy = abs(y - other.y);

	return dx <= range && dy <= range && dx * dx + dy * dy <= range * range;
}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return {x + other.x, y + other.y};
}

Vector2 Vector2::operator+(double num) const
{
	return {x + num, y + num};
}

Vector2 Vector2::operator+(const py::list& vectorList) const
{
	return {x + vectorList[0].cast<double>(), y + vectorList[1].cast<double>()};
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return {x - other.x, y - other.y};
}

Vector2 Vector2::operator-(double num) const
{
	return {x - num, y - num};
}

Vector2 Vector2::operator-(const py::list& vectorList) const
{
	return {x - vectorList[0].cast<double>(), y - vectorList[1].cast<double>()};
}

Vector2 Vector2::operator-() const
{
	return {-x, -y};
}

Vector2 Vector2::operator/(const Vector2& other) const
{
	return {x / other.x, y / other.y};
}

Vector2 Vector2::operator/(double num) const
{
	return {x / num, y / num};
}

Vector2 Vector2::operator/(const py::list& vectorList) const
{
	return {x / vectorList[0].cast<double>(), y / vectorList[1].cast<double>()};
}

Vector2 Vector2::operator*(const Vector2& other) const
{
	return {x * other.x, y * other.y};
}

Vector2 Vector2::operator*(double num) const
{
	return {x * num, y * num};
}

Vector2 Vector2::operator*(const py::list& vectorList) const
{
	return {x * vectorList[0].cast<double>(), y * vectorList[1].cast<double>()};
}

bool Vector2::operator==(const Vector2& other) const
{
	return x == other.x && y == other.y;
}

double Vector2::Dot(const Vector2& other) const
{
	return x * other.x + y * other.y;
}

double Vector2::Dot(double num) const
{
	return x * num + y * num;
}

double Vector2::Dot(const py::list& vectorList) const
{
	return x * vectorList[0].cast<double>() + y * vectorList[1].cast<double>();
}

Vector2 Vector2::Normalize() const
{
	double length = sqrt(x * x + y * y);
	return {x / length, y / length};
}

Vector2 Vector2::Zero(const py::object& _this)
{
	return {0, 0};
}

Vector2 Vector2::One(const py::object& _this)
{
	return {1, 1};
}

Vector2 Vector2::Up(const py::object& _this)
{
	return {0, 1};
}

Vector2 Vector2::Down(const py::object& _this)
{
	return {0, -1};
}

Vector2 Vector2::Left(const py::object& _this)
{
	return {-1, 0};
}

Vector2 Vector2::Right(const py::object& _this)
{
	return {1, 0};
}

Vector2 Vector2::PositiveInfinity(const py::object& _this)
{
	return {std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity()};
}

Vector2 Vector2::NegativeInfinity(const py::object& _this)
{
	return {-std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity()};
}

double Vector2::AngleTo(const Vector2& other)
{
	return GetAngle(other, false);
}

double Vector2::AngleToDegrees(const Vector2& other)
{
	return GetAngle(other, true);
}

void RegisterVector2Class(const py::module_& m)
{
	auto pyClass = py::class_<Vector2>(m, "Vector2");
	pyClass.def(py::init([](double _x, double _y) { return Vector2(_x, _y); }), py::arg("x"), py::arg("y"));
	pyClass.def(py::init([](const py::list& vectorList) { return Vector2(vectorList); }), py::arg("vector_list"));

	pyClass.def_readwrite("x", &Vector2::x);
	pyClass.def_readwrite("y", &Vector2::y);
	pyClass.def("__str__", &Vector2::ToString);

	pyClass.def("to_dict", &Vector2::ToDict);
	pyClass.def("to_list", &Vector2::ToList);
	pyClass.def("length", &Vector2::Length);
	pyClass.def("distance", &Vector2::Distance, py::arg("vector"));
	pyClass.def("distance_squared", &Vector2::DistanceSquared, py::arg("vector"));
	pyClass.def("lerp", &Vector2::Lerp, py::arg("vector"), py::arg("ratio"));

	pyClass.def("to_degrees", &Vector2::ToDegrees);
	pyClass.def("to_radians", &Vector2::ToRadians);
	pyClass.def("is_in_range", &Vector2::IsInRange, py::arg("vector"), py::arg("range"));

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

	pyClass.def(py::self / py::self);
	pyClass.def(py::self / double());
	pyClass.def(py::self / py::list());

	pyClass.def(py::self == py::self);

	pyClass.def("dot", py::overload_cast<const Vector2&>(&Vector2::Dot, py::const_), py::arg("vector"));
	pyClass.def("dot", py::overload_cast<const py::list&>(&Vector2::Dot, py::const_), py::arg("vector_list"));
	pyClass.def("dot", py::overload_cast<double>(&Vector2::Dot, py::const_), py::arg("num"));

	pyClass.def_property_readonly_static("zero", &Vector2::Zero);
	pyClass.def_property_readonly_static("one", &Vector2::One);
	pyClass.def_property_readonly_static("up", &Vector2::Up);
	pyClass.def_property_readonly_static("down", &Vector2::Down);
	pyClass.def_property_readonly_static("left", &Vector2::Left);
	pyClass.def_property_readonly_static("right", &Vector2::Right);
	pyClass.def_property_readonly_static("positive_infinity", &Vector2::PositiveInfinity);
	pyClass.def_property_readonly_static("negative_infinity", &Vector2::NegativeInfinity);

	pyClass.def("normalize", &Vector2::Normalize);
	pyClass.def("angle_to", &Vector2::AngleTo, py::arg("vector"));
	pyClass.def("angle_to_degrees", &Vector2::AngleToDegrees, py::arg("vector"));
}
