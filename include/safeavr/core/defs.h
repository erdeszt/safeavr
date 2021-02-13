#ifndef SAFEAVR_CORE_DEFS_H
#define SAFEAVR_CORE_DEFS_H

#define NULL ((void *)0)
#define UNUSED(x) ((void)(x))
#define NOP() __asm__ __volatile__("nop")

void panic(void);

#endif /* SAFEAVR_CORE_DEFS_H */
