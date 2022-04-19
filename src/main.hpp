#pragma once

#define ALT_SERVER_API

// Standard C++ stuff
#include <iostream>
#include <map>
#include <string>

// AltV SDK
#include <SDK.h>

// Python API
#include <pybind11/stl.h>
#include <pybind11/embed.h>
#include <pybind11/operators.h>

namespace py = pybind11;
