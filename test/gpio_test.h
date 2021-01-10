#include <unity.h>
#include <safeavr/gpio.h>

static struct gpio_init_config test_pin = { .direction = OUTPUT, .pin = PIN0 };

void test_gpio_init_single_pin(void)
{
    gpio_init(GPIOB, &test_pin);

    TEST_ASSERT_BIT_HIGH(0, GPIOB->direction_register);

    for (u8 bit = 1; bit < 8; bit++) {
        TEST_ASSERT_BIT_LOW(bit, GPIOB->direction_register);
    }
}

void test_gpio_init_invalid_gpio(void)
{
    // gpio_init(NULL, &test_pin);

    // TEST_ASSERT_FALSE(paniced);
}