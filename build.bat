
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

set pythonPath=build\Python-3.10.6

copy build\Release\python-module.dll dist
copy %pythonPath%\PCbuild\amd64\python310.dll dist\python
copy %pythonPath%\PCbuild\amd64\python3.dll dist\python

rmdir /s /q %pythonPath%\Lib\test
rmdir /s /q %pythonPath%\Lib\__pycache__

pushd %pythonPath%\Lib
tar -acf ..\..\..\dist\python\libs.zip *
popd
xcopy %pythonPath%\PCbuild\amd64\*.pyd dist\python /Y > nul
xcopy %pythonPath%\PCbuild\amd64\lib*.dll dist\python /Y > nul

