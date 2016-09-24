/*! \file drive.h
 *  \brief data structures and functions for controll all four motors
 *  \author Lukas Kiechle
 *  \date 2016-01-11 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 *
 */
#ifndef DRIVE_H
#define DRIVE_H
#include <stdint.h>
#include "drv8835.h"
#include "gpio.h"

/** @addtogroup DRIVE_Modul
  * @{
  */


/*!
 * \brief the enum drive_state_t defines the modul states */
typedef enum drive_state_t{ DRIVE_NOT_INIT,DRIVE_DISABLE,DRIVE_ENABLE,DRIVE_ERROR}drive_state_t;
/*!
 * \brief the enum drive_motors_t defines mositions of all four motors */
typedef enum drive_motors_t{ DRIVE_MOTOR_FRONT_RIGHT,DRIVE_MOTOR_FRONT_LEFT,
			  DRIVE_MOTOR_BACK_RIGHT,DRIVE_MOTOR_BACK_LEFT,DRIVE_MOTOR_ALL}drive_motors_t;

/*!
* \brief structure drive_t stores the required information of the drive_t modul */
typedef struct drive_t{
	drive_state_t _state;	//!< internal use, stores the actual state of the modul
	drv8835_driver_t front;	//!< instance of the front DC motor driver objekt
	drv8835_driver_t back;	//!< instance of the back DC motor driver objekt
}drive_t;


/*!
* \brief initialize the drive object with the assigned (allocated) pins*/
void drive_init(drive_t* drive, gpio_pins_t mode_pin);
/*!
* \brief  assign (allocate) the pins for actuate (gate, ansteueren) the motor drivers, have to be done before call driver_init */
void drive_set_pin(drive_t* ,drive_motors_t, gpio_pins_t speed_pin,gpio_pins_t direction_pin);
/*!
* \brief enables the speed pins output*/
void drive_enable(drive_t* ,drive_motors_t);
/*!
* \brief disables the speed pins output*/
void drive_disable(drive_t* ,drive_motors_t);
/*!
* \brief change motor direction of rotation to forward (right, clockwise)*/
void drive_forward(drive_t* ,drive_motors_t);
/*!
* \brief change motor direction of rotation to backword (left)*/
void drive_reverse(drive_t* ,drive_motors_t);
/*!
* \brief change the rotation speed of a motor or for all*/
uint8_t drive_set_speed(drive_t* ,drive_motors_t , uint16_t speed);

/** @} */ /* End of group DRIVE_Modul */

#endif /* DRIVE_H_ */
