#ifndef SAFEAVR_CORE_USART_H
#define SAFEAVR_CORE_USART_H

#include "safeavr/core/types.h"

/*
 * 9-bit mode not supported
 */
enum usart_character_size {
    USART_CHARACTER_SIZE_5 = 0,
    USART_CHARACTER_SIZE_6 = 1,
    USART_CHARACTER_SIZE_7 = 2,
    USART_CHARACTER_SIZE_8 = 3,
};

enum usart_clock_polarity {
    USART_CLOCK_POLARITY_TX_RISE_RX_FALL = 0,
    USART_CLOCK_POLARITY_TX_FALL_RX_RISE = 1,
};

enum usart_parity_bit {
    USART_PARITY_BIT_NO = 0,
    USART_PARITY_BIT_EVEN = 2,
    USART_PARITY_BIT_ODD = 3,
};

enum usart_stop_bits {
    USART_STOP_BITS_1 = 0,
    USART_STOP_BITS_2 = 1,
};

enum usart_mode {
    USART_MODE_ASYNC = 0,
    USART_MODE_SYNC = 1,
    USART_MODE_MASTER_SPI = 3,
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
    volatile enum usart_clock_polarity clock_polarity : 1;
    volatile enum usart_character_size character_size : 2;
    volatile enum usart_stop_bits stop_bits : 1;
    volatile enum usart_parity_bit parity_bit : 2;
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

extern struct usart_control *usart0;

#endif /* SAFEAVR_CORE_USART_H */
