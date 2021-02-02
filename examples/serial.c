#include "safeavr_config.h"
#include <safeavr.h>

void initialize(void);
void dummy_delay_one_second(void);

int main(void)
{
    initialize();

    while (TRUE) {
        usart_send("Hello 10\n");
        dummy_delay_one_second();
    }

    return 0;
}

void initialize(void)
{
    struct usart_init_config usart_config = {
        .cpu_clock_speed = 16000000UL,
        .baud_rate = 9600,
        .data_bits = USART_DATA_BITS_8,
        .parity_bit = USART_PARITY_BIT_NO,
        .stop_bit = USART_STOP_BIT_1,
    };

    usart_init(&usart_config);
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
