/*
 * TODO: REMOVE
 */
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void dummy_delay_one_second(void);

int main(void)
{
    DDRB = 1;

    while (1) {
        PORTB |= 1;
        _delay_ms(1000);
        PORTB &= ~1;
        _delay_ms(1000);
    }

    return 0;
}

void dummy_delay_one_second(void)
{
    for (unsigned long int i = 0; i < 600000UL; i++) {
        __asm__ __volatile__("nop");
    }
}
