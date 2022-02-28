#pragma once

#include "main.hpp"
#include "utils.hpp"

uint32_t Hash(const std::string& str) {
    return alt::ICore::Instance().Hash(str);
}

void RegisterHelpersFunctions(py::module_ m) {
    m.def("hash", &Hash);
}
