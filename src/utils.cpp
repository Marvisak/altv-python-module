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
    } else
    {
        mValue = Core->CreateMValueNone();
    }
    return mValue;
}

void Utils::PushMValue(py::list &list, const alt::MValueConst &mValue) {
    switch(mValue->GetType())
    {
        case alt::IMValue::Type::NIL:
        case alt::IMValue::Type::NONE:
            list.append(py::none());
            break;
        case alt::IMValue::Type::BOOL:
            list.append(mValue.As<alt::IMValueBool>()->Value());
            break;
        case alt::IMValue::Type::INT:
            list.append(static_cast<int32_t>(mValue.As<alt::IMValueInt>()->Value()));
            break;
        case alt::IMValue::Type::UINT:
            list.append(static_cast<uint32_t>(mValue.As<alt::IMValueUInt>()->Value()));
            break;
        case alt::IMValue::Type::DOUBLE:
            list.append(mValue.As<alt::IMValueDouble>()->Value());
            break;
        case alt::IMValue::Type::STRING:
            list.append(mValue.As<alt::IMValueString>()->Value().ToString());
            break;
        case alt::IMValue::Type::LIST:
            auto mList = mValue.As<alt::IMValueList>();
            py::list pyList;
            for (size_t i = 0; i < mList->GetSize(); i++)
            {
                pyList.append(mList->Get(i));
            }
            list.append(pyList);
            break;
    }
}