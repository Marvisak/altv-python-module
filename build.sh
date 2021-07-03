if [ ! -d "./build" ]; then
    mkdir build
fi

cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
cd ..

if [ ! -d "./dist" ]; then
    mkdir dist
fi

cp build/python-module.so dist
