cmake_minimum_required(VERSION 3.10)

project(SafeAVR C)

set(ROOT_DIR ..)

if(NOT DEFINED DEVICE)
    set(DEVICE uno)
endif()

include(../Avr.cmake)

add_avr_library(safeavr_gpio assert.c gpio.c gpio_registers.c)
target_include_directories(safeavr_gpio PUBLIC ${ROOT_DIR}/include)
