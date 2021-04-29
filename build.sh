if [ ! -d "./build" ]; then
    mkdir build
fi
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DSERVER_MODULE=1 -DPYTHON_EXECUTABLE="../deps/cpython/lib/python.exe" ..
cmake --build . --config Release
cd ..