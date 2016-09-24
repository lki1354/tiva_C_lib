/*
 * rgb.c
 *
 *  Created on: Nov 19, 2015
 *      Author: lukas
 */
#include "port_defines.h"
#include "rgb.h"

typedef struct{
	gpio_pins_t pins[3];
	rgb_color_t color;
	float brightness;
}rgb_led;

rgb_led rgb ={{PIN_RED,PIN_GREEN,PIN_BLUE},WHITE,50};

void rgb_init(void){
	//gpio_set_type_pins(rgb.pins,3,GPIO_TYPE_PWM_OUTPUT);
	//gpio_pin_init(PIN_RED,GPIO_TYPE_PWM_OUTPUT);
	//gpio_pin_init(PIN_GREEN,GPIO_TYPE_PWM_OUTPUT);
	//gpio_pin_init(PIN_BLUE,GPIO_TYPE_PWM_OUTPUT);
	gpio_pins_init(rgb.pins,3,GPIO_TYPE_PWM_OUTPUT);
	gpio_pwm_set_duty_cycle_pins(rgb.pins,3,rgb.brightness);
}

void rgb_brighter(uint32_t val){
	if(rgb.brightness<=99){
		rgb.brightness +=1;
	}
	gpio_pwm_set_duty_cycle_pins(rgb.pins,3,rgb.brightness);
}
void rgb_darker(uint32_t val){
	if(rgb.brightness>=1){
		rgb.brightness -=1;
	}
	gpio_pwm_set_duty_cycle_pins(rgb.pins,3,rgb.brightness);
}

void rgb_set_color(rgb_color_t color){
	rgb.color = color;
	switch(rgb.color ){
	case BLACK:
		gpio_pwm_stop_pins(rgb.pins,3);
		break;
	case RED:
		gpio_pwm_start(rgb.pins[RED]);
		gpio_pwm_stop(rgb.pins[BLUE]);
		gpio_pwm_stop(rgb.pins[GREEN]);
		break;
	case GREEN:
		gpio_pwm_start(rgb.pins[GREEN]);
		gpio_pwm_stop(rgb.pins[RED]);
		gpio_pwm_stop(rgb.pins[BLUE]);
		break;
	case BLUE:
		gpio_pwm_start(rgb.pins[BLUE]);
		gpio_pwm_stop(rgb.pins[RED]);
		gpio_pwm_stop(rgb.pins[GREEN]);
		break;
	case WHITE:
		gpio_pwm_start_pins(rgb.pins,3);
		break;
	}
}

void toggel_rgb(uint32_t val){
	static rgb_color_t color;
	switch(color){
	case WHITE:
		color = RED;
		break;
	case RED:
		color = BLUE;
		break;
	case BLUE:
		color = GREEN;
		break;
	case GREEN:
		color = WHITE;
		break;
	default:
		color = WHITE;
	}
	rgb_set_color(color);
}

