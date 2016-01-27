/*! \file hal_timer.h
 *  \brief Functions and objects for the hardware timers.
 *  \author Lukas Kiechle
 *  \date 2015-12-06 creat date
 *  \copyright  All rights belong to
 *  \version 0.1
 *  \todo - create more modular
 *  	  - use system defined Clock
 *  	  - should I make for each uart modul a own functions or with a enum? Same as in i2c.h
 *
 */

#ifndef HAL_TIMER_H
#define HAL_TIMER_H

#include <stdint.h>

#include "mcu_type.h"

/** @addtogroup HAL_TIMER_Modul
  * @{
  */

/*!
 * \brief the enum hal_timer_modul_t defines the modules which can be used */
typedef enum hal_timer_modul_t{HAL_TIMER_MODUL_0=0x01,HAL_TIMER_MODUL_1=0x02,HAL_TIMER_MODUL_2=0x04,HAL_TIMER_MODUL_3=0x08,HAL_TIMER_MODUL_4=0x10,HAL_TIMER_MODUL_5=0x20,}hal_timer_modul_t;
/*!
 * \brief the enum hal_timer_state_t defines the states of the hal_timer modul*/
typedef enum hal_timer_state_t{HAL_TIMER_NOT_INIT,HAL_TIMER_INIT,HAL_TIMER_START,HAL_TIMER_STOP}hal_timer_state_t;

/*!
 * \brief the struct hal_timer_t stores the required information of the hal_timer modul*/
typedef struct hal_timer_t{
	hal_timer_state_t _state;	//!< internal use, save actual status
	HAL_TIMER_TYPE* _modul;	//!< internal use, the timer modul register pointer, is defined after init
}hal_timer_t;

/*!
 * \brief initialize the hal_timer_t objekt, set modul register and prepare for use */
void hal_timer_init(hal_timer_t*,hal_timer_modul_t);

/*!
 * \brief function starts the hardware timer */
void hal_timer_start(hal_timer_t* timer);

/*!
 * \brief function stops the hardware timer */
void hal_timer_stop(hal_timer_t* timer);

/*!
* \brief function gets the actual time since start with 64bit value */
uint64_t hal_timer_get_millisec(hal_timer_t* timer);

/*!
 * \brief function gets the actual time since start with 32bit value */
uint32_t hal_timer_get_millisec_32bit(hal_timer_t* timer);

/** @} */ /* End of group HAL_TIMER_Modul */

#endif /* PROJECT_HAL_HAL_TIMER_H_ */
