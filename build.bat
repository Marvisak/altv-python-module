
@echo off
IF NOT EXIST build\ (
    mkdir build
)
pushd build
cmake -A x64 ..
cmake --build . --config Release
popd

IF NOT EXIST dist\ (
    mkdir dist\python
)

set pythonPath=build\Python-3.10.5

copy build\Release\python-module.dll dist
copy %pythonPath%\PCbuild\amd64\python310.dll dist
xcopy %pythonPath%\Lib\* dist\python /E /Y > nul
xcopy %pythonPath%\PCbuild\amd64\*.pyd dist\python /Y > nul
xcopy %pythonPath%\PCbuild\amd64\lib*.dll dist\python /Y > nul

:: This is huge absolutely useless directory
rmdir /s /q dist\python\test
rmdir /s /q dist\python\__pycache__
