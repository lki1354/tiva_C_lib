/*! \file hal_timer.c
 *  \brief Implementation of hardware timer modul register handling.
 *  \author Lukas Kiechle
 *  \date 2015-12-06 creat date
 *  \copyright  All rights belong to
 *  \todo - implement interrupt
 *  	  - implement use of timer software timer modul
 *
 *  $Revision: 0.1$
 *  $LastChangedDate: $
 */

#include "hal_timer.h"
#include "mcu_type.h"
#include "debug.h"


void hal_timer_init(hal_timer_t* timer,hal_timer_modul_t modul){

	//! 1. enabel wide timer modul
	SYSCTL->RCGCWTIMER |= modul;

	//! 2. set right timer modul register address
	switch (modul){
		case HAL_TIMER_MODUL_0:
			timer->_modul = WTIMER0;
			while( (SYSCTL->PRWTIMER & HAL_TIMER_MODUL_0) == 0);
			break;
		case HAL_TIMER_MODUL_1:
			timer->_modul = WTIMER1;
			while( (SYSCTL->PRWTIMER & HAL_TIMER_MODUL_1) == 0);
			break;
		case HAL_TIMER_MODUL_2:
			timer->_modul = WTIMER2;
			while( (SYSCTL->PRWTIMER & HAL_TIMER_MODUL_2) == 0);
			break;
		case HAL_TIMER_MODUL_3:
			timer->_modul = WTIMER3;
			while( (SYSCTL->PRWTIMER & HAL_TIMER_MODUL_3) == 0);
			break;
		case HAL_TIMER_MODUL_4:
			timer->_modul = WTIMER4;
			while( (SYSCTL->PRWTIMER & HAL_TIMER_MODUL_4) == 0);
			break;
		case HAL_TIMER_MODUL_5:
			timer->_modul = WTIMER5;
			while( (SYSCTL->PRWTIMER & HAL_TIMER_MODUL_5) == 0);
			break;
		default:
			ASSERT(1);
			break;
	}
	//! 3. disable timer modul
	timer->_modul->CTL &= ~GPTMCTL_TEAN;	//! disable timer A

	//! 4. Timer mode and length
	//! 4.1 use 64bit, concatenated
	timer->_modul->CFG = GPTMCFG_COMBINED_MODE;
	// 4.1 use 32bit
	//timer->_modul->CFG = GPTMCFG_NORMAL_MODE;

	//! 5. Timer as periodic and count up
	timer->_modul->TAMR = GPTMTAMR_TAMR_PERIODIC | GPTMTAMR_TACDIR_UP;

	//! 6. Upper-Bound of Timer,
	//! When the timer is counting up, this register sets the upper bound for the timeout event.
	timer->_modul->TBILR = 0xFFFFFFFF; //! for 64bit use
	timer->_modul->TAILR = 0xFFFFFFFF;
	timer->_state = HAL_TIMER_INIT;

}

void hal_timer_start(hal_timer_t* timer){
	if(timer->_state == HAL_TIMER_NOT_INIT){
		ASSERT(1);
		return;
	}
	timer->_modul->CTL |= GPTMCTL_TEAN;	//! enable timer A
	timer->_state = HAL_TIMER_START;
}

void hal_timer_stop(hal_timer_t* timer){
	if(timer->_state == HAL_TIMER_NOT_INIT){
		ASSERT(1);
		return;
	}
	timer->_modul->CTL &= ~GPTMCTL_TEAN;	//! disable timer A
	timer->_state = HAL_TIMER_STOP;
}


uint64_t hal_timer_get_millisec(hal_timer_t* timer){
	uint64_t mill_sec = 0;
	if( (timer->_state == HAL_TIMER_NOT_INIT) |  (timer->_state == HAL_TIMER_INIT) ){
		ASSERT(1);
		return 0;
	}
	mill_sec = timer->_modul->TAR | ((uint64_t)timer->_modul->TBR <<32);  //! current timer value
	//! \todo check if result of muliplication is to large for a 64 multiplication
	mill_sec = (mill_sec * 1000) / SYS_CLOCK;	//! current timer value divided by amount of ticks per millisecond
	return mill_sec;
}

uint32_t hal_timer_get_millisec_32bit(hal_timer_t* timer){
	uint64_t mill_sec = 0;

	if( (timer->_state == HAL_TIMER_NOT_INIT) |  (timer->_state == HAL_TIMER_INIT) ){
		ASSERT(1);
		return 0;
	}

	mill_sec = timer->_modul->TAR | ((uint64_t)timer->_modul->TBR <<32);  //! current timer value
	//! \todo check if result of muliplication is to large for a 64 multiplication
	mill_sec = (mill_sec * 1000) / SYS_CLOCK;	//! current timer value divided by amount of ticks per millisecond
	return (uint32_t)mill_sec;
}
