#include "safeavr_config.h"
#include <safeavr/hal.h>

void initialize(void);

int main(void)
{
    initialize();

    while (TRUE) {
        adc->control_a |= (1 << 6);
        while (IS_BIT_SET(adc->control_a, 6))
            ;

        u16 value = adc->adc;

        // TODO: USART Write u16;
    }

    return 0;
}

void initialize(void)
{
    adc->multiplexer = 64; // REFS=01
    adc->control_a = 131; // Prescale: 8, enable
}

