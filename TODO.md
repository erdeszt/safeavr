* USART
* real timer, dummy doesn't work in simulation tracing
* github flow with tests
* Add build/test/dependencies instructions
* MisraC compliance
  * Create compliance matrix
  * Document deviations for IO mapped registers (11.4)
  * Document deviation from single point of exit:
    * 15.1 for functions with resource allocation
    * 15.5 for functions with no resource allocation
  * Figure out how to suppress deviations in tool
* Complete cmake setup for the avr build
  * Move check to cmake
  * Release vs debug build
* Refine cppcheck unused warning supression for library functions
* Add CppUTest as a git submodule
* Update cmake to support c++20
