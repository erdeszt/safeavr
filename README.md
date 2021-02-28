# SafeAVR

(Somewhat)MISRA2012 compliant C library for AVR microcontrollers.

The library is composed of two parts: `core` and `hal`.

The `core` part is a replacement for [avr-libc](http://www.nongnu.org/avr-libc/) it provides bindings for the registers of the AVR MCU in a more structured way(structs & enums instead of macros to register addresses and bit values). It also helps with unit testing by avoiding the header only approach of `avr-libc` and instead splitting the interface from the actual bindings which can be replaced at link time.

The `hal` part is an abstraction layer built on top of `core` that hides some of the details of the underlying hardware and makes it easier to write portable code.

## Supported MCUs:

* ATMega328P

## Features:

* GPIO
* USART
* Timer
* ADC

## Install requirements:

* `gcc-avr`
* `binutils-avr`
* `avr-libc`
* `cmake`
* [Optional]`cppcheck`
* [Optional]`cpputest`

## Build:

```
> ./scripts/build
```

## Test:

```
> ./scripts/test
```

## Run static analyzers:
```
> ./scripts/check
```

