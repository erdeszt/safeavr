#ifndef ASSERT_H_
#define ASSERT_H_

#include "defs.h"

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
