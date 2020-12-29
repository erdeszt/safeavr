/*
 * gpio.h
 *
 * Created: 12/29/2020 12:32:22 PM
 *  Author: erdeszt
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <safeavr/defs.h>

enum gpio_direction {
    INPUT = 0,
    OUTPUT = 1,
};

struct gpio_definition {
    volatile uint8_t mode_register;
    volatile uint8_t input_register;
    volatile uint8_t output_register;
};

#endif /* GPIO_H_ */
