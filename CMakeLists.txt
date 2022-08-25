cmake_minimum_required(VERSION 3.1)

include(vendors/cpp-sdk/CMakeLists.txt)
include(cmake/python.cmake)

project(python-module)
set(PROJECT_MODULE_NAME python-module)

set(PYTHON_VERSION 3.10.6)

message("Downloading and Compiling Python, this might take a while")
DownloadPython(${PYTHON_VERSION})
CompilePython(${PYTHON_VERSION})

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
		"${CMAKE_CURRENT_BINARY_DIR}/Python-${PYTHON_VERSION}/Include"
		"${PROJECT_SOURCE_DIR}/vendors/pybind11/include"
)

if (UNIX)
	include_directories("${CMAKE_CURRENT_BINARY_DIR}/Python-${PYTHON_VERSION}")
endif(UNIX)

if (WIN32)
	include_directories("${CMAKE_CURRENT_BINARY_DIR}/Python-${PYTHON_VERSION}/PC")
	set(CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE, x64)
endif(WIN32)

add_library(
		${PROJECT_MODULE_NAME} SHARED
		${PROJECT_SOURCE_FILES}
)

add_dependencies(${PROJECT_MODULE_NAME} alt-sdk)

if (WIN32)
	target_link_libraries(${PROJECT_MODULE_NAME} ${CMAKE_CURRENT_BINARY_DIR}/Python-${PYTHON_VERSION}/PCbuild/amd64/python310.lib)
endif(WIN32)

if (UNIX)
	target_link_libraries(${PROJECT_MODULE_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/Python-${PYTHON_VERSION}/libpython3.10.so)
endif(UNIX)
