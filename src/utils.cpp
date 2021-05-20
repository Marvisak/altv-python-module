#include <utils.h>


PythonResource* Utils::GetResourceFromFrame(PyFrameObject *frame) {
    PyObject *filename = frame->f_code->co_filename;
    PyObject* byteStr = PyUnicode_AsEncodedString(filename, "utf-8", "~E~");
    std::string fullPath = PyBytes_AS_STRING(byteStr);
    PythonResource* resource = PythonRuntime::GetInstance()->GetPythonResourceFromPath(fullPath);
    return resource;
}

alt::MValue Utils::ArgToMValue(const pybind11::handle &arg) {
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
            tempList->Push(ArgToMValue(element));
        }
        mValue = tempList;
    } else if (type == "dict")
    {
        auto tempDict = Core->CreateMValueDict();
        auto dict = arg.cast<py::dict>();
        for (auto item : dict)
        {
            tempDict->Set(item.first.cast<std::string>(), ArgToMValue(item.second));
        }
        mValue = tempDict;
    }

    else
    {
        mValue = Core->CreateMValueNone();
    }
    return mValue;
}

py::object Utils::MValueToValue(const alt::MValueConst &mValue) {
    py::object value;
    switch(mValue->GetType())
    {
        case alt::IMValue::Type::NIL:
        case alt::IMValue::Type::NONE:
        {
            value = py::none();
            break;
        }
        case alt::IMValue::Type::BOOL:
        {
            value = py::bool_(mValue.As<alt::IMValueBool>()->Value());
            break;
        }

        case alt::IMValue::Type::INT:
        {
            value = py::int_(static_cast<int>(mValue.As<alt::IMValueInt>()->Value()));
            break;
        }

        case alt::IMValue::Type::UINT:
        {
            value = py::int_(static_cast<unsigned int>(mValue.As<alt::IMValueUInt>()->Value()));
            break;
        }
        case alt::IMValue::Type::DOUBLE:
        {
            value = py::float_(mValue.As<alt::IMValueDouble>()->Value());
            break;
        }
        case alt::IMValue::Type::STRING:
        {
            value = py::str(mValue.As<alt::IMValueString>()->Value().ToString());
            break;
        }

        case alt::IMValue::Type::LIST:
        {
            auto mList = mValue.As<alt::IMValueList>();
            py::list pyList;
            for (uint64_t i = 0; i < mList->GetSize(); i++)
            {
                pyList.append(MValueToValue(mList->Get(i)));
            }
            value = pyList;
            break;
        }

        case alt::IMValue::Type::DICT:
        {
            auto mDict = mValue.As<alt::IMValueDict>();
            py::dict pyDict;
            for(auto item = mDict->Begin(); item; item = mDict->Next())
            {
                auto dictVal = MValueToValue(item->GetValue().Get());
                pyDict[item->GetKey().CStr()] = dictVal;
            }
            value = pyDict;
            break;
        }
    }
    return value;
}