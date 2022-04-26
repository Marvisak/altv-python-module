#include "classes/types/vector3.hpp"
#include "utils.hpp"

alt::MValue Utils::ValueToMValue(const py::object& arg) {
	alt::MValue mValue;
	auto valueStr = py::str(arg).cast<std::string>();
	if (py::isinstance<py::str>(arg))
		mValue = alt::ICore::Instance().CreateMValueString(valueStr);
	else if (py::isinstance<py::bool_>(arg))
		mValue = alt::ICore::Instance().CreateMValueBool(valueStr != "0");
	else if (py::isinstance<py::int_>(arg))
		mValue = alt::ICore::Instance().CreateMValueInt(std::stoi(valueStr));
	else if (py::isinstance<py::none>(arg))
		mValue = alt::ICore::Instance().CreateMValueNil();
	else if (py::isinstance<py::float_>(arg))
		mValue = alt::ICore::Instance().CreateMValueDouble(std::stod(valueStr));
	else if (py::isinstance<py::list>(arg) || py::isinstance<py::tuple>(arg)) {
		auto tempList = alt::ICore::Instance().CreateMValueList();
		for (auto element : arg)
			tempList->Push(ValueToMValue(element.cast<py::object>()));
		mValue = tempList;
	} else if (py::isinstance<py::dict>(arg)) {
		auto tempDict = alt::ICore::Instance().CreateMValueDict();
		auto dict = arg.cast<py::dict>();
		for (auto item : dict)
			tempDict->Set(item.first.cast<std::string>(), ValueToMValue(item.second.cast<py::object>()));
		mValue = tempDict;
	} else if (py::isinstance<py::function>(arg)) {
		auto func = arg.cast<py::function>();
		mValue = alt::ICore::Instance().CreateMValueFunction(new PythonResource::PythonFunction(func));
	} else if (py::isinstance<py::bytes>(arg))
		mValue = alt::ICore::Instance().CreateMValueString(arg.cast<py::bytes>().cast<std::string>());
	else if (py::isinstance<py::bytearray>(arg)) {
		auto byteArray = arg.cast<py::bytearray>();
		mValue = alt::ICore::Instance().CreateMValueByteArray(reinterpret_cast<const uint8_t*>(byteArray.cast<std::string>().c_str()), byteArray.size());
	} else if (py::isinstance<Vector3>(arg))
		mValue = alt::ICore::Instance().CreateMValueVector3(arg.cast<Vector3>().ToAltPos());
	else if (py::isinstance<alt::RGBA>(arg))
		mValue = alt::ICore::Instance().CreateMValueRGBA(arg.cast<alt::RGBA>());
	else if (py::isinstance<alt::IBaseObject>(arg))
		mValue = alt::ICore::Instance().CreateMValueBaseObject(arg.cast<alt::IBaseObject*>());
	else
		mValue = alt::ICore::Instance().CreateMValueNone();
	return mValue;
}

py::object Utils::MValueToValue(const alt::MValueConst& mValue) {
	py::object value;
	switch (mValue->GetType())
	{
        case alt::IMValue::Type::NIL:
        case alt::IMValue::Type::NONE:
            value = py::none();
            break;
        case alt::IMValue::Type::BOOL:
            value = py::bool_(mValue.As<alt::IMValueBool>()->Value());
            break;
        case alt::IMValue::Type::INT:
            value = py::int_(static_cast<int>(mValue.As<alt::IMValueInt>()->Value()));
            break;
        case alt::IMValue::Type::UINT:
            value = py::int_(static_cast<unsigned int>(mValue.As<alt::IMValueUInt>()->Value()));
            break;
        case alt::IMValue::Type::DOUBLE:
            value = py::float_(mValue.As<alt::IMValueDouble>()->Value());
            break;
        case alt::IMValue::Type::STRING:
            value = py::str(mValue.As<alt::IMValueString>()->Value());
            break;
        case alt::IMValue::Type::LIST: {
            auto mList = mValue.As<alt::IMValueList>();
            py::list pyList;
            for (uint64_t i = 0; i < mList->GetSize(); i++)
                pyList.append(MValueToValue(mList->Get(i)));
            value = pyList;
            break;
        }

        case alt::IMValue::Type::DICT: {
            auto mDict = mValue.As<alt::IMValueDict>();
            py::dict pyDict;
            for (auto item = mDict->Begin(); item; item = mDict->Next()) {
                auto dictVal = MValueToValue(item->GetValue().Get());
                pyDict[item->GetKey().c_str()] = dictVal;
            }
            value = pyDict;
            break;
        }

        case alt::IMValue::Type::VECTOR3: {
            Vector3 mVector3 = Vector3(mValue.As<alt::IMValueVector3>()->Value());
            value = py::cast(mVector3);
            break;
        }

        case alt::IMValue::Type::BASE_OBJECT: {
            auto mBaseObject = mValue.As<alt::IMValueBaseObject>()->Value();
            value = Utils::GetBaseObject(mBaseObject);
            break;
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
            value = pyFunc;
            break;
        }
        case alt::IMValue::Type::RGBA: {
            auto mRGBA = mValue.As<alt::IMValueRGBA>().Get()->Value();
            value = py::cast(mRGBA);
            break;
        }
		case alt::IMValue::Type::BYTE_ARRAY: {
			auto mByteArray = mValue.As<alt::IMValueByteArray>();
			value = py::bytearray(reinterpret_cast<const char*>(mByteArray->GetData()), mByteArray->GetSize());
			break;
		}
        default:
            value = py::none();
            break;
        }
	return value;
}

py::object Utils::ConfigNodeToValue(alt::config::Node& node) {
	py::object value;
	switch (node.GetType()) {
		case alt::config::Node::Type::NONE:
			value = py::none();
			break;
		case alt::config::Node::Type::SCALAR: {
			try {
				value = py::bool_(node.ToBool());
			} catch (alt::config::Error&) {
				try {
					value = py::float_(node.ToNumber());
				} catch (alt::config::Error&) {
					value = py::str(node.ToString());
				}
			}
			break;
		}
		case alt::config::Node::Type::LIST: {
			alt::config::Node::List list = node.ToList();
			py::list pyList;
			for (auto val : list)
				pyList.append(ConfigNodeToValue(val));
			value = pyList;
			break;
		}
		case alt::config::Node::Type::DICT: {
			alt::config::Node::Dict dict = node.ToDict();
			py::dict pyDict;
			for (auto& pair : dict)
				pyDict[pair.first.c_str()] = ConfigNodeToValue(pair.second);
			value = pyDict;
			break;
		}
	}
	return value;
}

py::object Utils::GetBaseObject(const alt::Ref<alt::IBaseObject>& baseObject) {
    if (!baseObject) return py::none();
    switch (baseObject->GetType()) {
        case alt::IBaseObject::Type::PLAYER:
            return py::cast(dynamic_cast<alt::IPlayer*>(baseObject.Get()));
        case alt::IBaseObject::Type::VEHICLE:
            return py::cast(dynamic_cast<alt::IVehicle*>(baseObject.Get()));
        case alt::IBaseObject::Type::BLIP:
            break;
        case alt::IBaseObject::Type::COLSHAPE:
            break;
        case alt::IBaseObject::Type::CHECKPOINT:
            break;
        case alt::IBaseObject::Type::VOICE_CHANNEL:
            break;
    }
    return py::none();
}
