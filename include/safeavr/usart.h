#ifndef SAFEAVR_USART_H_
#define SAFEAVR_USART_H_

#include "safeavr/defs.h"

// TODO: Reuse low level config
enum usart_data_bits_config {
    USART_DATA_BITS_5,
    USART_DATA_BITS_6,
    USART_DATA_BITS_7,
    USART_DATA_BITS_8,
    USART_DATA_BITS_9,
};

enum usart_parity_bit_config {
    USART_PARITY_BIT_NO,
    USART_PARITY_BIT_EVEN,
    USART_PARITY_BIT_ODD,
};

enum usart_stop_bit_config {
    USART_STOP_BIT_1,
    USART_STOP_BIT_2,
};

struct usart_init_config {
    u32 cpu_clock_speed;
    u32 baud_rate;
    enum usart_data_bits_config data_bits;
    enum usart_parity_bit_config parity_bit;
    enum usart_stop_bit_config stop_bit;
};

void usart_init(const struct usart_init_config *config);

void usart_send(const char *message);

#endif /* SAFEAVR_USART_H_ */
