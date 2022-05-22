#include "classes/classes.hpp"
#include "classes/types/enums.hpp"
#include "classes/types/vector2.hpp"
#include "classes/types/vector3.hpp"


ColShapeType GetColShapeType(alt::IColShape* _this) {
	return (ColShapeType)_this->GetColshapeType();
}

bool IsPointIn(alt::IColShape* _this, Vector3 pos) {
	return _this->IsPointIn(pos.ToAlt());
}

void RegisterColShapeClass(const py::module_& m) {
	auto pyClass = py::class_<alt::IColShape, alt::IWorldObject, alt::Ref<alt::IColShape>>(m, "ColShape", py::multiple_inheritance());

	pyClass.def_static("circle", [](double x, double y, float radius) {
		return alt::ICore::Instance().CreateColShapeCircle({x, y, 0}, radius);
	}, py::arg("x"), py::arg("y"), py::arg("radius"));

	pyClass.def_static("circle", [](Vector2 pos, float radius) {
		return alt::ICore::Instance().CreateColShapeCircle(pos.ToAlt(), radius);
	}, py::arg("pos"), py::arg("radius"));

	pyClass.def_static("cylinder", [](double x, double y, double z, float radius, float height) {
		return alt::ICore::Instance().CreateColShapeCylinder({x, y, z}, radius, height);
	}, py::arg("x"), py::arg("y"), py::arg("z"), py::arg("radius"), py::arg("height"));

	pyClass.def_static("cylinder", [](Vector3 pos, float radius, float height) {
		return alt::ICore::Instance().CreateColShapeCylinder(pos.ToAlt(), radius, height);
	}, py::arg("pos"), py::arg("radius"), py::arg("height"));

	pyClass.def_static("sphere", [](double x, double y, double z, float radius) {
			return alt::ICore::Instance().CreateColShapeSphere({x, y, z}, radius);
	}, py::arg("x"), py::arg("y"), py::arg("z"), py::arg("radius"));

	pyClass.def_static("sphere", [](Vector3 pos, float radius) {
			return alt::ICore::Instance().CreateColShapeSphere(pos.ToAlt(), radius);
	}, py::arg("pos"), py::arg("radius"));

	pyClass.def_static("cube", [](double x1, double y1, double z1, double x2, double y2, double z2) {
			return alt::ICore::Instance().CreateColShapeCube({x1, y1, z1}, {x2, y2, z2});
	}, py::arg("x1"), py::arg("y1"), py::arg("z1"), py::arg("x2"), py::arg("y2"), py::arg("z2"));

	pyClass.def_static("cube", [](Vector3 pos1, Vector3 pos2) {
			return alt::ICore::Instance().CreateColShapeCube(pos1.ToAlt(), pos2.ToAlt());
	}, py::arg("pos1"), py::arg("pos2"));

	pyClass.def_static("rectangle", [](float x1, float y1, float x2, float y2) {
			return alt::ICore::Instance().CreateColShapeRectangle(x1, y1, x2, y2, 0);
	}, py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"));

	pyClass.def_static("rectangle", [](Vector2 pos1, Vector2 pos2) {
			return alt::ICore::Instance().CreateColShapeRectangle((float)pos1.x, (float)pos1.y, (float)pos2.x, (float)pos2.y, 0);
	}, py::arg("pos1"), py::arg("pos2"));

	pyClass.def_static("polygon", [](float minZ, float maxZ, const std::vector<Vector2>& points) {
		std::vector<alt::Vector2f> parsed_points;
		for (auto point : points)
			parsed_points.emplace_back(point.ToAlt());
		return alt::ICore::Instance().CreateColShapePolygon(minZ, maxZ, parsed_points);
	}, py::arg("min_z"), py::arg("max_z"), py::arg("points"));

	pyClass.def_property_readonly("colshape_type", &GetColShapeType);
	pyClass.def_property("players_only", &alt::IColShape::IsPlayersOnly, &alt::IColShape::SetPlayersOnly);

	pyClass.def("is_entity_in", &alt::IColShape::IsEntityIn, py::arg("entity"));
	pyClass.def("is_point_in", &IsPointIn, py::arg("pos"));
}
