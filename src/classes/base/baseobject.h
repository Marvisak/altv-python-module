#pragma once

#include "main.h"
#include "utils.h"

class BaseObject
{
 private:
	alt::Ref<alt::IBaseObject> Obj;

 public:
	BaseObject(alt::Ref<alt::IBaseObject> BaseObject)
		: Obj(BaseObject)
	{
	}

	// Type
	alt::IBaseObject::Type GetType() const
	{
		return Obj->GetType();
	}

	// Valid
	bool IsValid() const
	{
		PyFrameObject* frame = PyEval_GetFrame();
		PythonResource* resource = Utils::GetResourceFromFrame(frame);
		return resource->IsObjectValid(Obj);
	}

	// Meta
	void DeleteMeta(const std::string& key)
	{
		Obj->DeleteMetaData(key);
	}
	py::object GetMeta(const std::string& key)
	{
		return Utils::MValueToValue(Obj->GetMetaData(key));
	}
	bool HasMeta(const std::string& key)
	{
		return Obj->HasMetaData(key);
	}
	void SetMeta(const std::string& key, const py::object& value)
	{
		return Obj->SetMetaData(key, Utils::ValueToMValue(value));
	}
	void Destroy()
	{
		Core->DestroyBaseObject(Obj);
	}
};

void RegisterBaseObjectClass(const py::module_& m);
