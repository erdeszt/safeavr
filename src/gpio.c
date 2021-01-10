#include "safeavr/assert.h"
#include "safeavr/defs.h"
#include "safeavr/gpio.h"

static inline _Bool is_pin_mode_output(const struct gpio_definition *gpio,
                                       const enum gpio_pin pin)
{
    return IS_BIT_SET(gpio->direction_register, (const u8)pin);
}

static inline _Bool is_pin_mode_input(const struct gpio_definition *gpio,
                                      const enum gpio_pin pin)
{
    return IS_BIT_CLEAR(gpio->direction_register, (const u8)pin);
}

static inline _Bool is_valid_pin(const enum gpio_pin pin)
{
    _Bool result = FALSE;

    switch (pin) {
    case PIN0:
    case PIN1:
    case PIN2:
    case PIN3:
    case PIN4:
    case PIN5:
    case PIN6:
    case PIN7:
        result = TRUE;
        break;
    default:
        result = FALSE;
        break;
    }

    return result;
}

void gpio_init(struct gpio_definition *gpio,
               const struct gpio_init_config *config)
{
    // TODO: Check
    assert(gpio);

    // TODO: Set all pins
    if (config->direction == OUTPUT) {
        SET_BIT(gpio->direction_register, (const u8)config->pin);
    } else {
        CLEAR_BIT(gpio->direction_register, (const u8)config->pin);
    }
}

void gpio_write(struct gpio_definition *gpio, const enum gpio_pin pin,
                const enum logic_level level)
{
    assert(is_valid_pin(pin));

    // TODO: Checks
    assert(gpio);
    assert(is_pin_mode_output(gpio, pin));

    if (level == LOW) {
        CLEAR_BIT(gpio->output_register, (const u8)pin);
    } else {
        SET_BIT(gpio->output_register, (const u8)pin);
    }
}

void gpio_set_high(struct gpio_definition *gpio, const enum gpio_pin pin)
{
    assert(is_valid_pin(pin));

    // TODO: Checks
    assert(gpio);
    assert(is_pin_mode_output(gpio, pin));

    SET_BIT(gpio->output_register, (const u8)pin);
}

void gpio_set_low(struct gpio_definition *gpio, const enum gpio_pin pin)
{
    assert(is_valid_pin(pin));

    // TODO: Checks
    assert(gpio);
    assert(is_pin_mode_output(gpio, pin));

    CLEAR_BIT(gpio->output_register, (const u8)pin);
}

enum logic_level gpio_read(const struct gpio_definition *gpio,
                           const enum gpio_pin pin)
{
    assert(is_valid_pin(pin));

    // TODO: Checks
    assert(gpio);
    assert(is_pin_mode_input(gpio, pin));

    return IS_BIT_SET(gpio->input_register, (const u8)pin);
}
