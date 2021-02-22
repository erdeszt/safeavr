#ifndef SAFEAVR_USART_H
#define SAFEAVR_USART_H

#include "safeavr/core/types.h"

enum usart_baud_rate {
    USART_BAUD_RATE_9600 = 103,
};

enum usart_tx_result {
    USART_TX_SUCCESS = 0,
    USART_TX_TIMEOUT = 1,
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

extern const u16 SAFEAVR_USART_TX_MAX_STRING_SIZE;
extern const u16 SAFEAVR_USART_TX_MAX_WAIT;
extern const u16 SAFEAVR_USART_RX_MAX_WAIT;

void usart_init(const struct usart_init_config *config);

enum usart_tx_result usart_send(const char *message);

#endif /* SAFEAVR_HAL_USART_H */
