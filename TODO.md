* Test
  * Finish GPIO tests
    * Turn assertions to unit tests where it makes sense
    * Consider different types of errors
    * enum return types for library functions
* Add parameter names to function protypes (MISRA 8.2,8.3)
* SimAVR
* USART
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
