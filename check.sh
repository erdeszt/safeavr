#!/bin/bash

OPTS="--enable=all --std=c99 --addon=misra --suppressions-list=suppressions.txt -I../SafeAVR/include"

pushd check

for filename in ../SafeAVR/src/*.c; do
  cppcheck ${OPTS} ${filename}
done

for filename in ../Examples/*.c; do
  cppcheck ${OPTS} ${filename}
done

popd
