#!/bin/bash
echo "hamada"
cmake -S . -B build -D CMAKE_BUILD_TYPE=Debug
cd build
cmake --build . --parallel $(nproc)