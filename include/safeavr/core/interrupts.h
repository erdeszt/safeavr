#ifndef SAFEAVR_CORE_INTERRUPTS_H
#define SAFEAVR_CORE_INTERRUPTS_H

#define ENABLE_INTERRUPTS() __asm__ __volatile__("sei" ::: "memory")
#define DISABLE_INTERRUPTS() __asm__ __volatile__("cli" ::: "memory")

#endif /* SAFEAVR_CORE_INTERRUPTS_H */
