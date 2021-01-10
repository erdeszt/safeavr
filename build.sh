#!/bin/bash

set -e

mkdir -p build
pushd build
cmake -DCMAKE_TOOLCHAIN_FILE=../AvrToolchain.cmake ..
make
popd
