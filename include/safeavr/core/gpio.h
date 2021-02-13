#ifndef SAFEAVR_CORE_GPIO_H
#define SAFEAVR_CORE_GPIO_H

#include "safeavr/core/types.h"

/*
 * Memory mapping of GPIO ports.
 * Each port includes a direction register to configure pins as input or output,
 * an input register for reading the logic level of the pins and an output register
 * for setting the logic level of the pins.
 *
 * Requirement:1.1.1
 */
struct gpio_definition {
    volatile u8 input_register;
    volatile u8 direction_register;
    volatile u8 output_register;
};

/*
 * Definition of the GPIO ports B, C and D
 *
 * Requirement:1.1.1
 */
extern struct gpio_definition *GPIOB;
extern struct gpio_definition *GPIOC;
extern struct gpio_definition *GPIOD;

#endif /* SAFEAVR_CORE_GPIO_H */
