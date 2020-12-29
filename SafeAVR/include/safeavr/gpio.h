/*
 * gpio.h
 *
 * Created: 12/29/2020 12:32:22 PM
 *  Author: erdeszt
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "safeavr/defs.h"

enum gpio_direction {
    INPUT = 0,
    OUTPUT = 1,
};

enum gpio_level {
    LOW = 0,
    HIGH = 1,
};

struct gpio_definition {
    volatile uint8_t input_register;
    volatile uint8_t direction_register;
    volatile uint8_t output_register;
};

struct gpio_init_config {
    enum gpio_direction direction;
    uint8_t pin;
};

#define SFR_OFFSET 0x20
#define GPIOB_BASE_ADDRESS 0x23
#define GPIOB ((struct gpio_definition *)GPIOB_BASE_ADDRESS)

#define PIN1 (1 << 1)
#define PIN2 (1 << 2)
#define PIN3 (1 << 3)
#define PIN4 (1 << 4)
#define PIN5 (1 << 5)
#define PIN6 (1 << 6)
#define PIN7 (1 << 7)
#define PIN8 (1 << 8)

#define IS_VALID_PIN(PIN) ((PIN) >= 0 && (PIN) < 8)

void gpio_init(struct gpio_definition *, const struct gpio_init_config *);
void gpio_write(struct gpio_definition *, const uint8_t, const enum gpio_level);

#endif /* GPIO_H_ */
