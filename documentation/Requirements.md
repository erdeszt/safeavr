# Requirements for the SafeAVR library

## 1 Functionality

### 1.1 GPIO

#### 1.1.1 Logic level read and write access to the GPIO pins

The library should provide access to all the general puprose pins defined in `Reference 3.1` section `1.1.3`, `1.1.4` and `1.1.5`

##### 1.1.1.1 It should be possible to configure each pin as either `input` or `output`.
##### 1.1.1.2 It should be possible to write either `high` or `low` logic levels to pins configured as `output`.
##### 1.1.1.3 It should be possible to read the logic level of pins configured as `input`.

## 2 Safety

The library should be MISRA compliant. Compliance should be checked with the cppcheck Misra addon.

## 3 References

### 3.1 The Atmal ATMega328P datasheet 

`references/ATMega328P_Datasheet.pdf`

