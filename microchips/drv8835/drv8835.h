/*! \file drv8835.h
 *  \brief Modul for handling the control of the DC motor driver drv8835 from TI
 *  \author Lukas Kiechle
 *  \date 2016-01-13 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 */

#ifndef DRV8835_H
#define DRV8835_H

#include <stdint.h>
#include "gpio.h"

/** @addtogroup DRV8835_Modul
  * @{
  */

/*!
 * \brief the enum drv8835_state_t defines the different modul states*/
typedef enum{ DRV8835_NOT_INIT,DRV8835_INIT,DRV8835_ALL_DISABLED,DRV8835_ALL_ENABLED,
	          DRV8835_CHANNEL_1_ENABLED,DRV8835_CHANNEL_2_ENABLED}drv8835_state_t;

/*!
* \brief the enum drv8835_direction_t defines two direction of rotation for the motor  */
typedef enum{ DRV8835_FORWARD,DRV8835_REVERSE }drv8835_direction_t;

/*!
* \brief the enum drv8835_direction_t defines two direction of rotation for the motor  */
typedef struct drv8835_channel_t{
	uint16_t _speed;	//!< in 1/100 %
	gpio_pins_t _pin_direction;	//!< internal use, which pin is used for direction of rotation
	gpio_pins_t _pin_speed; //!< internal use, which pin is used for speed control
}drv8835_channel_t;

typedef struct{
	drv8835_state_t state;
	drv8835_channel_t c_one;
	drv8835_channel_t c_two;
	gpio_pins_t _pin_mode;
}drv8835_driver_t;

void drv8835_init(drv8835_driver_t*);
void drv8835_set_speed(drv8835_driver_t*, uint16_t speed);
void drv8835_set_direction(drv8835_driver_t* , drv8835_direction_t );
void drv8835_enable(drv8835_driver_t* );
void drv8835_disable(drv8835_driver_t* );

void drv8835_set_speed_channel(drv8835_channel_t* , uint16_t speed);
void drv8835_set_direction_channel(drv8835_channel_t* , drv8835_direction_t );
void drv8835_enable_channel(drv8835_channel_t* );
void drv8835_disable_channel(drv8835_channel_t* );

/** @} */ /* End of group DRV8835_Modul */

#endif /* MICROCHIPS_DRV8835_H_ */
