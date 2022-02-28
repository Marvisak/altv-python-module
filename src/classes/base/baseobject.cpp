#include "classes/classes.hpp"
#include "utils.hpp"

PYBIND11_DECLARE_HOLDER_TYPE(T, alt::Ref<T>, true)

uint64_t GetRefCount(alt::IBaseObject* _this) {
    if (alt::ICore::Instance().IsDebug())
        return _this->GetRefCount();
    throw std::exception("ref_count is only available in debug mode");
}

bool GetValid(alt::IBaseObject* _this) {
    PyFrameObject* frame = PyEval_GetFrame();
    PythonResource* resource = Utils::GetResourceFromFrame(frame);
    return resource->IsObjectValid(_this);
}

py::object GetMeta(alt::IBaseObject* _this, const std::string& key) {
    return Utils::MValueToValue(_this->GetMetaData(key));
}

void SetMeta(alt::IBaseObject* _this, const std::string& key, const py::object& value) {
    _this->SetMetaData(key, Utils::ValueToMValue(value));
}

void Destroy(alt::IBaseObject* _this) {
    alt::ICore::Instance().DestroyBaseObject(_this);
}

void RegisterBaseObjectClass(const py::module_& m) {
    auto pyClass = py::class_<alt::IBaseObject, alt::Ref<alt::IBaseObject>>(m, "BaseObject");

    pyClass.def_property_readonly("ref_count", &GetRefCount);
    pyClass.def_property_readonly("valid", &GetValid);
    pyClass.def_property_readonly("type", &alt::IBaseObject::GetType);

    // Meta
    pyClass.def("delete_meta", &alt::IBaseObject::DeleteMetaData, py::arg("key"));
    pyClass.def("has_meta", &alt::IBaseObject::HasMetaData, py::arg("key"));
    pyClass.def("set_meta", &SetMeta, py::arg("key"), py::arg("value"));
    pyClass.def("get_meta", &GetMeta, py::arg("key"));

    pyClass.def("destroy", &Destroy);
}
