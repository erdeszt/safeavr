#include "safeavr_config.h"
#include <safeavr/hal.h>

void initialize(void);

int main(void)
{
    initialize();

    while (TRUE) {
        adc->control_a.start_conversion = TRUE;
        while (adc->control_a.start_conversion == TRUE) {
        }

        u16 value = adc->adc;

        // TODO: USART Write u16;
    }

    return 0;
}

void initialize(void)
{
    adc->multiplexer = 64; // REFS=01
    adc->control_a.prescaler = ADC_PRESCALER_8;
    adc->control_a.enable = TRUE;
}

