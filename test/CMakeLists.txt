cmake_minimum_required(VERSION 3.10)

project(SafeAVRTest C CXX)

include(../Flags.cmake)

enable_testing()

# SafeAVR library with mocks
add_library(safeavr_gpio_mocked ../src/hal/gpio.c ../src/core/assert.c gpio_register_mocks.cpp)
set_target_properties(safeavr_gpio_mocked PROPERTIES COMPILE_FLAGS ${C_WARNING_FLAGS})
target_include_directories(safeavr_gpio_mocked PUBLIC ../include)
set_property(TARGET safeavr_gpio_mocked PROPERTY CXX_STANDARD 17)

# GPIO test suite executable
add_executable(gpio_tests gpio_tests.cpp)
target_link_libraries(gpio_tests safeavr_gpio_mocked CppUTest)
target_include_directories(gpio_tests PUBLIC ../include)
set_target_properties(gpio_tests PROPERTIES COMPILE_FLAGS ${C_WARNING_FLAGS})
set_property(TARGET gpio_tests PROPERTY CXX_STANDARD 17)

add_test(NAME gpio_tests COMMAND gpio_tests)
