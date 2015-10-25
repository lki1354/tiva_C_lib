/*
 * hw_type.h
 *
 *  Created on: Oct 10, 2015
 *      Author: lukas
 */

#ifndef HAL_HW_TYPE_H_
#define HAL_HW_TYPE_H_

#define TM4C123GH6PM_REGISTERS
#include <stdint.h>
#include "hw_registers.h"

typedef enum {HW_TYPE_DISABLE, HW_TYPE_ENABLE} HW_TYPE_STATE;
typedef enum {HW_TYPE_GPIO_INPUT, HW_TYPE_GPIO_OUTPUT} HW_TYPE_DIR;
typedef enum {PORTA,PORTB,PORTC,PORTD,PORTE,PORTF,ALL_PORTS} HW_TYPE_GPIO_PORTS;
typedef enum {PIN0=0x01,PIN1=0x02, PIN2=0x04,PIN3=0x08,PIN4=0x10,PIN5=0x20,PIN6=0x40,PIN7=0x80,ALL_PINS=0xFF} HW_TYPE_GPIO_PIN;
typedef enum {PERIPHERAL_BUS, HIGH_BUS} HW_TYPE_GPIO_BUS;
typedef enum {
	HW_TYPE_GPIO_DATA, /*GPIO Data*/
	HW_TYPE_GPIO_DIR, /*GPIO Direction*/
	HW_TYPE_GPIO_2MA_DRIVER, /*GPIO 2-mA Drive Select*/
	HW_TYPE_GPIO_4MA_DRIVER, /*GPIO 4-mA Drive Select*/
	HW_TYPE_GPIO_8MA_DRIVER, /*GPIO 8-mA Drive Select*/
	HW_TYPE_GPIO_PULL_UP, /*GPIO Pull-Up Select*/
	HW_TYPE_GPIO_DIGITAL_FUNTION /*GPIO digital function Select*/
} HW_TYPE_GPIO_PAD;

typedef enum { HW_TYPE_TIMER_0, HW_TYPE_TIMER_1, HW_TYPE_TIMER_2, HW_TYPE_TIMER_3, HW_TYPE_TIMER_4, HW_TYPE_TIMER_5 }HW_TYPE_TIMER;

#endif /* HAL_HW_TYPE_H_ */
