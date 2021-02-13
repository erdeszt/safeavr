#ifndef SAFEAVR_CORE_TYPES_H
#define SAFEAVR_CORE_TYPES_H

/*
 * Standard integral types
 */
typedef signed char i8;
typedef unsigned char u8;
typedef signed int i16;
typedef unsigned int u16;
typedef signed long int i32;
typedef unsigned long int u32;

#ifdef __cplusplus
typedef bool boolean;
#define TRUE true
#define FALSE false
#else
typedef _Bool boolean;
#define TRUE 1
#define FALSE 0
#endif

#endif /* SAFEAVR_CORE_TYPES_H */
