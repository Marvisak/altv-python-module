#pragma once

#include "main.h"
#include "utils.h"

uint32_t Hash(const std::string& str) {
    return alt::ICore::Instance().Hash(str);
}

void RegisterHelpersFunctions(py::module_ m) {
    m.def("hash", &Hash);
}
