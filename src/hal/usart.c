#include "safeavr/core/assert.h"
#include "safeavr/core/defs.h"
#include "safeavr/core/types.h"
#include "safeavr/core/usart.h"
#include "safeavr/hal/usart.h"

void usart_init(const struct usart_init_config *config)
{
    switch (config->baud_rate) {
    case USART_BAUD_RATE_9600:
        usart0->baud_high = 0;
        usart0->baud_low = 103;
        break;
    default:
        panic();
        break;
    }

    usart0->control_a.multi_processor_mode = (u8)config->multi_processor_mode;

    usart0->control_b.tx_enable = 1;
    usart0->control_b.rx_enable = 1;

    usart0->control_c.character_size = config->baud_rate;
    usart0->control_c.stop_bits = config->stop_bits;
    usart0->control_c.parity_bit = config->parity_bit;
    usart0->control_c.mode = config->mode;
    usart0->control_c.clock_polarity = config->clock_polarity;
}

enum usart_tx_result usart_send(const char *message)
{
    u16 char_index = 0;
    u16 wait_count = 0;
    enum usart_tx_result result = USART_TX_SUCCESS;

    for (; (char_index < SAFEAVR_USART_TX_MAX_STRING_SIZE) &&
           (message[char_index] != '\0');
         char_index++) {
        for (wait_count = 0; (usart0->control_a.data_register_empty == 0) &&
                             (wait_count < SAFEAVR_USART_TX_MAX_WAIT);
             wait_count++) {
            NOP();
        }

        if (wait_count >= SAFEAVR_USART_TX_MAX_WAIT) {
            result = USART_TX_TIMEOUT;
            break;
        }

        usart0->data = message[char_index];
    }

    if (char_index >= SAFEAVR_USART_TX_MAX_STRING_SIZE) {
        panic();
    }

    return result;
}
