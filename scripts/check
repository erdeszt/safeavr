#!/bin/bash

OPTS="--enable=all --std=c99 --addon=misra --suppressions-list=suppressions.txt -I../include"
ROOT=".."

pushd check

for filename in ${ROOT}/src/*.c; do
  cppcheck ${OPTS} ${filename}
done

for filename in ${ROOT}/examples/*.c; do
  cppcheck ${OPTS} ${filename}
done

popd
