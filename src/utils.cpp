#include "utils.hpp"
#include "classes/types/vector2.hpp"
#include "classes/types/vector3.hpp"

alt::MValue Utils::ValueToMValue(const py::object& arg)
{
	if (py::isinstance<py::str>(arg))
		return alt::ICore::Instance().CreateMValueString(py::str(arg).cast<std::string>());
	else if (py::isinstance<py::bool_>(arg))
		return alt::ICore::Instance().CreateMValueBool(py::bool_(arg).cast<bool>());
	else if (py::isinstance<py::int_>(arg))
		return alt::ICore::Instance().CreateMValueInt(py::int_(arg).cast<int64_t>());
	else if (py::isinstance<py::none>(arg))
		return alt::ICore::Instance().CreateMValueNil();
	else if (py::isinstance<py::float_>(arg))
		return alt::ICore::Instance().CreateMValueDouble(py::float_(arg).cast<double>());
	else if (py::isinstance<py::list>(arg) || py::isinstance<py::tuple>(arg))
	{
		auto tempList = alt::ICore::Instance().CreateMValueList();
		for (auto element : arg)
			tempList->Push(ValueToMValue(element.cast<py::object>()));
		return tempList;
	}
	else if (py::isinstance<py::dict>(arg))
	{
		auto tempDict = alt::ICore::Instance().CreateMValueDict();
		auto dict = arg.cast<py::dict>();
		for (auto item : dict)
			tempDict->Set(item.first.cast<std::string>(), ValueToMValue(item.second.cast<py::object>()));
		return tempDict;
	}
	else if (py::isinstance<py::function>(arg))
	{
		auto func = arg.cast<py::function>();
		return alt::ICore::Instance().CreateMValueFunction(new PythonResource::PythonFunction(func));
	}
	else if (py::isinstance<py::bytes>(arg))
		return alt::ICore::Instance().CreateMValueString(arg.cast<py::bytes>().cast<std::string>());
	else if (py::isinstance<py::bytearray>(arg))
	{
		auto byteArray = arg.cast<py::bytearray>();
		return alt::ICore::Instance().CreateMValueByteArray(reinterpret_cast<const uint8_t*>(byteArray.cast<std::string>().c_str()), byteArray.size());
	}
	else if (py::isinstance<Vector3>(arg))
		return alt::ICore::Instance().CreateMValueVector3(arg.cast<Vector3>().ToAlt());
	else if (py::isinstance<Vector2>(arg))
		return alt::ICore::Instance().CreateMValueVector2(arg.cast<Vector2>().ToAlt());
	else if (py::isinstance<alt::RGBA>(arg))
		return alt::ICore::Instance().CreateMValueRGBA(arg.cast<alt::RGBA>());
	else if (py::isinstance<alt::IBaseObject>(arg))
		return alt::ICore::Instance().CreateMValueBaseObject(arg.cast<alt::IBaseObject*>());
	else
		return alt::ICore::Instance().CreateMValueNone();
}

py::object Utils::MValueToValue(const alt::MValueConst& mValue)
{
	switch (mValue->GetType())
	{
	case alt::IMValue::Type::NIL:
	case alt::IMValue::Type::NONE:
		return py::none();
	case alt::IMValue::Type::BOOL:
		return py::bool_(mValue.As<alt::IMValueBool>()->Value());
	case alt::IMValue::Type::INT:
		return py::int_(static_cast<int>(mValue.As<alt::IMValueInt>()->Value()));
	case alt::IMValue::Type::UINT:
		return py::int_(static_cast<unsigned int>(mValue.As<alt::IMValueUInt>()->Value()));
	case alt::IMValue::Type::DOUBLE:
		return py::float_(mValue.As<alt::IMValueDouble>()->Value());
	case alt::IMValue::Type::STRING:
		return py::str(mValue.As<alt::IMValueString>()->Value());
	case alt::IMValue::Type::LIST: {
		auto mList = mValue.As<alt::IMValueList>();
		py::list pyList;
		for (uint64_t i = 0; i < mList->GetSize(); i++)
			pyList.append(MValueToValue(mList->Get(i)));
		return pyList;
	}

	case alt::IMValue::Type::DICT: {
		auto mDict = mValue.As<alt::IMValueDict>();
		py::dict pyDict;
		for (auto item = mDict->Begin(); item; item = mDict->Next())
		{
			auto dictVal = MValueToValue(item->GetValue().Get());
			pyDict[item->GetKey().c_str()] = dictVal;
		}
		return pyDict;
	}

	case alt::IMValue::Type::VECTOR3: {
		Vector3 mVector3 = Vector3(mValue.As<alt::IMValueVector3>()->Value());
		return py::cast(mVector3);
	}

	case alt::IMValue::Type::VECTOR2: {
		Vector2 mVector2 = Vector2(mValue.As<alt::IMValueVector2>()->Value());
		return py::cast(mVector2);
	}

	case alt::IMValue::Type::BASE_OBJECT: {
		auto mBaseObject = mValue.As<alt::IMValueBaseObject>()->Value();
		return Utils::GetBaseObject(mBaseObject);
	}
	case alt::IMValue::Type::FUNCTION: {
		auto mFunc = mValue.As<alt::IMValueFunction>();
		py::cpp_function pyFunc = [mFunc](const py::args& args) {
			alt::MValueArgs funcArgs;
			for (auto arg : args)
				funcArgs.Push(Utils::ValueToMValue(arg.cast<py::object>()));
			auto returnValue = mFunc->Call(funcArgs);
			return MValueToValue(returnValue);
		};
		return pyFunc;
	}
	case alt::IMValue::Type::RGBA: {
		auto mRGBA = mValue.As<alt::IMValueRGBA>().Get()->Value();
		return py::cast(mRGBA);
	}
	case alt::IMValue::Type::BYTE_ARRAY: {
		auto mByteArray = mValue.As<alt::IMValueByteArray>();
		return py::bytearray(reinterpret_cast<const char*>(mByteArray->GetData()), (Py_ssize_t)mByteArray->GetSize());
	}
	default:
		return py::none();
	}
}

py::object Utils::ConfigNodeToValue(alt::config::Node& node)
{
	switch (node.GetType())
	{
	case alt::config::Node::Type::NONE:
		return py::none();
	case alt::config::Node::Type::SCALAR: {
		try
		{
			return py::bool_(node.ToBool());
		}
		catch (alt::config::Error&)
		{
			try
			{
				return py::float_(node.ToNumber());
			}
			catch (alt::config::Error&)
			{
				return py::str(node.ToString());
			}
		}
	}
	case alt::config::Node::Type::LIST: {
		alt::config::Node::List list = node.ToList();
		py::list pyList;
		for (auto val : list)
			pyList.append(ConfigNodeToValue(val));
		return pyList;
	}
	case alt::config::Node::Type::DICT: {
		alt::config::Node::Dict dict = node.ToDict();
		py::dict pyDict;
		for (auto& pair : dict)
			pyDict[pair.first.c_str()] = ConfigNodeToValue(pair.second);
		return pyDict;
	}
	default:
		return py::none();
	}
}

py::object Utils::GetBaseObject(const alt::Ref<alt::IBaseObject>& baseObject)
{
	if (!baseObject) return py::none();
	switch (baseObject->GetType())
	{
	case alt::IBaseObject::Type::PLAYER:
		return py::cast(dynamic_cast<alt::IPlayer*>(baseObject.Get()));
	case alt::IBaseObject::Type::VEHICLE:
		return py::cast(dynamic_cast<alt::IVehicle*>(baseObject.Get()));
	case alt::IBaseObject::Type::BLIP:
		return py::cast(dynamic_cast<alt::IBlip*>(baseObject.Get()));
	case alt::IBaseObject::Type::COLSHAPE:
		return py::cast(dynamic_cast<alt::IColShape*>(baseObject.Get()));
	case alt::IBaseObject::Type::CHECKPOINT:
		return py::cast(dynamic_cast<alt::ICheckpoint*>(baseObject.Get()));
	case alt::IBaseObject::Type::VOICE_CHANNEL:
		return py::cast(dynamic_cast<alt::IVoiceChannel*>(baseObject.Get()));
	default:
		return py::none();
	}
}
