#include <utils.h>
#include <classes/classes.h>

PythonResource* Utils::GetResourceFromFrame(PyFrameObject *frame) {
    PyObject *filename = frame->f_code->co_filename;
    PyObject* byteStr = PyUnicode_AsEncodedString(filename, "utf-8", "~E~");
    std::string fullPath = PyBytes_AS_STRING(byteStr);
    PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromPath(fullPath);
    return resource;
}

alt::MValue Utils::ValueToMValue(pybind11::handle arg) {
    alt::MValue mValue;
    auto type = py::type::of(arg).attr("__name__").cast<std::string>();
    auto valueStr = py::str(arg).cast<std::string>();
    if (type == "str")
    {
        mValue = Core->CreateMValueString(valueStr);
    } else if (type == "int")
    {
        mValue = Core->CreateMValueInt(std::stoi(valueStr));
    } else if (type == "NoneType")
    {
        mValue = Core->CreateMValueNil();
    } else if (type == "bool")
    {
        mValue = Core->CreateMValueBool(valueStr != "0");
    } else if (type == "float")
    {
        mValue = Core->CreateMValueDouble(std::stod(valueStr));
    } else if (type == "list")
    {
        auto tempList = Core->CreateMValueList();
        for (auto element : arg)
        {
            tempList->Push(ValueToMValue(element));
        }
        mValue = tempList;
    } else if (type == "dict")
    {
        auto tempDict = Core->CreateMValueDict();
        auto dict = arg.cast<py::dict>();
        for (auto item : dict)
        {
            tempDict->Set(item.first.cast<std::string>(), ValueToMValue(item.second));
        }
        mValue = tempDict;
    } else if (type == "vector3")
    {
        auto vector3 = arg.cast<Vector3>();
        mValue = Core->CreateMValueVector3(alt::Vector3f(vector3.x, vector3.y, vector3.z));
    } else if (type == "function")
    {
        auto func = arg.cast<py::function>();
        mValue = Core->CreateMValueFunction(new PythonResource::PythonFunction(func));
    } else if (type == "player")
    {
        auto player = arg.cast<Player>();
        mValue = Core->CreateMValueBaseObject(player.GetBaseObject());
    } else if (type == "rgba")
    {
        auto rgba = arg.cast<RGBA>();
        mValue = Core->CreateMValueRGBA(alt::RGBA(rgba.r, rgba.g, rgba.b, rgba.a));
    }
    else
    {
        mValue = Core->CreateMValueNone();
    }
    return mValue;
}

py::object Utils::MValueToValue(const alt::MValueConst &mValue) {
    py::object value;
    switch(mValue->GetType()) {
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
            value = py::str(mValue.As<alt::IMValueString>()->Value().ToString());
            break;
        case alt::IMValue::Type::LIST: {
            auto mList = mValue.As<alt::IMValueList>();
            py::list pyList;
            for (uint64_t i = 0; i < mList->GetSize(); i++) {
                pyList.append(MValueToValue(mList->Get(i)));
            }
            value = pyList;
            break;
        }

        case alt::IMValue::Type::DICT: {
            auto mDict = mValue.As<alt::IMValueDict>();
            py::dict pyDict;
            for (auto item = mDict->Begin(); item; item = mDict->Next()) {
                auto dictVal = MValueToValue(item->GetValue().Get());
                pyDict[item->GetKey().CStr()] = dictVal;
            }
            value = pyDict;
            break;
        }

        case alt::IMValue::Type::VECTOR3:
        {
            auto mVector3 = mValue.As<alt::IMValueVector3>()->Value();
            value = py::cast(Vector3(mVector3[0], mVector3[1], mVector3[2]));
        }

        case alt::IMValue::Type::BASE_OBJECT:
        {
            auto mBaseObject = mValue.As<alt::IMValueBaseObject>()->Value().Get();
            switch (mBaseObject->GetType())
            {

                case alt::IBaseObject::Type::PLAYER:
                    value = py::cast(Player(dynamic_cast<alt::IPlayer*>(mBaseObject)));
                    break;
                case alt::IBaseObject::Type::VEHICLE:
                    break;
                case alt::IBaseObject::Type::BLIP:
                    break;
                case alt::IBaseObject::Type::WEBVIEW:
                    break;
                case alt::IBaseObject::Type::VOICE_CHANNEL:
                    break;
                case alt::IBaseObject::Type::COLSHAPE:
                    break;
                case alt::IBaseObject::Type::CHECKPOINT:
                    break;
            }
            break;
        }
        case alt::IMValue::Type::FUNCTION:
        {
            auto mFunc = mValue.As<alt::IMValueFunction>();
            py::cpp_function pyFunc = [mFunc](const py::args& args)
            {
                alt::MValueArgs funcArgs;
                for (auto arg : args)
                {
                    funcArgs.Push(Utils::ValueToMValue(arg));
                }
                auto returnValue = mFunc->Call(funcArgs);
                return MValueToValue(returnValue);
            };
            value = pyFunc;
            break;
        }
        case alt::IMValue::Type::RGBA:
        {
            auto mRGBA = mValue.As<alt::IMValueRGBA>().Get()->Value();
            value = py::cast(RGBA(mRGBA.r, mRGBA.g, mRGBA.b, mRGBA.a));
            break;
        }
        case alt::IMValue::Type::BYTE_ARRAY:
            break;
    }
    return value;
}