#!/bin/bash

pushd check

for filename in ../SafeAVR/src/*.c; do
  cppcheck --enable=all --std=c99 --addon=misra -I../SafeAvr/include ${filename} 
done

for filename in ../Examples/*.c; do
  cppcheck --enable=all --std=c99 --addon=misra -I../SafeAvr/include ${filename} 
done

popd
