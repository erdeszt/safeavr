#ifndef ASSERT_H_
#define ASSERT_H_

#include "defs.h"

#if defined(DEBUG) && defined(NDEBUG)
#error Both DEBUG and NDEBUG are defined!
#endif

/*
 * Aborts execution when the condition is false
 */
#ifndef NDEBUG
#define assert(condition)                                                      \
    if (!(condition)) {                                                        \
        panic();                                                               \
    }
#else
#define assert(condition)
#endif

#endif /* ASSERT_H_ */
