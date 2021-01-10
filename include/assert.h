/*
 * assert.h
 *
 * Created: 12/29/2020 7:36:40 PM
 *  Author: erdeszt
 */

#ifndef ASSERT_H_
#define ASSERT_H_

#include "safeavr/defs.h"

/*
 * Aborts execution when the condition is false
 */
#ifdef DEBUG
#define assert(condition)                                                      \
    if (!(condition)) {                                                        \
        panic();                                                               \
    }
#else
#define assert(condition)
#endif /* DEBUG */

#endif /* ASSERT_H_ */
