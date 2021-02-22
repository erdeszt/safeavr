#include "safeavr_config.h"
#include <safeavr/hal.h>

void initialize(void);

int main(void)
{
    initialize();

    while (TRUE) {
        (void)usart_send("Hello 1\n");
        (void)timer_delay_ms(1000U);
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

    timer_init();
}

void panic(void)
{
    DISABLE_INTERRUPTS();

    while (TRUE) {
        NOP();
    }
}
