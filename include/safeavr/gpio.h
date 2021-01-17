#ifndef SAFEAVR_GPIO_H_
#define SAFEAVR_GPIO_H_

#include "safeavr/defs.h"

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

enum gpio_status {
    GPIO_SUCCESS = 0,
    GPIO_INVALID_DEFINITION = 1,
    GPIO_INVALID_MODE = 2,
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
    enum gpio_mode mode;
    enum gpio_pin pin;
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
 * Initialize one more GPIO pins to the selected mode.
 * GPIO pins have to be initialized before any read/write operations.
 *
 * Requirement:1.1.1.1
 */
enum gpio_status gpio_init(struct gpio_definition *gpio,
                           const struct gpio_init_config *config);

/*
 * Write the selected logic level to the specified GPIO pin.
 * The pin has to be initialized as output.
 *
 * Requirement:1.1.1.2
 */
enum gpio_status gpio_write(struct gpio_definition *gpio,
                            const enum gpio_pin pin,
                            const enum gpio_logic_level value);

/*
 * Reads the logic level of the GPIO pin.
 * The pin has to be initialized as input.
 *
 * Requirement:1.1.1.3
 */
enum gpio_status gpio_read(const struct gpio_definition *gpio,
                           const enum gpio_pin pin,
                           enum gpio_logic_level *level);

#endif /* SAFEAVR_GPIO_H_ */
