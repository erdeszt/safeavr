#ifndef SAFEAVR_CORE_H
#define SAFEAVR_CORE_H

#if defined(DEBUG) && defined(NDEBUG)
#error Both DEBUG and NDEBUG are defined!
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "safeavr/core/assert.h"
#include "safeavr/core/bits.h"
#include "safeavr/core/defs.h"
#include "safeavr/core/interrupts.h"
#include "safeavr/core/types.h"

#if SAFEAVR_FEATURE_GPIO == 1
#include "safeavr/core/gpio.h"
#endif

#if SAFEAVR_FEATURE_USART == 1
#include "safeavr/core/usart.h"
#endif

#ifdef __cplusplus
}
#endif

#endif // SAFEAVR_CORE_H
