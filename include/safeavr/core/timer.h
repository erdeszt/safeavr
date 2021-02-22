#ifndef SAFEAVR_CORE_TIMER_H
#define SAFEAVR_CORE_TIMER_H

#include "safeavr/core/types.h"

enum timer_clock_select {
    TIMER_NO_CLOCK = 0,
    TIMER_NO_PRESCALER = 1,
    TIMER_PRESCALER_8 = 2,
    TIMER_PRESCALER_64 = 3,
    TIMER_PRESCALER_256 = 4,
    TIMER_PRESCALER_1024 = 5,
    TIMER_EXTERNAL_FALLING_EDGE = 6,
    TIMER_EXTERNAL_RISING_EDGE = 7,
};

// TODO: Use enums
struct timer_counter1_control_b {
    volatile enum timer_clock_select clock_select : 3;
    volatile u8 waveform_generation_mode : 2;
    volatile u8 unused : 1;
    volatile u8 input_capture_edge_select : 1;
    volatile u8 input_capture_noise_canceler : 1;
};

struct timer_counter1_control {
    /* 0x81 */ struct timer_counter1_control_b control_b;
    /* 0x82 */ volatile u8 unused_1;
    /* 0x83 */ volatile u8 unused_2;
    /* 0x84 */ volatile u16 counter;
};

extern struct timer_counter1_control *timer_counter1;

#endif /* SAFEAVR_CORE_TIMER_H */

