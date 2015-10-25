/*
 * clock.h
 *
 *  Created on: Oct 12, 2015
 *      Author: lukas
 */

#ifndef HAL_CLOCK_CLOCK_H_
#define HAL_CLOCK_CLOCK_H_

#include "../hw_type.h"

void clock_init(HW_TYPE_TIMER timer);
void clock_start(HW_TYPE_TIMER timer);
void clock_stop(HW_TYPE_TIMER timer);


#endif /* HAL_CLOCK_CLOCK_H_ */
