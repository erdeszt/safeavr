#!/bin/bash

set -e

mkdir -p build/test
pushd build/test
cmake ../../test
make
ctest --output-on-failure
popd
