#ifndef SAFEAVR_HAL_TIMER_H
#define SAFEAVR_HAL_TIMER_H

#include "safeavr/core/types.h"

extern const u16 SAFEAVR_TIMER_MAX_WAIT;
extern const u16 SAFEAVR_TIMER_MAX_DELAY;

void timer_init(void);

boolean timer_delay_ms(const u16 delay);

#endif /* SAFEAVR_HAL_TIMER_H */
