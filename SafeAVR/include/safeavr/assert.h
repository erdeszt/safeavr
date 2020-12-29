/*
 * assert.h
 *
 * Created: 12/29/2020 7:36:40 PM
 *  Author: erdeszt
 */

#ifndef ASSERT_H_
#define ASSERT_H_

#include "safeavr/defs.h"

#ifdef DEBUG
/*
 * Aborts execution when the argument is false
 */
inline void assert(const _Bool condition)
{
    if (!condition) {
        panic();
    }
}
#else
#define assert(CONDITION)
#endif /* DEBUG */

#endif /* ASSERT_H_ */
