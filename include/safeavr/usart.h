#ifndef SAFEAVR_USART_H_
#define SAFEAVR_USART_H_

#include "safeavr/defs.h"

enum usart_baud_rate {
    USART_BAUD_RATE_9600 = 103,
};

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

/*
 * Assumed clock speed is 16Mhz
 */
struct usart_init_config {
    enum usart_baud_rate baud_rate;
    enum usart_character_size character_size;
    enum usart_stop_bits stop_bits;
    enum usart_parity_bit parity_bit;
    enum usart_mode mode;
    enum usart_clock_polarity clock_polarity;
    boolean multi_processor_mode;
};

void usart_init(const struct usart_init_config *config);

void usart_send(const char *message);

#endif /* SAFEAVR_USART_H_ */
