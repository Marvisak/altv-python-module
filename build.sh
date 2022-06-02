if [ ! -d "./build" ]; then
    mkdir build
fi

cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
cmake --build . --config Release
cd ..

if [ ! -d "./dist" ]; then
    mkdir -p dist/python
fi

cp build/python-module.so dist
cp build/Python-3.*.*/libpython3.*.so.1.0 dist
cp -r build/Python-3.*.*/Lib/* dist/python
cp -r build/Python-3.*.*/build/lib.linux-x86_64-3.*/* dist/python


# This is huge absolutely useless directory
rm -rf dist/python/test
rm -rf dist/python/__pycache__
