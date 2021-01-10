cmake_minimum_required(VERSION 3.10)

project(SafeAVRRoot C)

set(ROOT_DIR .)

if(NOT DEFINED DEVICE)
    set(DEVICE uno)
endif()

include(Avr.cmake)

add_subdirectory(src)

add_avr_executable(blink ${DEVICE} examples/blink.c)
target_include_directories(blink.elf PUBLIC include)
target_link_libraries(blink.elf safeavr_gpio)
