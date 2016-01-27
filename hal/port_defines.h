/*! \file port_defines.h
 *  \brief Includes and define the used pins from the microcontroller
 *  \author Lukas Kiechle
 *  \date 2015-11-12 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 */


#ifndef PORT_DEFINES_H
#define PORT_DEFINES_H

#include "gpio.h"
#include "i2c.h"


/** @addtogroup HAL
  * @{
  */

#ifdef TIVA_BOARD

	#define I2C_MPU9150_MODUL I2C_MODULE_3

	#define PIN_RED PF1
	#define PIN_BLUE PF2
	#define PIN_GREEN PF3

	#define PIN_ORANGE PD2

	#define PIN_S1 PF4
	#define PIN_S2 PF0
	#define PIN_S3 PD3
	#define PIN_S4 PE1

	#define MFL_ENABLE	PF3
	#define MFL_PHASE	PE4
	#define MFR_ENABLE	PF2
	#define MFR_PHASE	PD0
	#define MBL_ENABLE	PF1
	#define MBL_PHASE	PB4
	#define MBR_ENABLE	PF0	//PD7
	#define MBR_PHASE	PD1

	#define DRIVE_MODE_PIN PD2

#elif ST_BOARD

#endif

/** @} */ /* End of group HAL */


#endif /* PROJECT_HAL_PORT_DEFINES_H_ */
