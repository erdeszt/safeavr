cmake_minimum_required(VERSION 3.10)

project(SafeAVRTest C)

include(../Flags.cmake)

enable_testing()

# SafeAVR library with mocks
add_library(safeavr_gpio_mocked ../src/gpio.c ../src/assert.c gpio_register_mocks.c)
set_target_properties(safeavr_gpio_mocked PROPERTIES COMPILE_FLAGS ${C_WARNING_FLAGS})
target_include_directories(safeavr_gpio_mocked PUBLIC ../include)

# Unity library
add_library(unity ../vendor/Unity/src/unity.c)
add_definitions(-DUNITY_INCLUDE_CONFIG_H)
target_include_directories(unity PUBLIC ../vendor/Unity/src)
target_include_directories(unity PUBLIC .)

# GPIO test suite executable
add_executable(gpio_tests gpio_tests.c)
target_link_libraries(gpio_tests safeavr_gpio_mocked unity)
target_include_directories(gpio_tests PUBLIC ../vendor/Unity/src ../include)
set_target_properties(gpio_tests PROPERTIES COMPILE_FLAGS ${C_WARNING_FLAGS})

add_test(NAME gpio_tests COMMAND gpio_tests)
