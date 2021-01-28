cmake_minimum_required(VERSION 3.10)

project(SafeAVRSimulation C)

include(../Flags.cmake)

set(SIMAVR_ROOT "../vendor/simavr/simavr")
set(SIMAVR_SRC ${SIMAVR_ROOT}/sim)

add_library(simavr 
  ${SIMAVR_SRC}/avr_eeprom.c
  ${SIMAVR_SRC}/avr_flash.c
  ${SIMAVR_SRC}/avr_watchdog.c
  ${SIMAVR_SRC}/avr_extint.c
  ${SIMAVR_SRC}/avr_ioport.c
  ${SIMAVR_SRC}/avr_uart.c
  ${SIMAVR_SRC}/avr_acomp.c
  ${SIMAVR_SRC}/avr_adc.c
  ${SIMAVR_SRC}/avr_timer.c
  ${SIMAVR_SRC}/avr_spi.c
  ${SIMAVR_SRC}/avr_twi.c
  ${SIMAVR_SRC}/sim_elf.c 
  ${SIMAVR_SRC}/sim_avr.c 
  ${SIMAVR_SRC}/sim_io.c 
  ${SIMAVR_SRC}/sim_vcd_file.c
  ${SIMAVR_SRC}/sim_interrupts.c
  ${SIMAVR_SRC}/sim_core.c
  ${SIMAVR_SRC}/sim_cmds.c
  ${SIMAVR_SRC}/sim_gdb.c
  ${SIMAVR_SRC}/sim_cycle_timers.c
  ${SIMAVR_SRC}/sim_irq.c
  ${SIMAVR_SRC}/sim_utils.c
  ${SIMAVR_SRC}/sim_hex.c
  ${SIMAVR_ROOT}/cores/sim_megax8.c
  ${SIMAVR_ROOT}/cores/sim_mega328.c
)
target_include_directories(simavr PUBLIC ${SIMAVR_ROOT} ${SIMAVR_ROOT}/cores ${SIMAVR_SRC})
target_link_libraries(simavr elf)

# GPIO test suite executable

add_executable(simulation main.c)
target_include_directories(simulation PUBLIC ../vendor/simavr/simavr/sim)
target_link_libraries(simulation simavr)
set_target_properties(simulation PROPERTIES COMPILE_FLAGS ${C_WARNING_FLAGS})
