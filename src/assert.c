#include "safeavr/assert.h"
#include "safeavr/defs.h"

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
