# TODO:
* USART
  * RX
  * Tests
* Cleanup warnings in tests
* Add CppUTest as a git submodule
* Improve github flow
  * werror on github
  * -fanalyzer gcc flag
  * Fixing cppcheck
* Add build/test/dependencies instructions
* Finish requirements for adc, timer, usart
* Cleanup simulation
  * cli arg for target file and mode(debug, run)
* Refine cppcheck unused warning supression for library functions
* MisraC compliance
  * Create compliance matrix
  * Document deviations for IO mapped registers (11.4)
  * Document deviation from single point of exit(??? not used atm):
    * 15.1 for functions with resource allocation
    * 15.5 for functions with no resource allocation
* Integration tests with simavr
* Complete cmake setup for the avr build
  * Move check to cmake
  * Release vs debug build

# Nice to have:
* Cmake link against specific libraries in examples
* Update cmake to support c++20
* More flexible usart, current limitations:
  * 9 bit mode not supported
  * Only fixed baud rates
  * 16Mhz clock assumed
  * Double speed mode not supported
* Check if it's possible to cmake without avr-libc
  * Try: https://stackoverflow.com/a/53635241/1278218
