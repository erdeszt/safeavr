/*
 * gpio.h
 *
 * Created: 12/29/2020 12:32:22 PM
 *  Author: erdeszt
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "defs.h"

/*
 * Definition of GPIO pin modes
 *
 * Requirement:1.1.1.1
 */
enum gpio_mode {
    INPUT = 0,
    OUTPUT = 1,
};

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
 * Configuration for initializing GPIO pins.
 * The member `pin` can contain multiple 1 bits and the corresponding pins
 * will be set to the configured `direction`.
 */
struct gpio_init_config {
    enum gpio_mode direction;
    u8 pin;
};

/*
 * The offset of the memory mapped IO addresses
 */
#define SFR_OFFSET 0x20

/*
 * Definition of the GPIO ports B, C and D
 *
 * Requirement:1.1.1
 */
#define GPIOB_BASE_ADDRESS (SFR_OFFSET + 0x03)
#define GPIOC_BASE_ADDRESS (SFR_OFFSET + 0x06)
#define GPIOD_BASE_ADDRESS (SFR_OFFSET + 0x09)

extern struct gpio_definition *GPIOB;
extern struct gpio_definition *GPIOC;
extern struct gpio_definition *GPIOD;

/*
 * Definition of the individual pins within the GPIO ports
 *
 * TODO: ENUM
 */
#define PIN1 (1U << 0U)
#define PIN2 (1U << 1U)
#define PIN3 (1U << 2U)
#define PIN4 (1U << 3U)
#define PIN5 (1U << 4U)
#define PIN6 (1U << 5U)
#define PIN7 (1U << 6U)
#define PIN8 (1U << 7U)

/*
 * Initialize one more GPIO pins to the selected mode.
 * GPIO pins have to be initialized before any read/write operations.
 *
 * Requirement:1.1.1.1
 */
void gpio_init(struct gpio_definition *, const struct gpio_init_config *);

/*
 * Write the selected logic level to the specified GPIO pin.
 * The pin has to be initialized as output.
 *
 * Requirement:1.1.1.2
 */
void gpio_write(struct gpio_definition *, const u8,
                const enum logic_level);

/*
 * Sets the GPIO pin to high logic level.
 * The pin has to be initialized as output.
 *
 * Requirement:1.1.1.2
 */
void gpio_set_high(struct gpio_definition *, const u8);

/*
 * Sets the GPIO pin to low logic level.
 * The pin has to be initialized as output.
 *
 * Requirement:1.1.1.2
 */
void gpio_set_low(struct gpio_definition *, const u8);

/*
 * Reads the logic level of the GPIO pin.
 * The pin has to be initialized as input.
 *
 * Requirement:1.1.1.3
 */
enum logic_level gpio_read(const struct gpio_definition *, const u8);

#endif /* GPIO_H_ */
