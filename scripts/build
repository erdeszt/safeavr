#!/bin/bash

set -e

mkdir -p build/examples
pushd build/examples
cmake -DCMAKE_TOOLCHAIN_FILE=../../AvrToolchain.cmake ../..
make
popd
