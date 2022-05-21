#!/bin/bash
echo "hamada"
cmake -S . -B build
cd build
cmake --build . --parallel $(nproc)