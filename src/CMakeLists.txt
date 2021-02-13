cmake_minimum_required(VERSION 3.10)

project(SafeAVR C)

set(ROOT_DIR ..)

if(NOT DEFINED DEVICE)
    set(DEVICE uno)
endif()

include(../Avr.cmake)

add_avr_library(safeavr_core_gpio core/assert.c core/gpio.c)
target_include_directories(safeavr_core_gpio PUBLIC ${ROOT_DIR}/include)

add_avr_library(safeavr_hal_gpio core/assert.c core/gpio.c hal/gpio.c)
target_include_directories(safeavr_hal_gpio PUBLIC ${ROOT_DIR}/include)

add_avr_library(safeavr_core_usart core/assert.c core/usart.c)
target_include_directories(safeavr_core_usart PUBLIC ${ROOT_DIR}/include)

add_avr_library(safeavr_hal_usart core/assert.c core/usart.c hal/usart.c)
target_include_directories(safeavr_hal_usart PUBLIC ${ROOT_DIR}/include)
