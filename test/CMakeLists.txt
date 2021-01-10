cmake_minimum_required(VERSION 3.10)

project(SafeAVRTest C)

include(../Flags.cmake)

enable_testing()

# SafeAVR library with mocks
add_library(safeavr_gpio_mocked ../src/gpio.c gpio_register_mocks.c)
set_target_properties(safeavr_gpio_mocked PROPERTIES COMPILE_FLAGS ${C_WARNING_FLAGS})
target_include_directories(safeavr_gpio_mocked PUBLIC ../include)

# Unity library
add_library(unity ../vendor/Unity/src/unity.c)
target_include_directories(unity PUBLIC ../vendor/Unity/src)

# Test suite executable
add_executable(test_suite test_suite.c)
target_link_libraries(test_suite safeavr_gpio_mocked unity)
target_include_directories(test_suite PUBLIC ../vendor/Unity/src ../include)
set_target_properties(test_suite PROPERTIES COMPILE_FLAGS ${C_WARNING_FLAGS})

add_test(NAME test_suite COMMAND test_suite)