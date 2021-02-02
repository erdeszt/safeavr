#include "safeavr/assert.h"
#include "safeavr/defs.h"
#include "safeavr/usart.h"

enum usart_character_size {
    USART_CHARACTER_SIZE_5 = 0,
    USART_CHARACTER_SIZE_6 = 1,
    USART_CHARACTER_SIZE_7 = 2,
    USART_CHARACTER_SIZE_8 = 3,
};

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
    volatile u8 clock_polarity : 1;
    volatile enum usart_character_size character_size : 2;
    volatile u8 stop_bit : 1;
    volatile u8 parity_mode_0 : 1;
    volatile u8 parity_mode_1 : 1;
    volatile u8 mode_select_0 : 1;
    volatile u8 mode_select_1 : 1;
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
    // TODO: Maybe fixed baud rates? Check table 19-12
    // TODO: Check enum values
    //       Check that the baud rate is sane
    assert(config->baud_rate > 0);

    // TODO: Check casting/math
    // u32 baud_rate_register_value = (config->cpu_clock_speed / (16UL * config->baud_rate)) - 1;
    // UBRR0H = ((u16)baud_rate_register_value) >> 8u;
    // UBRR0L = ((u16)baud_rate_register_value) & 0xffu;
    usart0->baud_high = 0;
    usart0->baud_low = 103;

    // TODO: Separate tx/rx/mix mode?
    usart0->control_b.tx_enable = 1;

    // TODO: Use config
    /* Set frame format: 8data, 2stop bit */
    // NOTE: USBS0 Stop bit: 0=1, 1=2
    //       UCSZ0(2,1,0) Character size: 011=8bit
    //       UPM0(1,0) Parity bit: 00=Disabled, 10=Even, 11=Odd
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
