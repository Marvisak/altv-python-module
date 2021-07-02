@echo off
IF NOT EXIST build\ (
    mkdir build
)
pushd build
cmake -G"Visual Studio 16" -A x64 ..
cmake --build . --config Release
popd

IF NOT EXIST dist\ (
    mkdir dist
)
copy build\Release\python-module.dll dist