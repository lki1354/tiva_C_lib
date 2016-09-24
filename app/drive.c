/*! \file drive.c
 *  \brief Implemenation of functions for controll all four motors
 *  \author Lukas Kiechle
 *  \date 2016-01-11 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 *
 */

#include "drive.h"
#include "debug.h"

void drive_init(drive_t* drive,gpio_pins_t mode_pin){

	ASSERT(drive);

	gpio_pin_init(mode_pin, GPIO_TYPE_DIGITAL_OUTPUT_HIGH_CURRENT);
	gpio_set(mode_pin);

	drv8835_init(&drive->front);
	drv8835_init(&drive->back);

	drv8835_set_direction(&drive->front,DRV8835_FORWARD);
	drv8835_set_direction(&drive->back,DRV8835_FORWARD);

	drive->_state = DRIVE_DISABLE;

}

void drive_set_pin(drive_t* drive, drive_motors_t motor, gpio_pins_t speed_pin,gpio_pins_t direction_pin){

	ASSERT(drive);
	ASSERT( drive->_state == DRIVE_NOT_INIT);

	switch (motor) {
		case DRIVE_MOTOR_FRONT_RIGHT:
			drive->front.c_one._pin_direction = direction_pin;
			drive->front.c_one._pin_speed = speed_pin;
			break;
		case DRIVE_MOTOR_FRONT_LEFT:
			drive->front.c_two._pin_direction = direction_pin;
			drive->front.c_two._pin_speed = speed_pin;
			break;
		case DRIVE_MOTOR_BACK_RIGHT:
			drive->back.c_one._pin_direction = direction_pin;
			drive->back.c_one._pin_speed = speed_pin;
			break;
		case DRIVE_MOTOR_BACK_LEFT:
			drive->back.c_two._pin_direction = direction_pin;
			drive->back.c_two._pin_speed = speed_pin;
			break;
		default:
			break;
	}
}

void drive_enable(drive_t* drive,drive_motors_t motor){

	ASSERT(drive);
	ASSERT( drive->_state == DRIVE_NOT_INIT);
	drive->_state = DRIVE_ENABLE;

	switch(motor){
	case DRIVE_MOTOR_FRONT_RIGHT:
		drv8835_enable_channel( &drive->front.c_one );
		break;
	case DRIVE_MOTOR_FRONT_LEFT:
		drv8835_enable_channel( &drive->front.c_two );
		break;
	case DRIVE_MOTOR_BACK_RIGHT:
		drv8835_enable_channel( &drive->back.c_one );
		break;
	case DRIVE_MOTOR_BACK_LEFT:
		drv8835_enable_channel( &drive->back.c_two );
		break;
	case DRIVE_MOTOR_ALL:
		drv8835_enable( &drive->front );
		drv8835_enable( &drive->back );
		break;
	default:
		ASSERT(1);
	}
}
void drive_disable(drive_t* drive,drive_motors_t motor){

	ASSERT(drive);
	ASSERT( drive->_state == DRIVE_NOT_INIT);

	switch(motor){
	case DRIVE_MOTOR_FRONT_RIGHT:
		drv8835_disable_channel( &drive->front.c_one );
		break;
	case DRIVE_MOTOR_FRONT_LEFT:
		drv8835_disable_channel( &drive->front.c_two );
		break;
	case DRIVE_MOTOR_BACK_RIGHT:
		drv8835_disable_channel( &drive->back.c_one );
		break;
	case DRIVE_MOTOR_BACK_LEFT:
		drv8835_disable_channel( &drive->back.c_two );
		break;
	case DRIVE_MOTOR_ALL:
		drv8835_disable( &drive->front );
		drv8835_disable( &drive->back );
		drive->_state = DRIVE_DISABLE;
		break;
	default:
		ASSERT(1);
	}

}
void drive_forward(drive_t* drive,drive_motors_t motor){

	ASSERT(drive);
	ASSERT( drive->_state == DRIVE_NOT_INIT);

	switch(motor){
	case DRIVE_MOTOR_FRONT_RIGHT:
		drv8835_set_direction_channel( &drive->front.c_one,DRV8835_FORWARD);
		break;
	case DRIVE_MOTOR_FRONT_LEFT:
		drv8835_set_direction_channel(&drive->front.c_two,DRV8835_FORWARD);
		break;
	case DRIVE_MOTOR_BACK_RIGHT:
		drv8835_set_direction_channel(&drive->back.c_one,DRV8835_FORWARD);
		break;
	case DRIVE_MOTOR_BACK_LEFT:
		drv8835_set_direction_channel(&drive->back.c_two,DRV8835_FORWARD);
		break;
	case DRIVE_MOTOR_ALL:
		drv8835_set_direction(&drive->front,DRV8835_FORWARD);
		drv8835_set_direction(&drive->back,DRV8835_FORWARD);
		break;
	default:
		ASSERT(1);
	}
}
void drive_reverse(drive_t* drive,drive_motors_t motor){

		ASSERT(drive);
		ASSERT(drive->_state == DRIVE_NOT_INIT);

		switch(motor){
		case DRIVE_MOTOR_FRONT_RIGHT:
			drv8835_set_direction_channel(&drive->front.c_one,DRV8835_REVERSE);
			break;
		case DRIVE_MOTOR_FRONT_LEFT:
			drv8835_set_direction_channel(&drive->front.c_two,DRV8835_REVERSE);
			break;
		case DRIVE_MOTOR_BACK_RIGHT:
			drv8835_set_direction_channel(&drive->back.c_one,DRV8835_REVERSE);
			break;
		case DRIVE_MOTOR_BACK_LEFT:
			drv8835_set_direction_channel(&drive->back.c_two,DRV8835_REVERSE);
			break;
		case DRIVE_MOTOR_ALL:
			drv8835_set_direction(&drive->front,DRV8835_REVERSE);
			drv8835_set_direction(&drive->back,DRV8835_REVERSE);
			break;
		default:
			ASSERT(1);
		}
}

uint8_t drive_set_speed(drive_t* drive,drive_motors_t motor, uint16_t speed){
//todo catch return values of set speed
	ASSERT(drive);
	ASSERT(drive->_state == DRIVE_NOT_INIT);

	switch(motor){
	case DRIVE_MOTOR_FRONT_RIGHT:
		drv8835_set_speed_channel(&drive->front.c_one, speed);
		break;
	case DRIVE_MOTOR_FRONT_LEFT:
		drv8835_set_speed_channel(&drive->front.c_two,speed);
		break;
	case DRIVE_MOTOR_BACK_RIGHT:
		drv8835_set_speed_channel(&drive->back.c_one,speed);
		break;
	case DRIVE_MOTOR_BACK_LEFT:
		drv8835_set_speed_channel(&drive->back.c_two,speed);
		break;
	case DRIVE_MOTOR_ALL:
		drv8835_set_speed(&drive->front,speed);
		drv8835_set_speed(&drive->back,speed);
		break;
	default:
		ASSERT(1);
	}
	return 0;
}
