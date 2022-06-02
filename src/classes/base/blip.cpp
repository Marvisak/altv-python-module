#include "classes/classes.hpp"
#include "classes/types/enums.hpp"
#include "classes/types/vector2.hpp"
#include "classes/types/vector3.hpp"
#include "utils.hpp"

BlipColor GetBlipColor(alt::IBlip* _this)
{
	return (BlipColor)_this->GetColor();
}

float GetBlipScale(alt::IBlip* _this)
{
	return _this->GetScaleXY()[0];
}

void SetBlipScale(alt::IBlip* _this, float scale)
{
	_this->SetScaleXY({scale, scale});
}

Vector2 GetSize(alt::IBlip* _this)
{
	return (Vector2)_this->GetScaleXY();
}

void SetSize(alt::IBlip* _this, Vector2 size)
{
	_this->SetScaleXY(size.ToAlt());
}

BlipSprite GetBlipSprite(alt::IBlip* _this)
{
	return (BlipSprite)_this->GetSprite();
}

py::list GetAllBlips(const py::object& type)
{
	return Utils::ArrayToPyList<alt::Ref<alt::IBlip>>(alt::ICore::Instance().GetBlips());
}

void RegisterBlipClass(const py::module_& m)
{
	auto pyClass = py::class_<alt::IBlip, alt::IWorldObject, alt::Ref<alt::IBlip>>(m, "Blip");

	pyClass.def_static(
		"area", [](double x, double y, double z, float width, float height) {
			auto blip = alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::AREA, {x, y, z});
			blip->SetScaleXY({width, height});
			return blip;
		},
		py::arg("x"), py::arg("y"), py::arg("z"), py::arg("width"), py::arg("height"));

	pyClass.def_static(
		"area", [](Vector3 pos, float width, float height) {
			auto blip = alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::AREA, pos.ToAlt());
			blip->SetScaleXY({width, height});
			return blip;
		},
		py::arg("pos"), py::arg("width"), py::arg("height"));

	pyClass.def_static(
		"point", [](double x, double y, double z) {
			return alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::DESTINATION, {x, y, z});
		},
		py::arg("x"), py::arg("y"), py::arg("z"));

	pyClass.def_static(
		"point", [](Vector3 pos) {
			return alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::DESTINATION, pos.ToAlt());
		},
		py::arg("pos"));

	pyClass.def_static(
		"point", [](alt::IEntity* entity) {
			return alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::DESTINATION, entity);
		},
		py::arg("entity"));

	pyClass.def_static(
		"radius", [](double x, double y, double z, float radius) {
			auto blip = alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::RADIUS, {x, y, z});
			blip->SetScaleXY({radius, radius});
			return blip;
		},
		py::arg("x"), py::arg("y"), py::arg("z"), py::arg("radius"));

	pyClass.def_static(
		"radius", [](Vector3 pos, float radius) {
			auto blip = alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::RADIUS, pos.ToAlt());
			blip->SetScaleXY({radius, radius});
			return blip;
		},
		py::arg("pos"), py::arg("radius"));

	pyClass.def_property_readonly_static("all", &GetAllBlips);

	pyClass.def("fade", &alt::IBlip::Fade, py::arg("opacity"), py::arg("duration"));

	pyClass.def_property("alpha", &alt::IBlip::GetAlpha, &alt::IBlip::SetAlpha);
	pyClass.def_property("as_mission_creator", &alt::IBlip::GetAsMissionCreator, &alt::IBlip::SetAsMissionCreator);
	pyClass.def_property("attached_to", &alt::IBlip::AttachedTo, &alt::IBlip::AttachTo);
	pyClass.def_property("bright", &alt::IBlip::GetBright, &alt::IBlip::SetBright);
	pyClass.def_property("category", &alt::IBlip::GetCategory, &alt::IBlip::SetCategory);
	pyClass.def_property("color", &GetBlipColor, &alt::IBlip::SetColor);
	pyClass.def_property("crew_indicator_visible", &alt::IBlip::GetCrewIndicatorVisible, &alt::IBlip::SetCrewIndicatorVisible);
	pyClass.def_property("display", &alt::IBlip::GetDisplay, &alt::IBlip::SetDisplay);
	pyClass.def_property("flash_interval", &alt::IBlip::GetFlashInterval, &alt::IBlip::SetFlashInterval);
	pyClass.def_property("flash_timer", &alt::IBlip::GetFlashTimer, &alt::IBlip::SetFlashTimer);
	pyClass.def_property("flashes", &alt::IBlip::GetFlashes, &alt::IBlip::SetFlashes);
	pyClass.def_property("flashes_alternate", &alt::IBlip::GetFlashesAlternate, &alt::IBlip::SetFlashesAlternate);
	pyClass.def_property("friend_indicator_visible", &alt::IBlip::GetFriendIndicatorVisible, &alt::IBlip::SetFriendIndicatorVisible);
	pyClass.def_property("gxt_name", &alt::IBlip::GetGxtName, &alt::IBlip::SetGxtName);
	pyClass.def_property("heading", &alt::IBlip::GetRotation, &alt::IBlip::SetRotation);
	pyClass.def_property("heading_indicator_visible", &alt::IBlip::GetHeadingIndicatorVisible, &alt::IBlip::SetHeadingIndicatorVisible);
	pyClass.def_property("high_detail", &alt::IBlip::GetAsHighDetail, &alt::IBlip::SetAsHighDetail);
	pyClass.def_property("name", &alt::IBlip::GetName, &alt::IBlip::SetName);
	pyClass.def_property("number", &alt::IBlip::GetNumber, &alt::IBlip::SetNumber);
	pyClass.def_property("outline_indicator_visible", &alt::IBlip::GetOutlineIndicatorVisible, &alt::IBlip::SetOutlineIndicatorVisible);
	pyClass.def_property("priority", &alt::IBlip::GetPriority, &alt::IBlip::SetPriority);
	pyClass.def_property("pulse", &alt::IBlip::GetPulse, &alt::IBlip::SetPulse);
	pyClass.def_property("route", &alt::IBlip::GetRoute, &alt::IBlip::SetRoute);
	pyClass.def_property("route_color", &alt::IBlip::GetRouteColor, &alt::IBlip::SetRouteColor);
	pyClass.def_property("scale", &GetBlipScale, &SetBlipScale);
	pyClass.def_property("secondary_color", &alt::IBlip::GetSecondaryColor, &alt::IBlip::SetSecondaryColor);
	pyClass.def_property("short_range", &alt::IBlip::GetAsShortRange, &alt::IBlip::SetAsShortRange);
	pyClass.def_property("show_cone", &alt::IBlip::GetShowCone, &alt::IBlip::SetShowCone);
	pyClass.def_property("shrinked", &alt::IBlip::GetShrinked, &alt::IBlip::SetShrinked);
	pyClass.def_property("size", &GetSize, &SetSize);
	pyClass.def_property("sprite", &GetBlipSprite, &alt::IBlip::SetSprite);
	pyClass.def_property("tick_visible", &alt::IBlip::GetTickVisible, &alt::IBlip::SetTickVisible);
}
