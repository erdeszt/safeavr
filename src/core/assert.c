#include "safeavr/core/assert.h"
#include "safeavr/core/defs.h"

#ifndef NDEBUG
void assert(boolean condition)
{
    if (!condition) {
        panic();
    }
}
#else
void assert(boolean condition)
{
    UNUSED(condition);
}
#endif /* NDEBUG */
