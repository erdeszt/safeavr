# Based on: https://github.com/mkleemann/cmake-avr

cmake_minimum_required(VERSION 3.10)

set(C_WARNING_FLAGS "-Wall -Wextra -Wundef -Wshadow -Wdouble-promotion -pedantic")
set(C_GENERAL_FLAGS "-funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -fno-common")
set(C_OPTIMIZATION_FLAGS "-Os")

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
        COMPILE_FLAGS "-mmcu=${AVR_MCU} ${C_WARNING_FLAGS} ${C_GENERAL_FLAGS} ${C_OPTIMIZATION_FLAGS}"
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

    if(NOT ARGN)
        message(FATAL_ERROR "No source files given for ${LIBRARY_NAME}.")
    endif(NOT ARGN)

    set(lib_file ${LIBRARY_NAME})

    add_library(${lib_file} STATIC ${ARGN})

    set_target_properties(
        ${lib_file}
        PROPERTIES
        COMPILE_FLAGS "-mmcu=${AVR_MCU} ${C_WARNING_FLAGS} ${C_GENERAL_FLAGS} ${C_OPTIMIZATION_FLAGS}"
        OUTPUT_NAME "${lib_file}"
    )

    # TODO: Check if necessary
    # if(NOT TARGET ${LIBRARY_NAME})
    #     add_custom_target(
    #             ${LIBRARY_NAME}
    #             ALL
    #             DEPENDS ${lib_file}
    #     )

    #     set_target_properties(
    #             ${LIBRARY_NAME}
    #             PROPERTIES
    #             OUTPUT_NAME "${lib_file}"
    #     )
    # endif(NOT TARGET ${LIBRARY_NAME})

endfunction(add_avr_library)

function(avr_target_link_libraries EXECUTABLE_TARGET)

    if(NOT ARGN)
        message(FATAL_ERROR "Nothing to link to ${EXECUTABLE_TARGET}.")
    endif(NOT ARGN)

    get_target_property(TARGET_LIST ${EXECUTABLE_TARGET} OUTPUT_NAME)

    foreach(TGT ${ARGN})
        if(TARGET ${TGT})
            get_target_property(ARG_NAME ${TGT} OUTPUT_NAME)
            list(APPEND NON_TARGET_LIST ${ARG_NAME})
        else()
            list(APPEND NON_TARGET_LIST ${TGT})
        endif()
    endforeach()

    target_link_libraries(${TARGET_LIST} ${NON_TARGET_LIST})
endfunction(avr_target_link_libraries)

function(avr_target_include_directories EXECUTABLE_TARGET)
    if(NOT ARGN)
        message(FATAL_ERROR "No include directories to add to ${EXECUTABLE_TARGET}.")
    endif()

    get_target_property(TARGET_LIST ${EXECUTABLE_TARGET} OUTPUT_NAME)
    set(extra_args ${ARGN})

    target_include_directories(${TARGET_LIST} ${extra_args})
endfunction()
