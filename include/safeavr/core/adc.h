#ifndef SAFEAVR_CORE_ADC_H
#define SAFEAVR_CORE_ADC_H

#include "safeavr/core/types.h"

enum adc_prescaler {
    ADC_PRESCALER_2 = 0,
    ADC_PRESCALER_4 = 2,
    ADC_PRESCALER_8 = 3,
    ADC_PRESCALER_16 = 4,
    ADC_PRESCALER_32 = 5,
    ADC_PRESCALER_64 = 6,
    ADC_PRESCALER_123 = 7,
};

enum adc_auto_trigger_source {
    ADC_AUTO_TRIGGER_SOURCE_FREE_RUNNING = 0,
    ADC_AUTO_TRIGGER_ = 0,
    // TODO: FINISH
};

struct adc_control_a {
    volatile enum adc_prescaler prescaler : 3;
    volatile boolean interrupt_enable : 1;
    volatile boolean interrupt_flag : 1;
    volatile boolean auto_trigger : 1;
    volatile boolean start_conversion : 1;
    volatile boolean enable : 1;
};

struct adc_control_b {
    volatile enum adc_auto_trigger_source auto_trigger_source : 3;
    volatile u8 unused_1 : 3;
    volatile boolean analog_comparator_multiplexer : 1;
    volatile u8 unused_2 : 1;
};

struct adc_registers {
    volatile u16 adc;
    struct adc_control_a control_a;
    struct adc_control_b control_b;
    volatile u8 multiplexer;
};

extern struct adc_registers *adc;

#endif /* SAFEAVR_CORE_ADC_H */
