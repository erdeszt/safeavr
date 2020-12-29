/*
 * default_panic.h
 *
 * Created: 12/29/2020 4:41:15 PM
 *  Author: erdeszt
 */

#ifndef DEFAULT_PANIC_H_
#define DEFAULT_PANIC_H_

#include <safeavr/defs.h>

/*
 * Default panic function.
 * Disables interrupts and goes into an infinite loop
 */
void panic(void)
{
    disable_interrupts();

    while (1)
        ;
}

#endif /* DEFAULT_PANIC_H_ */
