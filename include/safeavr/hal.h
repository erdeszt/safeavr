#ifndef SAFEAVR_HAL_H
#define SAFEAVR_HAL_H

#include "safeavr/core.h"

#ifdef __cplusplus
extern "C" {
#endif

#if SAFEAVR_FEATURE_GPIO == 1
#include "safeavr/hal/gpio.h"
#endif

#if SAFEAVR_FEATURE_USART == 1
#include "safeavr/hal/usart.h"
#endif

#ifdef __cplusplus
}
#endif

#endif // SAFEAVR_CORE_H
