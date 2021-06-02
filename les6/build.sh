#! /bin/bash

rm -rf build
rm -rf bin
mkdir build
mkdir bin
cp ./f4.txt ./bin
cd build
cmake ..
make
cd -
./bin/les6 ./bin/f1.txt ./bin/f2.txt ./bin/f3.txt ./bin/f4.txt character
