#ifndef SAFEAVR_HAL_H
#define SAFEAVR_HAL_H

#include "safeavr/core.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(SAFEAVR_FEATURE_GPIO) && SAFEAVR_FEATURE_GPIO == 1
#include "safeavr/hal/gpio.h"
#endif

#if defined(SAFEAVR_FEATURE_USART) && SAFEAVR_FEATURE_USART == 1
#include "safeavr/hal/usart.h"
#endif

#if defined(SAFEAVR_FEATURE_TIMER) && SAFEAVR_FEATURE_TIMER == 1
#include "safeavr/hal/timer.h"
#endif

#ifdef __cplusplus
}
#endif

#endif // SAFEAVR_CORE_H
