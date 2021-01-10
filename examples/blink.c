#include <safeavr/gpio.h>

void initialize(void);
void dummy_delay_one_second(void);

int main(void)
{
    initialize();

    while (TRUE) {
        gpio_write(GPIOB, PIN1, HIGH);
        dummy_delay_one_second();
        gpio_write(GPIOB, PIN1, LOW);
        dummy_delay_one_second();
    }

    return 0;
}

void initialize(void)
{
    struct gpio_init_config d9 = { .direction = OUTPUT, .pin = PIN1 };

    gpio_init(GPIOB, &d9);
}

void dummy_delay_one_second(void)
{
    for (u32 i = 0; i < 600000UL; i++) {
        __asm__ __volatile__("nop");
    }
}

void panic(void)
{
    disable_interrupts();

    while (TRUE) {
        ;
    }
}
