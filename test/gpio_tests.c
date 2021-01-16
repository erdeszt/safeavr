#include <unity.h>
#include <safeavr/gpio.h>

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
    TEST_FAIL_MESSAGE("PANIC");
}

void test_gpio_init_single_pin_all_positions(void)
{
    /* Check all the pins */
    for (u8 current_pin = (u8)PIN0; current_pin <= (u8)PIN7; current_pin++) {
        struct gpio_init_config test_pin = { .mode = GPIO_OUTPUT,
                                             .pin =
                                                 (enum gpio_pin)current_pin };
        enum gpio_status status = gpio_init(GPIOB, &test_pin);

        TEST_ASSERT_EQUAL(status, GPIO_SUCCESS);

        for (u8 pin = (u8)PIN0; pin <= (u8)PIN7; pin++) {
            /* If this is the current pin, it should be set,
             * otherwise it should be cleared.
             */
            if (pin == current_pin) {
                TEST_ASSERT_BIT_HIGH(pin, GPIOB->direction_register);
            } else {
                TEST_ASSERT_BIT_LOW(pin, GPIOB->direction_register);
            }
        }

        clear_registers();
    }
}

void test_gpio_init_invalid_gpio(void)
{
    struct gpio_init_config test_pin = { .mode = GPIO_OUTPUT, .pin = PIN0 };
    enum gpio_status status = gpio_init(NULL, &test_pin);

    TEST_ASSERT_EQUAL(status, GPIO_INVALID_DEFINITION);
}

void setUp(void)
{
    clear_registers();
}

void tearDown(void)
{
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_gpio_init_single_pin_all_positions);
    RUN_TEST(test_gpio_init_invalid_gpio);

    return UNITY_END();
}

