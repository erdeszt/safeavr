#ifndef SAFEAVR_HAL_TIMER_H
#define SAFEAVR_HAL_TIMER_H

#include "safeavr/core/types.h"

extern const u16 SAFEAVR_TIMER_MAX_WAIT;

void timer_init(void);

boolean timer_delay_ms(u16 delay);

#endif /* SAFEAVR_HAL_TIMER_H */
