#include "safeavr_config.h"
#include <safeavr/hal.h>

void initialize(void);
void dummy_delay_one_second(void);

int main(void)
{
    initialize();

    while (TRUE) {
        usart_send("Hello 0\n");
        dummy_delay_one_second();
    }

    return 0;
}

void initialize(void)
{
    struct usart_init_config usart_config = {
        .baud_rate = USART_BAUD_RATE_9600,
        .character_size = USART_CHARACTER_SIZE_8,
        .stop_bits = USART_STOP_BITS_1,
        .parity_bit = USART_PARITY_BIT_NO,
        .mode = USART_MODE_ASYNC,
        .clock_polarity = USART_CLOCK_POLARITY_TX_RISE_RX_FALL,
        .multi_processor_mode = FALSE,
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
