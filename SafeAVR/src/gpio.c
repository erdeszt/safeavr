/*
 * gpio.c
 *
 * Created: 12/29/2020 7:05:51 PM
 *  Author: erdeszt
 */

#include "safeavr/assert.h"
#include "safeavr/defs.h"
#include "safeavr/gpio.h"

void gpio_init(struct gpio_definition *gpio,
               const struct gpio_init_config *config)
{
    assert(gpio);
    assert(IS_VALID_PIN(config->pin));

    if (config->direction == OUTPUT) {
        SET_BIT(gpio->direction_register, config->pin);
    } else {
        CLEAR_BIT(gpio->direction_register, config->pin);
    }
}

void gpio_write(struct gpio_definition *gpio, const uint8_t pin,
                const enum gpio_level level)
{
    assert(gpio);
    assert(IS_VALID_PIN(pin));
    assert(IS_BIT_SET(gpio->direction_register, pin));

    if (level == LOW) {
        CLEAR_BIT(gpio->output_register, pin);
    } else {
        SET_BIT(gpio->output_register, pin);
    }
}
