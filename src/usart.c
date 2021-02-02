#include "safeavr/assert.h"
#include "safeavr/defs.h"
#include "safeavr/usart.h"

struct usart_control_def_a {
    volatile u8 multi_processor_mode : 1;
    volatile u8 double_speed : 1;
    volatile u8 parity_error : 1;
    volatile u8 data_overrun : 1;
    volatile u8 frame_error : 1;
    volatile u8 data_register_empty : 1;
    volatile u8 tx_complete : 1;
    volatile u8 rx_complete : 1;
};

struct usart_control_def_b {
    volatile u8 tx_bit8 : 1;
    volatile u8 rx_bit8 : 1;
    volatile u8 character_size_2 : 1;
    volatile u8 tx_enable : 1;
    volatile u8 rx_enable : 1;
    volatile u8 data_empty_int : 1;
    volatile u8 tx_complete_int : 1;
    volatile u8 rx_complete_int : 1;
};

struct usart_control_def_c {
    volatile enum usart_clock_polarity clock_polarity : 1;
    volatile enum usart_character_size character_size : 2;
    volatile enum usart_stop_bits stop_bit : 1;
    volatile enum usart_parity_bit parity_mode_0 : 2;
    volatile enum usart_mode mode : 2;
};

struct usart_control {
    /* 0xC0 */ struct usart_control_def_a control_a;
    /* 0xC1 */ struct usart_control_def_b control_b;
    /* 0xC2 */ struct usart_control_def_c control_c;
    /* 0xC3 */ volatile u8 unused : 8;
    /* 0xC4 */ volatile u8 baud_low : 8;
    /* 0xC5 */ volatile u8 baud_high : 8;
    /* 0xC6 */ volatile u8 data : 8;
};

struct usart_control *usart0 = (struct usart_control *)0xC0;

void usart_init(const struct usart_init_config *config)
{
    assert(config->baud_rate > 0);

    // UBRR0H = ((u16)baud_rate_register_value) >> 8u;
    // UBRR0L = ((u16)baud_rate_register_value) & 0xffu;
    usart0->baud_high = 0;
    usart0->baud_low = 103;

    usart0->control_b.tx_enable = 1;
    usart0->control_c.character_size = USART_CHARACTER_SIZE_8;
}

void usart_send(const char *message)
{
    // TODO: Abstraction for test:
    // TODO: Static limits on the loops
    for (int i = 0; message[i]; i++) {
        // TODO: Check for UDRE0
        // while (!(UCSR0A & (1u << UDRE0))) ;

        usart0->data = message[i];

        for (i16 j = 0; j < 10000; j++) {
            __asm__ __volatile__("nop");
        }
    }
}
