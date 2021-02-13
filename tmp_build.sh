#!/bin/bash

# -funsigned-char -funsigned-bitfields -fno-thread-safe-statics -fpack-structs -fshort-enums 

avr-gcc -c -g -Os -Wall -std=c99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -Iinclude -o build/tmp/usart.o src/usart.c
avr-gcc -c -g -Os -Wall -std=c99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -Iinclude -o build/tmp/gpio.o src/gpio.c
avr-gcc -c -g -Os -Wall -std=c99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -Iinclude -o build/tmp/gpio_registers.o src/gpio_registers.c
avr-gcc -c -g -Os -Wall -std=c99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -Iinclude -o build/tmp/assert.o src/assert.c
avr-gcc -c -g -Os -Wall -std=c99 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000UL -Iinclude -o build/tmp/serial.o examples/serial.c
avr-gcc -g -Os -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega328p  -o build/tmp/serial.elf build/tmp/gpio.o build/tmp/gpio_registers.o build/tmp/usart.o build/tmp/serial.o build/tmp/assert.o

avr-objcopy -O ihex -R .eeprom build/tmp/serial.elf build/tmp/serial.hex
avrdude -Cavrdude.conf -v -patmega328p -carduino -P/dev/ttyS4 -b115200 -D -Uflash:w:build/tmp/serial.hex:i
