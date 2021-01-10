#ifndef DEFS_H_
#define DEFS_H_

/*
 * Standard integral types
 */
typedef signed char i8;
typedef unsigned char u8;
typedef signed int i16;
typedef unsigned int u16;
typedef signed long int i32;
typedef unsigned long int u32;

#define TRUE 1
#define FALSE 0

#define NUL ((void *)0)

enum logic_level { LOW = 0, HIGH = 1 };

/*
 * Bit manipulation and query helpers
 */
#define BIT_VALUE(BIT) (1u << (BIT))
#define SET_BIT(REG, BIT) ((REG) |= (BIT_VALUE(BIT)))
#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT_VALUE(BIT)))
#define READ_BIT(REG, BIT) ((REG) & (BIT_VALUE(BIT)))
#define IS_BIT_SET(REG, BIT) (((REG) & (BIT_VALUE(BIT))) == (BIT_VALUE(BIT)))
#define IS_BIT_CLEAR(REG, BIT) (((REG) & (BIT_VALUE(BIT))) == 0U)

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
