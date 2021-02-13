# TODO:
* USART
  * RX
  * Tests
* real timer, dummy doesn't work in simulation tracing
  * Only delay ms for now
* Cleanup warnings in tests
* Add CppUTest as a git submodule
* github flow with tests
* Add build/test/dependencies instructions
* Cleanup simulation
  * cli arg for target file and mode(debug, run)
* Refine cppcheck unused warning supression for library functions
* MisraC compliance
  * Create compliance matrix
  * Document deviations for IO mapped registers (11.4)
  * Document deviation from single point of exit:
    * 15.1 for functions with resource allocation
    * 15.5 for functions with no resource allocation
  * Figure out how to suppress deviations in tool
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
