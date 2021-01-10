cmake_minimum_required(VERSION 3.10)

project(SafeAVRRoot C)

include(Avr.cmake)

if(NOT DEFINED DEVICE)
    set(DEVICE uno)
endif()

add_avr_library(safeavr_gpio src/gpio.c src/gpio_registers.c)
target_include_directories(safeavr_gpio PUBLIC include)

add_avr_executable(blink ${DEVICE} examples/blink.c)
target_include_directories(blink.elf PUBLIC include)
target_link_libraries(blink.elf safeavr_gpio)
