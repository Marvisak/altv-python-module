if [ ! -d "./build" ]
then
    mkdir build
fi

cd build
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
cmake --build . --config Release
cd ..

if [ ! -d "./dist" ]
then
    mkdir -p dist/python
fi

cp build/python-module.so dist
cp build/Python-3.*.*/libpython3.*.so.1.0 dist/python

# This is huge absolutely useless directory
rm -rf build/Python-3.*.*/Lib/test
rm -rf build/Python-3.*.*/Lib/__pycache__

cd build/Python-3.*.*/Lib/
zip -rq ../../../dist/python/libs .
cd ..
cp -r build/lib.linux-x86_64-3.*/* ../../dist/python

