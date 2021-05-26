#! /bin/bash

rm -rf build
rm -rf bin
mkdir build
mkdir bin
cp ./primes.txt ./bin
cd build
cmake ..
make
cd -
./bin/les4

