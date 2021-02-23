#include "safeavr_config.h"
#include <safeavr/hal.h>

void initialize(void);

int main(void)
{
    initialize();

    while (TRUE) {
        gpio_write(GPIOB, PIN0, GPIO_HIGH);
        (void)timer_delay_ms(1000U);
        gpio_write(GPIOB, PIN0, GPIO_LOW);
        (void)timer_delay_ms(1000U);
    }

    return 0;
}

void initialize(void)
{
    struct gpio_init_config d8 = { .mode = GPIO_OUTPUT, .pin = PIN0 };

    gpio_init(GPIOB, &d8);

    timer_init();
}

void panic(void)
{
    DISABLE_INTERRUPTS();

    while (TRUE) {
        NOP();
    }
}
