#include "safeavr_config.h"
#include <safeavr.h>
#include <CppUTest/TestHarness.h>
#include <CppUTest/CommandLineTestRunner.h>
#include <vector>

const std::vector<enum gpio_pin> pins = { PIN0, PIN1, PIN2, PIN3,
                                          PIN4, PIN5, PIN6, PIN7 };
const std::vector<enum gpio_mode> modes = { GPIO_INPUT, GPIO_OUTPUT };
const std::vector<enum gpio_logic_level> levels = { GPIO_LOW, GPIO_HIGH };

struct PanicException : public std::exception {
    const char *what() const throw()
    {
        return "panic was called";
    }
};

void clear_registers()
{
    GPIOB->direction_register = 0;
    GPIOB->input_register = 0;
    GPIOB->output_register = 0;
    GPIOC->direction_register = 0;
    GPIOC->input_register = 0;
    GPIOC->output_register = 0;
    GPIOD->direction_register = 0;
    GPIOD->input_register = 0;
    GPIOD->output_register = 0;
}

void panic(void)
{
    throw PanicException();
}

// clang-format off
TEST_GROUP(GpioBlackBox)
{
    void setup(void)
    {
        clear_registers();
    }
};

TEST_GROUP(GpioWhiteBox)
{
    void setup(void)
    {
        clear_registers();
    }
};
// clang-format on

TEST(GpioBlackBox, init_all_pins_all_modes)
{
    for (const auto pin : pins) {
        for (const auto mode : modes) {
            const struct gpio_init_config config = { .mode = mode, .pin = pin };

            gpio_init(GPIOB, &config);
        }
    }
}

TEST(GpioBlackBox, init_with_invalid_definition)
{
    const struct gpio_init_config config = { .mode = GPIO_OUTPUT, .pin = PIN0 };

    CHECK_THROWS(PanicException, gpio_init(NULL, &config));
}

TEST(GpioBlackBox, init_with_invalid_mode)
{
    const struct gpio_init_config config = { .mode = (enum gpio_mode)100,
                                             .pin = PIN0 };

    CHECK_THROWS(PanicException, gpio_init(GPIOB, &config));
}

TEST(GpioBlackBox, init_with_invalid_pin)
{
    const struct gpio_init_config config = { .mode = GPIO_OUTPUT,
                                             .pin = (enum gpio_pin)100 };

    CHECK_THROWS(PanicException, gpio_init(GPIOB, &config));
}

TEST(GpioBlackBox, write_all_pins_all_levels)
{
    for (const auto pin : pins) {
        for (const auto level : levels) {
            const struct gpio_init_config config = { .mode = GPIO_OUTPUT,
                                                     .pin = pin };
            gpio_init(GPIOB, &config);

            gpio_write(GPIOB, pin, level);
        }
    }
}

TEST(GpioBlackBox, write_invalid_definition)
{
    CHECK_THROWS(PanicException, gpio_write(NULL, PIN0, GPIO_LOW));
}

TEST(GpioBlackBox, write_invalid_pin)
{
    const struct gpio_init_config config = { .mode = GPIO_OUTPUT, .pin = PIN0 };

    gpio_init(GPIOB, &config);

    CHECK_THROWS(PanicException,
                 gpio_write(GPIOB, (enum gpio_pin)100, GPIO_LOW));
}

TEST(GpioBlackBox, write_invalid_mode)
{
    const struct gpio_init_config config = { .mode = GPIO_INPUT, .pin = PIN0 };

    gpio_init(GPIOB, &config);

    CHECK_THROWS(PanicException, gpio_write(GPIOB, PIN0, GPIO_LOW));
}

TEST(GpioBlackBox, read_all_pins)
{
    for (const auto pin : pins) {
        const struct gpio_init_config config = { .mode = GPIO_INPUT,
                                                 .pin = pin };
        gpio_init(GPIOB, &config);

        const enum gpio_logic_level level = gpio_read(GPIOB, pin);

        CHECK_EQUAL(level, GPIO_LOW);
    }
}

TEST(GpioBlackBox, read_invalid_definition)
{
    CHECK_THROWS(PanicException, gpio_read(NULL, PIN0));
}

TEST(GpioBlackBox, read_invalid_pin)
{
    const struct gpio_init_config config = { .mode = GPIO_INPUT, .pin = PIN0 };

    gpio_init(GPIOB, &config);

    CHECK_THROWS(PanicException, gpio_read(NULL, PIN0));
}

TEST(GpioBlackBox, read_invalid_mode)
{
    const struct gpio_init_config config = { .mode = GPIO_OUTPUT, .pin = PIN0 };

    gpio_init(GPIOB, &config);

    CHECK_THROWS(PanicException, gpio_read(GPIOB, PIN0));
}

int main(int argc, char **argv)
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

