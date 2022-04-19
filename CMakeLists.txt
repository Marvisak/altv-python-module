cmake_minimum_required(VERSION 3.1)

include(vendors/cpp-sdk/CMakeLists.txt)

project(python-module)
set(PROJECT_MODULE_NAME python-module)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_definitions(-DMODULE_NAME="${PROJECT_MODULE_NAME}")
add_definitions(-D_CRT_SECURE_NO_WARNINGS)


file(GLOB_RECURSE PROJECT_SOURCE_FILES "./src/*.h" "./src/*.hpp" "./src/*.cpp")


include_directories(
        "${PROJECT_SOURCE_DIR}/src"
        "${PROJECT_SOURCE_DIR}/vendors/cpp-sdk"
		"${PROJECT_SOURCE_DIR}/vendors/magic_enum/include"
)

add_subdirectory(
		${PROJECT_SOURCE_DIR}/vendors/pybind11
)

add_library(
        ${PROJECT_MODULE_NAME} SHARED
        ${PROJECT_SOURCE_FILES}
)


target_link_libraries(${PROJECT_MODULE_NAME} PRIVATE pybind11::embed)

add_dependencies(${PROJECT_MODULE_NAME} alt-sdk)

