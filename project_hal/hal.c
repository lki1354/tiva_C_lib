/*
 * hal.c
 *
 *  Created on: Nov 12, 2015
 *      Author: lukas
 */

#include "hal.h"


#include "port_defines.h"
//#include "rgb.h"

gpio_pins_t buttons[4]={PIN_S1,PIN_S3,PIN_S4};

extern float pwm = 10;

gpio_pins_t m_enable[4] ={MVL_ENABLE,MVR_ENABLE,MHL_ENABLE,MHR_ENABLE};
gpio_pins_t m_phase[4] ={MVL_PHASE,MVR_PHASE,MHL_PHASE,MHR_PHASE};


void orange_led_toggel(uint32_t val){
	gpio_toggel(PIN_ORANGE);
}

void pwm_higher(uint32_t value){
	if(pwm <= 99){
		pwm +=1;
	}
	gpio_pwm_set_duty_cycle_pins(m_enable,4,pwm);
}
void pwm_lower(uint32_t value){
	if(pwm >= 11){
		pwm -=1;
	}
	gpio_pwm_set_duty_cycle_pins(m_enable,4,pwm);
}
uint8_t temp = 0;

void pwm_stop(uint32_t value){
	if( temp){
		gpio_pwm_stop_pins(m_enable,4);
		temp = 0;
	}else{
		gpio_pwm_start_pins(m_enable,4);
		temp = 1;
	}
}
void pwm_start(uint32_t value){

}


void hal_init(){
	//rgb_init();
	gpio_set_type(PIN_ORANGE,GPIO_TYPE_DIGITAL_OUTPUT_HIGH_CURRENT);
	//enable motor 3
	gpio_set_type_pins(m_enable,4,GPIO_TYPE_PWM_OUTPUT);
	gpio_set_type_pins(m_phase,4,GPIO_TYPE_DIGITAL_OUTPUT);
	gpio_pwm_set_duty_cycle_pins(m_enable,4,pwm);

	gpio_set_type_pins(buttons,3,GPIO_TYPE_BUTTON_INTERRUPT);
	//gpio_set_call_back(PIN_S1,rgb_brighter);
	//gpio_set_call_back(PIN_S2,rgb_darker);
	//gpio_set_call_back(PIN_S3,toggel_rgb);
	//gpio_set_call_back(PIN_S4,orange_led_toggel);
	gpio_set_call_back(PIN_S1,pwm_stop);
	//gpio_set_call_back(PIN_S2,);
	gpio_set_call_back(PIN_S3,pwm_lower);
	gpio_set_call_back(PIN_S4,pwm_higher);

	gpio_init();
	gpio_set(PIN_ORANGE);
	/*gpio_clear(MVL_PHASE);
	gpio_clear(MVR_PHASE);
	gpio_clear(MHL_PHASE);
	gpio_clear(MHR_PHASE); */
	gpio_set(MVL_PHASE);
	gpio_set(MVR_PHASE);
	gpio_set(MHL_PHASE);
	gpio_set(MHR_PHASE);

}
