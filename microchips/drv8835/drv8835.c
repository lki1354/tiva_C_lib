/*! \file drv8835.c
 *  \brief Implementation of all need functions for handling drv8835 control
 *  \author Lukas Kiechle
 *  \date 2016-01-13 creat date
 *  \copyright  All rights belong to
 *
 *  $Date:  $
 *  $Revision: 0.1$
 *  $LastChangedDate: $
 */

#include "drv8835.h"
#include "debug.h"


void drv8835_init(drv8835_driver_t* drv8835){

	ASSERT(drv8835);

	gpio_pin_init(drv8835->_pin_mode,GPIO_TYPE_DIGITAL_OUTPUT);
	gpio_set(drv8835->_pin_mode);

	gpio_pin_init(drv8835->c_one._pin_direction,GPIO_TYPE_DIGITAL_OUTPUT);
	gpio_pin_init(drv8835->c_two._pin_direction,GPIO_TYPE_DIGITAL_OUTPUT);

	gpio_pin_init(drv8835->c_one._pin_speed,GPIO_TYPE_PWM_OUTPUT);
	gpio_pin_init(drv8835->c_two._pin_speed,GPIO_TYPE_PWM_OUTPUT);

	drv8835->state = DRV8835_INIT;

	drv8835_set_speed(drv8835,0);

}

void drv8835_set_speed(drv8835_driver_t* drv8835, uint16_t speed){

	ASSERT(drv8835);

	gpio_pwm_set_duty_cycle(drv8835->c_one._pin_speed,speed/100.0);
	drv8835->c_one._speed = speed;

	gpio_pwm_set_duty_cycle(drv8835->c_two._pin_speed,speed/100.0);
	drv8835->c_two._speed = speed;

}

void drv8835_set_direction(drv8835_driver_t* drv8835, drv8835_direction_t direction){

	ASSERT(drv8835);

	switch(direction){
	case DRV8835_FORWARD:
		gpio_set(drv8835->c_one._pin_direction);
		gpio_set(drv8835->c_two._pin_direction);
		break;
	case DRV8835_REVERSE:
		gpio_clear(drv8835->c_one._pin_direction);
		gpio_clear(drv8835->c_two._pin_direction);
		break;
	}
}

void drv8835_enable(drv8835_driver_t* drv8835){

	ASSERT(drv8835);
	gpio_pwm_start(drv8835->c_one._pin_speed);
	gpio_pwm_start(drv8835->c_two._pin_speed);
}
void drv8835_disable(drv8835_driver_t* drv8835){

	ASSERT(drv8835);

	gpio_pwm_stop(drv8835->c_one._pin_speed);
	gpio_pwm_stop(drv8835->c_two._pin_speed);
}

void drv8835_set_speed_channel(drv8835_channel_t* channel, uint16_t speed){
	//todo check set error and return the information
	ASSERT(channel);
	gpio_pwm_set_duty_cycle(channel->_pin_speed,speed/100.0);
	channel->_speed = speed;
}
void drv8835_set_direction_channel(drv8835_channel_t* channel, drv8835_direction_t direction){

	ASSERT(channel);

	switch(direction){
	case DRV8835_FORWARD:
		gpio_set(channel->_pin_direction);
		break;
	case DRV8835_REVERSE:
		gpio_clear(channel->_pin_direction);
		break;
	}
}
void drv8835_enable_channel(drv8835_channel_t* channel){

	ASSERT(channel);

	gpio_pwm_set_duty_cycle(channel->_pin_speed,channel->_speed);
	gpio_pwm_start(channel->_pin_speed);
}
void drv8835_disable_channel(drv8835_channel_t* channel){

	ASSERT(channel);

	gpio_pwm_stop(channel->_pin_speed);
}


