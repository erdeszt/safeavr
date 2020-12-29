/*
 * bits.h
 *
 * Created: 12/29/2020 12:31:38 PM
 *  Author: erdeszt
 */

#ifndef BITS_H_
#define BITS_H_

/*
 * Standard integral types
 */
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed int int16_t;
typedef unsigned int uint16_t;
typedef signed long int int32_t;
typedef unsigned long int uint32_t;

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
 * Either define it in your project or include default_panic.h
 */
void panic(void);

#endif /* BITS_H_ */
