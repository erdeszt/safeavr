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
target_link_libraries(blink.elf safeavr_hal_gpio safeavr_hal_usart)

add_avr_executable(serial ${DEVICE} examples/serial.c)
target_include_directories(serial.elf PUBLIC include)
target_link_libraries(serial.elf safeavr_hal_gpio safeavr_hal_usart)
