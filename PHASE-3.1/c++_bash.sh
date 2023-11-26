#!/bin/bash

cd ./code_output/
file_name="$1.cpp"
executable="$1.o"
echo "$executable"
g++ -std=c++20 -w compile.cpp "$file_name"  -I/usr/include/python3.10 -lpython3.10 -lpthread
./a.out
cd ..

