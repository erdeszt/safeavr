#ifndef SAFEAVR_CORE_BITS_H
#define SAFEAVR_CORE_BITS_H

#define BIT_VALUE(BIT) (1U << (BIT))
#define SET_BIT(REG, BIT) ((REG) |= (BIT_VALUE(BIT)))
#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT_VALUE(BIT)))
#define READ_BIT(REG, BIT) ((REG) & (BIT_VALUE(BIT)))
#define IS_BIT_SET(REG, BIT) (((REG) & (BIT_VALUE(BIT))) == (BIT_VALUE(BIT)))
#define IS_BIT_CLEAR(REG, BIT) (((REG) & (BIT_VALUE(BIT))) == 0U)

#endif /* SAFEAVR_CORE_BITS_H */
