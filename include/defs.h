/*
 * bits.h
 *
 * Created: 12/29/2020 12:31:38 PM
 *  Author: erdeszt
 */

#ifndef DEFS_H_
#define DEFS_H_

/*
 * Standard integral types
 */
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed int int16_t;
typedef unsigned int uint16_t;
typedef signed long int int32_t;
typedef unsigned long int uint32_t;

#define TRUE 1
#define FALSE 0

#define NUL ((void *)0)

enum logic_level { LOW = 0, HIGH = 1 };

/*
 * Bit manipulation and query helpers
 */
#define SET_BIT(REG, BIT) ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT) ((REG) & (BIT))
#define IS_BIT_SET(REG, BIT) (((REG) & (BIT)) == (BIT))
#define IS_BIT_CLEAR(REG, BIT) (((REG) & (BIT)) == 0U)

/* 
 * Interrupt helpers
 */
#define enable_interrupts() __asm__ __volatile__("sei" ::: "memory")
#define disable_interrupts() __asm__ __volatile__("cli" ::: "memory")

/*
 * Panic function called in case of a non recoverable error.
 */
void panic(void);

#endif /* DEFS_H_ */
