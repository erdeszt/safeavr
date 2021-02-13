#include "safeavr/core/gpio.h"

/*
 * The offset of the memory mapped IO registers
 */
#define SFR_OFFSET 0x20

#define GPIOB_BASE_ADDRESS (SFR_OFFSET + 0x03)
#define GPIOC_BASE_ADDRESS (SFR_OFFSET + 0x06)
#define GPIOD_BASE_ADDRESS (SFR_OFFSET + 0x09)

struct gpio_definition *GPIOB = (struct gpio_definition *)GPIOB_BASE_ADDRESS;
struct gpio_definition *GPIOC = (struct gpio_definition *)GPIOC_BASE_ADDRESS;
struct gpio_definition *GPIOD = (struct gpio_definition *)GPIOD_BASE_ADDRESS;
