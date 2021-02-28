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
target_link_libraries(blink.elf safeavr_hal_gpio safeavr_hal_usart safeavr_hal_timer)

add_avr_executable(serial ${DEVICE} examples/serial.c)
target_include_directories(serial.elf PUBLIC include)
target_link_libraries(serial.elf safeavr_hal_gpio safeavr_hal_usart safeavr_hal_timer)

add_avr_executable(analog ${DEVICE} examples/analog.c)
target_include_directories(analog.elf PUBLIC include)
# TODO: USE ADC HAL
target_link_libraries(analog.elf safeavr_hal_gpio safeavr_hal_usart safeavr_hal_timer safeavr_core_adc)
