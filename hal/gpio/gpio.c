/*
 * gpio.c
 *
 *  Created on: Oct 10, 2015
 *      Author: lukas
 */
#include <stdint.h>

#include "gpio.h"


#define SET_PIN_CONFIG(set_register,pin,state)  set_register = ( 0x000000FF & (state ? set_register|pin :  set_register & (~pin) ) );

static void portA_settings_hbus(uint8_t pin,HW_TYPE_GPIO_PAD pad,uint8_t state){

  switch(pad){
	case HW_TYPE_GPIO_DATA:
	  SET_PIN_CONFIG(GPIO_PORTA_AHB_DATA_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIR:
	  SET_PIN_CONFIG(GPIO_PORTA_AHB_DIR_R,pin,state);
	 break;
	case HW_TYPE_GPIO_2MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTA_AHB_DR2R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_4MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTA_AHB_DR4R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_8MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTA_AHB_DR8R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_PULL_UP:
	  SET_PIN_CONFIG(GPIO_PORTA_AHB_PUR_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIGITAL_FUNTION:
	  SET_PIN_CONFIG(GPIO_PORTA_AHB_DEN_R,pin,state);
	  break;
  }
}

static void portB_settings_hbus(uint8_t pin,HW_TYPE_GPIO_PAD pad,uint8_t state){

  switch(pad){
	case HW_TYPE_GPIO_DATA:
	  SET_PIN_CONFIG(GPIO_PORTB_AHB_DATA_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIR:
	  SET_PIN_CONFIG(GPIO_PORTB_AHB_DIR_R,pin,state);
	 break;
	case HW_TYPE_GPIO_2MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTB_AHB_DR2R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_4MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTB_AHB_DR4R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_8MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTB_AHB_DR8R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_PULL_UP:
	  SET_PIN_CONFIG(GPIO_PORTB_AHB_PUR_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIGITAL_FUNTION:
	  SET_PIN_CONFIG(GPIO_PORTB_AHB_DEN_R,pin,state);
	  break;
  }
}

static void portC_settings_hbus(uint8_t pin,HW_TYPE_GPIO_PAD pad,uint8_t state){

  switch(pad){
	case HW_TYPE_GPIO_DATA:
	  SET_PIN_CONFIG(GPIO_PORTC_AHB_DATA_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIR:
	  SET_PIN_CONFIG(GPIO_PORTC_AHB_DIR_R,pin,state);
	 break;
	case HW_TYPE_GPIO_2MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTC_AHB_DR2R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_4MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTC_AHB_DR4R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_8MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTC_AHB_DR8R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_PULL_UP:
	  SET_PIN_CONFIG(GPIO_PORTC_AHB_PUR_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIGITAL_FUNTION:
	  SET_PIN_CONFIG(GPIO_PORTC_AHB_DEN_R,pin,state);
	  break;
  }
}

static void portD_settings_hbus(uint8_t pin,HW_TYPE_GPIO_PAD pad,uint8_t state){

  switch(pad){
	case HW_TYPE_GPIO_DATA:
	  SET_PIN_CONFIG(GPIO_PORTD_AHB_DATA_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIR:
	  SET_PIN_CONFIG(GPIO_PORTD_AHB_DIR_R,pin,state);
	 break;
	case HW_TYPE_GPIO_2MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTD_AHB_DR2R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_4MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTD_AHB_DR4R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_8MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTD_AHB_DR8R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_PULL_UP:
	  SET_PIN_CONFIG(GPIO_PORTD_AHB_PUR_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIGITAL_FUNTION:
	  SET_PIN_CONFIG(GPIO_PORTD_AHB_DEN_R,pin,state);
	  break;
  }
}

static void portE_settings_hbus(uint8_t pin,HW_TYPE_GPIO_PAD pad,uint8_t state){

  switch(pad){
	case HW_TYPE_GPIO_DATA:
	  SET_PIN_CONFIG(GPIO_PORTE_AHB_DATA_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIR:
	  SET_PIN_CONFIG(GPIO_PORTE_AHB_DIR_R,pin,state);
	 break;
	case HW_TYPE_GPIO_2MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTE_AHB_DR2R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_4MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTE_AHB_DR4R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_8MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTE_AHB_DR8R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_PULL_UP:
	  SET_PIN_CONFIG(GPIO_PORTE_AHB_PUR_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIGITAL_FUNTION:
	  SET_PIN_CONFIG(GPIO_PORTE_AHB_DEN_R,pin,state);
	  break;
  }

}

static void portF_settings_hbus(uint8_t pin,HW_TYPE_GPIO_PAD pad,uint8_t state){

  switch(pad){
	case HW_TYPE_GPIO_DATA:
	  SET_PIN_CONFIG(GPIO_PORTF_AHB_DATA_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIR:
	  SET_PIN_CONFIG(GPIO_PORTF_AHB_DIR_R,pin,state);
	 break;
	case HW_TYPE_GPIO_2MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTF_AHB_DR2R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_4MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTF_AHB_DR4R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_8MA_DRIVER:
	  SET_PIN_CONFIG(GPIO_PORTF_AHB_DR8R_R,pin,state);
	  break;
	case HW_TYPE_GPIO_PULL_UP:
	  SET_PIN_CONFIG(GPIO_PORTF_AHB_PUR_R,pin,state);
	  break;
	case HW_TYPE_GPIO_DIGITAL_FUNTION:
	  SET_PIN_CONFIG(GPIO_PORTF_AHB_DEN_R,pin,state);
	  break;
  }
}


/*******************************************************************
functions
********************************************************************/

void gpio_pad_config_hbus(HW_TYPE_GPIO_PORTS port,uint8_t pin,HW_TYPE_GPIO_PAD pad,uint8_t state){

  switch(port){
    case PORTA:
  	  portA_settings_hbus(pin,pad,state);
  	  break;
    case PORTB:
	  portB_settings_hbus(pin,pad,state);
	  break;
    case PORTC:
	  portC_settings_hbus(pin,pad,state);
	  break;
    case PORTD:
	  portD_settings_hbus(pin,pad,state);
	  break;
    case PORTE:
	  portE_settings_hbus(pin,pad,state);
	  break;
    case PORTF:
      portF_settings_hbus(pin,pad,state);
      break;
  }
}

void gpio_enable(HW_TYPE_GPIO_PORTS port,uint8_t pin){
	gpio_pad_config_hbus(port,pin,HW_TYPE_GPIO_DATA,HW_TYPE_ENABLE);
}

void gpio_disable(HW_TYPE_GPIO_PORTS port,uint8_t pin){
	gpio_pad_config_hbus(port,pin,HW_TYPE_GPIO_DATA,HW_TYPE_DISABLE);
}
