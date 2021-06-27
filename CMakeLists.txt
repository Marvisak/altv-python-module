cmake_minimum_required(VERSION 3.1)

project(python-module)
SET(PROJECT_MODULE_NAME python-module)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DMODULE_NAME="${PROJECT_MODULE_NAME}")
add_definitions(-D_CRT_SECURE_NO_WARNINGS)


file(GLOB_RECURSE PROJECT_SOURCE_FILES "./src/*.h" "./src/*.hpp" "./src/*.cpp")

include_directories(
        "${PROJECT_SOURCE_DIR}/src"
        "${PROJECT_SOURCE_DIR}/vendors/cpp-sdk"
        "${PROJECT_SOURCE_DIR}/vendors/pybind11/include"
        "${PROJECT_SOURCE_DIR}/vendors/cpython/include"
)

link_directories(
        "${PROJECT_SOURCE_DIR}/vendors/cpython/lib"
)

add_library(
        ${PROJECT_MODULE_NAME} SHARED
        ${PROJECT_SOURCE_FILES}
)
