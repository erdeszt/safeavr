project(SafeAVR C)

add_library(
    SafeAVR
    include/safeavr/assert.h
    include/safeavr/defs.h
    include/safeavr/gpio.h
    src/gpio.c
    )

target_include_directories(
    SafeAVR PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)