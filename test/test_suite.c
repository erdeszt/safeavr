#include <unity.h>
#include "gpio_test.h"

void setUp(void);
void tearDown(void);
void panic(void);

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_gpio_init_single_pin);
    RUN_TEST(test_gpio_init_invalid_gpio);

    return UNITY_END();
}

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