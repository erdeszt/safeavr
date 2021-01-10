cmake_minimum_required(VERSION 3.10)

project(SafeAVRRoot C)

include(Avr.cmake)

if(NOT DEFINED DEVICE)
    set(DEVICE uno)
endif()

# TODO: Split file into libs and examples
add_avr_library(safeavr_gpio src/gpio.c)

target_include_directories(safeavr_gpio PUBLIC include)

add_avr_executable(raw ${DEVICE} examples/raw.c)

add_avr_executable(blink ${DEVICE} examples/blink.c)

target_include_directories(blink.elf PUBLIC include)

target_link_libraries(blink.elf safeavr_gpio)
