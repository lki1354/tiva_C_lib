/*! \file mcu_type.h
 *  \brief Includes and define the used microcontroller include files
 *  \author Lukas Kiechle
 *  \date 2016-01-14 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 */

#ifndef MCU_TYPE
#define MCU_TYPE

/** @addtogroup HAL
  * @{
  */

#ifdef TIVA_BOARD

	#include "TM4C123GH6PM.h"
	#define I2C_TYPE I2C0_Type
	#define HAL_TIMER_TYPE WTIMER0_Type
	#define SYS_CLOCK 16000000

#elif ST_BOARD

#endif

#ifndef TIVA_BOARD
#ifndef ST_BOARD
	#error "no board is defined"
#endif
#endif

/** @} */ /* End of group HAL */

#endif /* PROJECT_HAL_MCU_TYPE_H_ */
