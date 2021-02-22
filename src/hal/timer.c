#include "safeavr/core/types.h"
#include "safeavr/core/timer.h"
#include "safeavr/core/defs.h"
#include "safeavr/hal/timer.h"

static inline boolean timer_delay_1ms(void)
{
    timer_counter1->counter = 0;
    u16 wait_count = 0;

    while ((wait_count < SAFEAVR_TIMER_MAX_WAIT) &&
           (timer_counter1->counter < 16000U)) {
        NOP();
    }

    return wait_count < SAFEAVR_TIMER_MAX_WAIT;
}

void timer_init(void)
{
    timer_counter1->control_b.clock_select = TIMER_NO_PRESCALER;
}

boolean timer_delay_ms(u16 delay)
{
    boolean delays_successful = TRUE;

    // Loop upper bound is UINT_16_MAX. Is it good enough?
    while (delay-- > 0U) {
        delays_successful = timer_delay_1ms();
    }

    return delays_successful;
}
