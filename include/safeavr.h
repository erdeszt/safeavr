#ifndef SAFEAVR_H_
#define SAFEAVR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "safeavr/defs.h"
#include "safeavr/assert.h"

#if SAFEAVR_FEATURE_GPIO == 1
#include "safeavr/gpio.h"
#endif

#ifdef __cplusplus
}
#endif

#endif /* SAFEAVR_H_ */
