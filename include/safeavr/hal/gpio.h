#ifndef SAFEAVR_HAL_GPIO_H
#define SAFEAVR_HAL_GPIO_H

#include "safeavr/core/types.h"

/*
 * Logic level of the GPIO pin
 */
enum gpio_logic_level { GPIO_LOW = 0, GPIO_HIGH = 1 };

/*
 * Definition of GPIO pin modes
 *
 * Requirement:1.1.1.1
 */
enum gpio_mode {
    GPIO_INPUT = 0,
    GPIO_OUTPUT = 1,
};

/*
 * Definition of the individual pins within the GPIO ports
 */
enum gpio_pin {
    PIN0 = 0,
    PIN1 = 1,
    PIN2 = 2,
    PIN3 = 3,
    PIN4 = 4,
    PIN5 = 5,
    PIN6 = 6,
    PIN7 = 7,
};

/*
 * Configuration for initializing GPIO pins.
 * The member `pin` can contain multiple 1 bits and the corresponding pins
 * will be set to the configured `direction`.
 */
struct gpio_init_config {
    enum gpio_mode mode;
    enum gpio_pin pin;
};

/*
 * Initialize one more GPIO pins to the selected mode.
 * GPIO pins have to be initialized before any read/write operations.
 *
 * Requirement:1.1.1.1
 */
void gpio_init(struct gpio_definition *gpio,
               const struct gpio_init_config *config);

/*
 * Write the selected logic level to the specified GPIO pin.
 * The pin has to be initialized as output.
 *
 * Requirement:1.1.1.2
 */
void gpio_write(struct gpio_definition *gpio, const enum gpio_pin pin,
                const enum gpio_logic_level value);

/*
 * Reads the logic level of the GPIO pin.
 * The pin has to be initialized as input.
 *
 * Requirement:1.1.1.3
 */
enum gpio_logic_level gpio_read(const struct gpio_definition *gpio,
                                const enum gpio_pin pin);

#endif /* SAFEAVR_HAL_GPIO_H */
