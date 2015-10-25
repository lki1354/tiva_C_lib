/*
 * gpio.h
 *
 *  Created on: Oct 10, 2015
 *      Author: lukas
 */

#ifndef HAL_GPIO_GPIO_H_
#define HAL_GPIO_GPIO_H_

#include "../hw_type.h"

void gpio_pad_config_hbus(HW_TYPE_GPIO_PORTS port,uint8_t pin,HW_TYPE_GPIO_PAD pad,uint8_t state);
void gpio_enable(HW_TYPE_GPIO_PORTS port,uint8_t pin);
void gpio_disable(HW_TYPE_GPIO_PORTS port,uint8_t pin);


#endif /* HAL_GPIO_GPIO_H_ */
