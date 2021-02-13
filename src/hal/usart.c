#include "safeavr/core/assert.h"
#include "safeavr/core/defs.h"
#include "safeavr/core/types.h"
#include "safeavr/core/usart.h"
#include "safeavr/hal/usart.h"

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
