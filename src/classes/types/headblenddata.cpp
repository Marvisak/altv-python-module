#include "classes/classes.h"

std::string ToString(alt::HeadBlendData _this) {
    return "HeadBlendData(shapeFirstID: " + std::to_string(_this.shapeFirstID) + ", shapeSecondID: " + std::to_string(_this.shapeSecondID) + ", shapeThirdID: " + std::to_string(_this.shapeThirdID) + ", skinFirstID: " + std::to_string(_this.skinFirstID) + ", skinSecondID: " + std::to_string(_this.skinSecondID) + ", skinThirdID: " + std::to_string(_this.skinThirdID) + ", shapeMix: " + std::to_string(_this.shapeMix) + ", skinMix: " + std::to_string(_this.shapeMix) + ", thirdMix: " + std::to_string(_this.thirdMix) + ")";
}

void RegisterHeadBlendData(const py::module_& m) {
    auto pyClass = py::class_<alt::HeadBlendData>(m, "HeadBlendData");
    pyClass.def(py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, float, float, float>(), py::arg("shape_first_id"), py::arg("shape_second_id"), py::arg("shape_third_id"), py::arg("skin_first_id"), py::arg("skin_second_id"), py::arg("skin_third_id"), py::arg("shape_mix"), py::arg("skin_mix"), py::arg("third_mix"));
    pyClass.def_readwrite("shape_first_id", &alt::HeadBlendData::shapeFirstID);
    pyClass.def_readwrite("shape_second_id", &alt::HeadBlendData::shapeSecondID);
    pyClass.def_readwrite("shape_third_id", &alt::HeadBlendData::shapeThirdID);
    pyClass.def_readwrite("skin_first_id", &alt::HeadBlendData::skinFirstID);
    pyClass.def_readwrite("skin_second_id", &alt::HeadBlendData::skinSecondID);
    pyClass.def_readwrite("skin_third_id", &alt::HeadBlendData::skinThirdID);
    pyClass.def_readwrite("shape_mix", &alt::HeadBlendData::shapeMix);
    pyClass.def_readwrite("skin_mix", &alt::HeadBlendData::skinMix);
    pyClass.def_readwrite("third_mix", &alt::HeadBlendData::thirdMix);
    pyClass.def("__str__", &ToString);
}