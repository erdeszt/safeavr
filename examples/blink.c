#include "safeavr_config.h"
#include <safeavr/gpio.h>

void initialize(void);
void dummy_delay_one_second(void);

int main(void)
{
    initialize();

    while (TRUE) {
        (void)gpio_write(GPIOB, PIN0, GPIO_HIGH);
        dummy_delay_one_second();
        (void)gpio_write(GPIOB, PIN0, GPIO_LOW);
        dummy_delay_one_second();
    }

    return 0;
}

void initialize(void)
{
    struct gpio_init_config d9 = { .mode = GPIO_OUTPUT, .pin = PIN0 };

    (void)gpio_init(GPIOB, &d9);
}

void dummy_delay_one_second(void)
{
    for (u32 i = 0; i < 1200000UL; i++) {
        __asm__ __volatile__("nop");
    }
}

void panic(void)
{
    DISABLE_INTERRUPTS();

    while (TRUE) {
        ;
    }
}
