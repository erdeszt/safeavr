#!/bin/bash

pushd check

for filename in ../SafeAVR/src/*; do
  cppcheck --enable=all --std=c99 --addon=misra -I../SafeAvr/include ${filename} 
done

popd
