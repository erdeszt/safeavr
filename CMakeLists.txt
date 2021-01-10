cmake_minimum_required(VERSION 3.10)

project(SafeAVRRoot C)

include(Avr.cmake)

add_avr_executable(raw uno examples/raw.c)
