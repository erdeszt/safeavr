#!/bin/sh

for filename in SafeAVR/src/*; do
  cppcheck --enable=all --std=c99 --addon=misra -ISafeAvr/include ${filename} 
done
