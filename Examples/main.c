/*
 * Examples.c
 *
 * Created: 12/29/2020 11:44:05 AM
 * Author : erdeszt
 */

#include "safeavr_config.h"
#include <safeavr.h>

void dummy_delay_one_second(void);

int main(void)
{
    struct gpio_init_config d9 = { .direction = OUTPUT, .pin = PIN1 };

    gpio_init(GPIOB, &d9);

    while (true) {
        gpio_write(GPIOB, PIN1, HIGH);
        dummy_delay_one_second();
        gpio_write(GPIOB, PIN1, LOW);
        dummy_delay_one_second();
    }

    return 0;
}

void dummy_delay_one_second(void)
{
    for (uint32_t i = 0; i < 600000; i++) {
        __asm__ __volatile__("nop");
    }
}

void panic(void)
{
    disable_interrupts();

    while (true)
        ;
}

//#include <avr/io.h>
//#include <util/delay.h>
//
//DDRB = 1;
//
//while (1) {
//PORTB = 1;
//_delay_ms(1000);
//PORTB = 0;
//_delay_ms(1000);
//}
