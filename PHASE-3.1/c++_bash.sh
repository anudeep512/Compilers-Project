#!/bin/bash

cd ./codegen/
file_name="$1.cpp"
executable="$1.o"
g++ -w -o  "$executable" "$file_name" -std=c++20 -I/usr/include/python3.10 -lpython3.10 -lpthread
"$executable"

