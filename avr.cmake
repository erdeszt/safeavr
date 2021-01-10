# Based on: https://github.com/mkleemann/cmake-avr

cmake_minimum_required(VERSION 3.10)

project(SafeAVRRoot C)

function(upload_avr_executable HEX_NAME DEVICE)

    if(DEVICE STREQUAL "uno")
        set(AVR_UPLOAD_PORT "/dev/ttyS4")
        set(AVR_UPLOAD_SPEED "115200")
    elseif(DEVICE STREQUAL "nano")
        set(AVR_UPLOAD_PORT "/dev/ttyS3")
        set(AVR_UPLOAD_SPEED "57600")
    else()
        message(FATAL_ERROR "Invalid or no device: '${DEVICE}'")
    endif()

    add_custom_target(
        upload_${HEX_NAME}
        ${AVR_UPLOADTOOL} -v -C${CMAKE_SOURCE_DIR}/avrdude.conf -p${AVR_MCU} -carduino -P${AVR_UPLOAD_PORT} -b${AVR_UPLOAD_SPEED} -D -Uflash:w:${HEX_NAME}:i
        DEPENDS ${HEX_NAME}
    )

endfunction(upload_avr_executable)

function(add_avr_executable EXECUTABLE_NAME DEVICE)

    if(NOT ARGN)
        message(FATAL_ERROR "No source files given for ${EXECUTABLE_NAME}.")
    endif(NOT ARGN)

    set(elf_file ${EXECUTABLE_NAME}.elf)
    set(hex_file ${EXECUTABLE_NAME}.hex)

    add_executable(${elf_file} ${ARGN})

    # TODO: Add -nostdinc
    set_target_properties(
        ${elf_file}
        PROPERTIES
        COMPILE_FLAGS "-mmcu=${AVR_MCU} -std=c99 -Wall -Wextra -Wundef -Wshadow -Wdouble-promotion -pedantic -funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -fno-common -Os"
        LINK_FLAGS "-mmcu=${AVR_MCU} -Wl,--gc-sections -Wl,--start-group -Wl,-lm -Wl,--end-group"
    )

    add_custom_command(
        OUTPUT ${hex_file}
        COMMAND ${AVR_OBJCOPY} -j .text -j .data -O ihex ${elf_file} ${hex_file}
        DEPENDS ${elf_file}
    )

    upload_avr_executable(${hex_file} ${DEVICE})

endfunction(add_avr_executable)

function(add_avr_library LIBRARY_NAME)
  
endfunction(add_avr_library)
