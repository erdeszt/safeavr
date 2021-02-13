#include "safeavr_config.h"
#include <safeavr/hal.h>

struct gpio_definition gpio_b_mock = {
    .input_register = 0u,
    .direction_register = 0u,
    .output_register = 0u,
};

struct gpio_definition gpio_c_mock = {
    .input_register = 0u,
    .direction_register = 0u,
    .output_register = 0u,
};

struct gpio_definition gpio_d_mock = {
    .input_register = 0u,
    .direction_register = 0u,
    .output_register = 0u,
};

struct gpio_definition *GPIOB = &gpio_b_mock;
struct gpio_definition *GPIOC = &gpio_c_mock;
struct gpio_definition *GPIOD = &gpio_d_mock;
