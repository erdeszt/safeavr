#!/bin/bash

set -e

mkdir -p test_build
pushd test_build
cmake ../test
make
ctest --output-on-failure
popd
