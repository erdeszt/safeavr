#ifndef SAFEAVR_USART_H
#define SAFEAVR_USART_H

#include "safeavr/core/types.h"

enum usart_baud_rate {
    USART_BAUD_RATE_9600 = 103,
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

#endif /* SAFEAVR_HAL_USART_H */
