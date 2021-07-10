#pragma once

#include "main.h"

unsigned int Hash(const std::string& strToHash) {
    return Core->Hash(strToHash);
}

void RegisterHelpersFunctions(py::module_ m)
{
    // Getters
    m.attr("branch") = Core->GetBranch().ToString();
    m.attr("defaultDimension") = alt::DEFAULT_DIMENSION;
    m.attr("globalDimension") = alt::GLOBAL_DIMENSION;
    m.attr("rootDir") = Core->GetRootDirectory().ToString();
    m.attr("sdkVersion") = Core->SDK_VERSION;
    m.attr("version") = Core->GetVersion().ToString();

    // Methods
    m.def("hash", &Hash, "Hashes string");
}
