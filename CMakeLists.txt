cmake_minimum_required(VERSION 3.10)

project(SafeAVRRoot C)

add_subdirectory(SafeAVR)

add_executable(
    Example1
    Examples/main.c
)

target_link_libraries(Example1 SafeAVR)
