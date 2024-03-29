/*
 * GPIO Header Constants
 *
 */

#ifndef _FSGPIO_H_
#define _FSGPIO_H_

#include <stdio.h>
#include <stdlib.h>

#define GPIO_OFFSET( _CONTROLLER, _CHANNEL) _CONTROLLER*32+_CHANNEL

/*
 * GPIO Pin sysfs numbers
 */
#define GPIO_P8_PIN_1 //GND
#define GPIO_P8_PIN_2 //GND
#define GPIO_P8_PIN_3 GPIO_OFFSET( 1, 6)
#define GPIO_P8_PIN_4 GPIO_OFFSET( 1, 7)
#define GPIO_P8_PIN_5 GPIO_OFFSET( 1, 2)
#define GPIO_P8_PIN_6 GPIO_OFFSET( 1, 3)
#define GPIO_P8_PIN_7 GPIO_OFFSET( 2, 2)
#define GPIO_P8_PIN_8 GPIO_OFFSET( 2, 3)
#define GPIO_P8_PIN_9 GPIO_OFFSET( 2, 5)
#define GPIO_P8_PIN_10 GPIO_OFFSET( 2, 4)
#define GPIO_P8_PIN_11 GPIO_OFFSET( 1, 13)
#define GPIO_P8_PIN_12 GPIO_OFFSET( 1, 12)
#define GPIO_P8_PIN_13 GPIO_OFFSET( 0, 23)
#define GPIO_P8_PIN_14 GPIO_OFFSET( 0, 26)
#define GPIO_P8_PIN_15 GPIO_OFFSET( 1, 15)
#define GPIO_P8_PIN_16 GPIO_OFFSET( 1, 14)
#define GPIO_P8_PIN_17 GPIO_OFFSET( 0, 27)
#define GPIO_P8_PIN_18 GPIO_OFFSET( 2, 1)
#define GPIO_P8_PIN_19 GPIO_OFFSET( 0, 22)
#define GPIO_P8_PIN_20 GPIO_OFFSET( 1, 31)
#define GPIO_P8_PIN_21 GPIO_OFFSET( 1, 30)
#define GPIO_P8_PIN_22 GPIO_OFFSET( 1, 5)
#define GPIO_P8_PIN_23 GPIO_OFFSET( 1, 4)
#define GPIO_P8_PIN_24 GPIO_OFFSET( 1, 1)
#define GPIO_P8_PIN_25 GPIO_OFFSET( 1, 0)
#define GPIO_P8_PIN_26 GPIO_OFFSET( 1, 29)
#define GPIO_P8_PIN_27 GPIO_OFFSET( 2, 22)
#define GPIO_P8_PIN_28 GPIO_OFFSET( 2, 24)
#define GPIO_P8_PIN_29 GPIO_OFFSET( 2, 23)
#define GPIO_P8_PIN_30 GPIO_OFFSET( 2, 25)
#define GPIO_P8_PIN_31 GPIO_OFFSET( 0, 10)
#define GPIO_P8_PIN_32 GPIO_OFFSET( 0, 11)
#define GPIO_P8_PIN_33 GPIO_OFFSET( 0, 9)
#define GPIO_P8_PIN_34 GPIO_OFFSET( 2, 17)
#define GPIO_P8_PIN_35 GPIO_OFFSET( 0, 8)
#define GPIO_P8_PIN_36 GPIO_OFFSET( 2, 16)
#define GPIO_P8_PIN_37 GPIO_OFFSET( 2, 14)
#define GPIO_P8_PIN_38 GPIO_OFFSET( 2, 15)
#define GPIO_P8_PIN_39 GPIO_OFFSET( 2, 12)
#define GPIO_P8_PIN_40 GPIO_OFFSET( 2, 13)
#define GPIO_P8_PIN_41 GPIO_OFFSET( 2, 10)
#define GPIO_P8_PIN_42 GPIO_OFFSET( 2, 11)
#define GPIO_P8_PIN_43 GPIO_OFFSET( 2, 8)
#define GPIO_P8_PIN_44 GPIO_OFFSET( 2, 9)
#define GPIO_P8_PIN_45 GPIO_OFFSET( 2, 6)
#define GPIO_P8_PIN_46 GPIO_OFFSET( 2, 7)

#define GPIO_P9_PIN_1
#define GPIO_P9_PIN_2
#define GPIO_P9_PIN_3
#define GPIO_P9_PIN_4
#define GPIO_P9_PIN_5
#define GPIO_P9_PIN_6
#define GPIO_P9_PIN_7
#define GPIO_P9_PIN_8
#define GPIO_P9_PIN_9
#define GPIO_P9_PIN_10
#define GPIO_P9_PIN_11 GPIO_OFFSET( 0, 30)
#define GPIO_P9_PIN_12 GPIO_OFFSET( 1, 28)
#define GPIO_P9_PIN_13 GPIO_OFFSET( 0, 31)
#define GPIO_P9_PIN_14 GPIO_OFFSET( 1, 18)
#define GPIO_P9_PIN_15 GPIO_OFFSET( 1, 16)
#define GPIO_P9_PIN_16 GPIO_OFFSET( 1, 19)
#define GPIO_P9_PIN_17 GPIO_OFFSET( 0, 5)
#define GPIO_P9_PIN_18 GPIO_OFFSET( 0, 4)
#define GPIO_P9_PIN_19 GPIO_OFFSET( 0, 13)
#define GPIO_P9_PIN_20 GPIO_OFFSET( 0, 12)
#define GPIO_P9_PIN_21 GPIO_OFFSET( 0, 3)
#define GPIO_P9_PIN_22 GPIO_OFFSET( 0, 2)
#define GPIO_P9_PIN_23 GPIO_OFFSET( 1, 17)
#define GPIO_P9_PIN_24 GPIO_OFFSET( 0, 15)
#define GPIO_P9_PIN_25 GPIO_OFFSET( 3, 21)
#define GPIO_P9_PIN_26 GPIO_OFFSET( 0, 14)
#define GPIO_P9_PIN_27 GPIO_OFFSET( 3, 19)
#define GPIO_P9_PIN_28 GPIO_OFFSET( 3, 17)
#define GPIO_P9_PIN_29 GPIO_OFFSET( 3, 15)
#define GPIO_P9_PIN_30 GPIO_OFFSET( 3, 16)
#define GPIO_P9_PIN_31 GPIO_OFFSET( 3, 14)
#define GPIO_P9_PIN_32
#define GPIO_P9_PIN_33
#define GPIO_P9_PIN_34
#define GPIO_P9_PIN_35
#define GPIO_P9_PIN_36
#define GPIO_P9_PIN_37
#define GPIO_P9_PIN_38
#define GPIO_P9_PIN_39
#define GPIO_P9_PIN_40
#define GPIO_P9_PIN_41 //blank for potential conflicts
#define GPIO_P9_PIN_42 //blank for potential conflicts
#define GPIO_P9_PIN_43
#define GPIO_P9_PIN_44
#define GPIO_P9_PIN_45
#define GPIO_P9_PIN_46

/*
 * Path Constants
 */

#define PATH_SIZE 100
#define GPIO_PATH_BASE "/sys/class/gpio"
#define GPIO_PATH_EXPORT "/sys/class/gpio/export"
#define GPIO_PATH_UNEXPORT "/sys/class/gpio/unexport"


int fsgpio_export(char gpioNum);
int fsgpio_unexport(char gpioNum);
int fsgpio_set_input(char gpioNum);
int fsgpio_set_output(char gpioNum);
int fsgpio_set_value(char gpioNum, char value);

#endif
