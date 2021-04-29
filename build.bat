@echo off
IF NOT EXIST build\ (
    mkdir build
)
pushd build
cmake -G"Visual Studio 16" -DSERVER_MODULE=1 -DPYTHON_EXECUTABLE="../vendors/cpython/lib/python.exe" -A x64 ..
cmake --build . --config Release
popd