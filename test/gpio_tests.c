#include <unity.h>
#include <safeavr/gpio.h>

static struct gpio_init_config test_pin = { .mode = GPIO_OUTPUT, .pin = PIN0 };

void setUp(void)
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

void tearDown(void)
{
}

void panic(void)
{
    TEST_FAIL_MESSAGE("PANIC");
}

void test_gpio_init_single_pin(void)
{
    enum gpio_status status = gpio_init(GPIOB, &test_pin);

    TEST_ASSERT_EQUAL(status, GPIO_SUCCESS);
    TEST_ASSERT_BIT_HIGH(0, GPIOB->direction_register);

    for (u8 bit = 1; bit < 8; bit++) {
        TEST_ASSERT_BIT_LOW(bit, GPIOB->direction_register);
    }
}

void test_gpio_init_invalid_gpio(void)
{
    // enum gpio_status status = gpio_init(NULL, &test_pin);
    // gpio_init(NULL, &test_pin);

    // TEST_ASSERT_FALSE(paniced);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_gpio_init_single_pin);
    RUN_TEST(test_gpio_init_invalid_gpio);

    return UNITY_END();
}

