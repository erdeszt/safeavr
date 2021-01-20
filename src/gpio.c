#include "safeavr/assert.h"
#include "safeavr/defs.h"
#include "safeavr/gpio.h"

static inline boolean is_pin_mode_output(const struct gpio_definition *gpio,
                                         const enum gpio_pin pin)
{
    return IS_BIT_SET(gpio->direction_register, (const u8)pin);
}

static inline boolean is_pin_mode_input(const struct gpio_definition *gpio,
                                        const enum gpio_pin pin)
{
    return IS_BIT_CLEAR(gpio->direction_register, (const u8)pin);
}

static inline boolean is_valid_mode(const enum gpio_mode mode)
{
    return (mode == GPIO_INPUT) || (mode == GPIO_OUTPUT);
}

static inline boolean is_valid_pin(const enum gpio_pin pin)
{
    switch (pin) {
    case PIN0:
    case PIN1:
    case PIN2:
    case PIN3:
    case PIN4:
    case PIN5:
    case PIN6:
    case PIN7:
        return TRUE;
        break;
    default:
        return FALSE;
        break;
    }
}

void gpio_init(struct gpio_definition *gpio,
               const struct gpio_init_config *config)
{
    assert(gpio != NULL);
    assert(is_valid_mode(config->mode));
    assert(is_valid_pin(config->pin));

    if (config->mode == GPIO_OUTPUT) {
        SET_BIT(gpio->direction_register, (const u8)config->pin);
    } else {
        CLEAR_BIT(gpio->direction_register, (const u8)config->pin);
    }
}

void gpio_write(struct gpio_definition *gpio, const enum gpio_pin pin,
                const enum gpio_logic_level level)
{
    assert(gpio != NULL);
    assert(is_valid_pin(pin));
    assert(is_pin_mode_output(gpio, pin));

    if (level == GPIO_LOW) {
        CLEAR_BIT(gpio->output_register, (const u8)pin);
    } else {
        SET_BIT(gpio->output_register, (const u8)pin);
    }
}

enum gpio_logic_level gpio_read(const struct gpio_definition *gpio,
                                const enum gpio_pin pin)
{
    assert(gpio != NULL);
    assert(is_valid_pin(pin));
    assert(is_pin_mode_input(gpio, pin));

    return (enum gpio_logic_level)IS_BIT_SET(gpio->input_register,
                                             (const u8)pin);
}

