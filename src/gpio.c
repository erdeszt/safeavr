#include "safeavr/assert.h"
#include "safeavr/defs.h"
#include "safeavr/gpio.h"

/*
 * TODO: Separate file for testabily
 */
struct gpio_definition *GPIOB = (struct gpio_definition *)GPIOB_BASE_ADDRESS;
struct gpio_definition *GPIOC = (struct gpio_definition *)GPIOC_BASE_ADDRESS;
struct gpio_definition *GPIOD = (struct gpio_definition *)GPIOD_BASE_ADDRESS;

static inline _Bool is_pin_mode_output(const struct gpio_definition *gpio,
                                       const u8 pin)
{
    return IS_BIT_SET(gpio->direction_register, pin);
}

static inline _Bool is_pin_mode_input(const struct gpio_definition *gpio,
                                      const u8 pin)
{
    return IS_BIT_CLEAR(gpio->direction_register, pin);
}

static inline _Bool is_valid_pin(const u8 pin)
{
    return pin && !(pin & (pin - 1U));
}

void gpio_init(struct gpio_definition *gpio,
               const struct gpio_init_config *config)
{
    assert(gpio);

    /* TODO: Set all the pins */

    if (config->direction == OUTPUT) {
        SET_BIT(gpio->direction_register, config->pin);
    } else {
        CLEAR_BIT(gpio->direction_register, config->pin);
    }
}

void gpio_write(struct gpio_definition *gpio, const u8 pin,
                const enum logic_level level)
{
    assert(gpio);
    assert(is_valid_pin(pin));
    assert(is_pin_mode_output(gpio, pin));

    if (level == LOW) {
        CLEAR_BIT(gpio->output_register, pin);
    } else {
        SET_BIT(gpio->output_register, pin);
    }
}

void gpio_set_high(struct gpio_definition *gpio, const u8 pin)
{
    assert(gpio);
    assert(is_valid_pin(pin));
    assert(is_pin_mode_output(gpio, pin));

    SET_BIT(gpio->output_register, pin);
}

void gpio_set_low(struct gpio_definition *gpio, const u8 pin)
{
    assert(gpio);
    assert(is_valid_pin(pin));
    assert(is_pin_mode_output(gpio, pin));

    CLEAR_BIT(gpio->output_register, pin);
}

enum logic_level gpio_read(const struct gpio_definition *gpio,
                           const u8 pin)
{
    assert(gpio);
    assert(is_valid_pin(pin));
    assert(is_pin_mode_input(gpio, pin));

    return IS_BIT_SET(gpio->input_register, pin);
}
