/*
 * gpio.c
 *
 *  Created on: Oct 29, 2015
 *      Author: lukas
 */

#include "gpio.h"
#include "mcu_type.h"



gpio_type_t gpio[GPIO_ALL_PINS];

gpio_type_t gpio[]={GPIO_TYPE_NOT_INIT};

void default_interrupt(uint32_t val){
	//! \todo what if this function is called, why this function is called but the interrupt on the pin is not enabled
}

void (* portA_call_backs[8])(uint32_t) = {default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt};
void (* portB_call_backs[8])(uint32_t) = {default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt};
void (* portC_call_backs[8])(uint32_t) = {default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt};
void (* portD_call_backs[8])(uint32_t) = {default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt};
void (* portE_call_backs[6])(uint32_t) = {default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt};
void (* portF_call_backs[5])(uint32_t) = {default_interrupt,default_interrupt,default_interrupt,default_interrupt,default_interrupt};

extern void Int_GPIO_Port_A_Handler(void){
	if((GPIOA_AHB->RIS & PIN0)){
		GPIOA_AHB->ICR = PIN0;
		portA_call_backs[0](1);
	}
	if((GPIOA_AHB->RIS & PIN1)){
		GPIOA_AHB->ICR = PIN1;
		portA_call_backs[1](1);
	}
	if((GPIOA_AHB->RIS & PIN2)){
		GPIOA_AHB->ICR = PIN2;
		portA_call_backs[2](1);
	}
	if((GPIOA_AHB->RIS & PIN3)){
		GPIOA_AHB->ICR = PIN3;
		portA_call_backs[3](1);
	}
	if((GPIOA_AHB->RIS & PIN4)){
		GPIOA_AHB->ICR = PIN4;
		portA_call_backs[4](1);
	}
	if((GPIOA_AHB->RIS & PIN5)){
		GPIOA_AHB->ICR = PIN5;
		portA_call_backs[5](1);
	}
	if((GPIOA_AHB->RIS & PIN6)){
		GPIOA_AHB->ICR = PIN6;
		portA_call_backs[6](1);
	}
	if((GPIOA_AHB->RIS & PIN7)){
		GPIOA_AHB->ICR = PIN7;
		portA_call_backs[7](1);
	}
}
extern void Int_GPIO_Port_B_Handler(void){
	if((GPIOB_AHB->RIS & PIN0)){
		GPIOB_AHB->ICR = PIN0;
		portB_call_backs[0](1);
	}
	if((GPIOB_AHB->RIS & PIN1)){
		GPIOB_AHB->ICR = PIN1;
		portB_call_backs[1](1);
	}
	if((GPIOB_AHB->RIS & PIN2)){
		GPIOB_AHB->ICR = PIN2;
		portB_call_backs[2](1);
	}
	if((GPIOB_AHB->RIS & PIN3)){
		GPIOB_AHB->ICR = PIN3;
		portB_call_backs[3](1);
	}
	if((GPIOB_AHB->RIS & PIN4)){
		GPIOB_AHB->ICR = PIN4;
		portB_call_backs[4](1);
	}
	if((GPIOB_AHB->RIS & PIN5)){
		GPIOB_AHB->ICR = PIN5;
		portB_call_backs[5](1);
	}
	if((GPIOB_AHB->RIS & PIN6)){
		GPIOB_AHB->ICR = PIN6;
		portB_call_backs[6](1);
	}
	if((GPIOB_AHB->RIS & PIN7)){
		GPIOB_AHB->ICR = PIN7;
		portB_call_backs[7](1);
	}
}
extern void Int_GPIO_Port_C_Handler(void){
	if((GPIOC_AHB->RIS & PIN0)){
		GPIOC_AHB->ICR = PIN0;
		portD_call_backs[0](1);
	}
	if((GPIOC_AHB->RIS & PIN1)){
		GPIOC_AHB->ICR = PIN1;
		portD_call_backs[1](1);
	}
	if((GPIOC_AHB->RIS & PIN2)){
		GPIOC_AHB->ICR = PIN2;
		portD_call_backs[2](1);
	}
	if((GPIOC_AHB->RIS & PIN3)){
		GPIOC_AHB->ICR = PIN3;
		portD_call_backs[3](1);
	}
	if((GPIOC_AHB->RIS & PIN4)){
		GPIOC_AHB->ICR = PIN4;
		portD_call_backs[4](1);
	}
	if((GPIOC_AHB->RIS & PIN5)){
		GPIOC_AHB->ICR = PIN5;
		portD_call_backs[5](1);
	}
	if((GPIOC_AHB->RIS & PIN6)){
		GPIOC_AHB->ICR = PIN6;
		portD_call_backs[6](1);
	}
	if((GPIOC_AHB->RIS & PIN7)){
		GPIOC_AHB->ICR = PIN7;
		portD_call_backs[7](1);
	}
}
extern void Int_GPIO_Port_D_Handler(void){
	if((GPIOD_AHB->RIS & PIN0)){
		GPIOD_AHB->ICR = PIN0;
		portD_call_backs[0](1);
	}
	if((GPIOD_AHB->RIS & PIN1)){
		GPIOD_AHB->ICR = PIN1;
		portD_call_backs[1](1);
	}
	if((GPIOD_AHB->RIS & PIN2)){
		GPIOD_AHB->ICR = PIN2;
		portD_call_backs[2](1);
	}
	if((GPIOD_AHB->RIS & PIN3)){
		GPIOD_AHB->ICR = PIN3;
		portD_call_backs[3](1);
	}
	if((GPIOD_AHB->RIS & PIN4)){
		GPIOD_AHB->ICR = PIN4;
		portD_call_backs[4](1);
	}
	if((GPIOD_AHB->RIS & PIN5)){
		GPIOD_AHB->ICR = PIN5;
		portD_call_backs[5](1);
	}
	if((GPIOD_AHB->RIS & PIN6)){
		GPIOD_AHB->ICR = PIN6;
		portD_call_backs[6](1);
	}
	if((GPIOD_AHB->RIS & PIN7)){
		GPIOD_AHB->ICR = PIN7;
		portD_call_backs[7](1);
	}
}
extern void Int_GPIO_Port_E_Handler(void){
	if((GPIOE_AHB->RIS & PIN0)){
		GPIOE_AHB->ICR = PIN0;
		portE_call_backs[0](1);
	}
	if((GPIOE_AHB->RIS & PIN1)){
		GPIOE_AHB->ICR = PIN1;
		portE_call_backs[1](1);
	}
	if((GPIOE_AHB->RIS & PIN2)){
		GPIOE_AHB->ICR = PIN2;
		portE_call_backs[2](1);
	}
	if((GPIOE_AHB->RIS & PIN3)){
		GPIOE_AHB->ICR = PIN3;
		portE_call_backs[3](1);
	}
	if((GPIOE_AHB->RIS & PIN4)){
		GPIOE_AHB->ICR = PIN4;
		portE_call_backs[4](1);
	}
	if((GPIOE_AHB->RIS & PIN5)){
		GPIOE_AHB->ICR = PIN5;
		portE_call_backs[5](1);
	}
}

extern void Int_GPIO_Port_F_Handler(void){
	if((GPIOF_AHB->RIS & PIN0)){
		GPIOF_AHB->ICR = PIN0;
		portF_call_backs[0](1);
	}
	if((GPIOF_AHB->RIS & PIN1)){
		GPIOF_AHB->ICR = PIN1;
		portF_call_backs[1](1);
	}
	if((GPIOF_AHB->RIS & PIN2)){
		GPIOF_AHB->ICR = PIN2;
		portF_call_backs[2](1);
	}
	if((GPIOF_AHB->RIS & PIN3)){
		GPIOF_AHB->ICR = PIN3;
		portF_call_backs[3](1);
	}
	if((GPIOF_AHB->RIS & PIN4)){
		GPIOF_AHB->ICR = PIN4;
		portF_call_backs[4](1);
	}
}


__STATIC_INLINE void pwm_enable_modul(uint32_t modul){

	SYSCTL->RCGCPWM |= modul;
	while((SYSCTL->PRPWM & modul) ==0);	/*!< wait for PWM Module Peripheral Ready */

}

__STATIC_INLINE void M0PWM0_count_down(void){
//todo check if right settings
	pwm_enable_modul(PWM_MODUL_0);
	//PWM
    PWM0->_0_CTL |= PWM_CTL_COUNT_DOWN;
    PWM0->_0_GENA = GEN_PIN_LOW(ACTION_COMP_A_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM0->_0_LOAD = 3300;  //Set the period.
    PWM0->_0_CMPA = PWM0->_0_LOAD*(10/100.0); //duty cycle
    PWM0->_0_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}
__STATIC_INLINE void M0PWM1_count_down(void){
//todo check if right settings
	pwm_enable_modul(PWM_MODUL_0);
	//PWM
    PWM0->_0_CTL |= PWM_CTL_COUNT_DOWN;
    PWM0->_0_GENB = GEN_PIN_LOW(ACTION_COMP_B_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM0->_0_LOAD = 3300;  //Set the period.
    PWM0->_0_CMPB = PWM0->_0_LOAD*(10/100.0); //duty cycle
    PWM0->_0_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}
__STATIC_INLINE void M0PWM2_count_down(void){
//todo check if right settings M1PWM4
	pwm_enable_modul(PWM_MODUL_0);
	//PWM
    PWM0->_1_CTL |= PWM_CTL_COUNT_DOWN;
    PWM0->_1_GENA = GEN_PIN_LOW(ACTION_COMP_A_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM0->_1_LOAD = 3300;  //Set the period.
    PWM0->_1_CMPA = PWM0->_1_LOAD*(10/100.0); //duty cycle
    PWM0->_1_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}
__STATIC_INLINE void M0PWM3_count_down(void){
//todo check if right settings
	pwm_enable_modul(PWM_MODUL_0);
	//PWM
    PWM0->_1_CTL |= PWM_CTL_COUNT_DOWN;
    PWM0->_1_GENB = GEN_PIN_LOW(ACTION_COMP_B_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM0->_1_LOAD = 3300;  //Set the period.
    PWM0->_1_CMPB = PWM0->_1_LOAD*(10/100.0); //duty cycle
    PWM0->_1_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}
__STATIC_INLINE void M0PWM4_count_down(void){
//todo check if right settings
	pwm_enable_modul(PWM_MODUL_0);
	//PWM
    PWM0->_2_CTL |= PWM_CTL_COUNT_DOWN;
    PWM0->_2_GENA = GEN_PIN_LOW(ACTION_COMP_A_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM0->_2_LOAD = 3300;  //Set the period.
    PWM0->_2_CMPA = PWM0->_2_LOAD*(10/100.0); //duty cycle
    PWM0->_2_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}
__STATIC_INLINE void M0PWM5_count_down(void){
//todo check if right settings
	pwm_enable_modul(PWM_MODUL_0);
	//PWM
    PWM0->_2_CTL |= PWM_CTL_COUNT_DOWN;
    PWM0->_2_GENB = GEN_PIN_LOW(ACTION_COMP_B_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM0->_2_LOAD = 3300;  //Set the period.
    PWM0->_2_CMPB = PWM0->_2_LOAD*(10/100.0); //duty cycle
    PWM0->_2_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}
__STATIC_INLINE void M0PWM6_count_down(void){
//todo check if right settings
	pwm_enable_modul(PWM_MODUL_0);
	//PWM
    PWM0->_3_CTL |= PWM_CTL_COUNT_DOWN;
    PWM0->_3_GENA = GEN_PIN_LOW(ACTION_COMP_A_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM0->_3_LOAD = 3300;  //Set the period.
    PWM0->_3_CMPA = PWM0->_3_LOAD*(10/100.0); //duty cycle
    PWM0->_3_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}
__STATIC_INLINE void M0PWM7_count_down(void){
//todo check if right settings
	pwm_enable_modul(PWM_MODUL_0);
	//PWM
    PWM0->_3_CTL |= PWM_CTL_COUNT_DOWN;
    PWM0->_3_GENB = GEN_PIN_LOW(ACTION_COMP_B_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM0->_3_LOAD = 3300;  //Set the period.
    PWM0->_3_CMPB = PWM0->_3_LOAD*(10/100.0); //duty cycle
    PWM0->_3_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}

__STATIC_INLINE void M1PWM0_count_down(void){
//todo check if right settings
	pwm_enable_modul(PWM_MODUL_1);
	//PWM
    PWM1->_0_CTL |= PWM_CTL_COUNT_DOWN;
    PWM1->_0_GENA = GEN_PIN_LOW(ACTION_COMP_A_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM1->_0_LOAD = 3300;  //Set the period.
    PWM1->_0_CMPA = PWM1->_0_LOAD*(10/100.0); //duty cycle
    PWM1->_0_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}

__STATIC_INLINE void M1PWM1_count_down(void){

	pwm_enable_modul(PWM_MODUL_1);
	//PWM
	//
    PWM1->_0_CTL |= PWM_CTL_COUNT_DOWN;
    PWM1->_0_GENB = GEN_PIN_LOW(ACTION_COMP_B_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM1->_0_LOAD = 3300;  //Set the period.
    PWM1->_0_CMPB = PWM1->_0_LOAD*(10/100.0); //duty cycle
    PWM1->_0_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}
__STATIC_INLINE void M1PWM2_count_down(void){
//todo check if right settings
	pwm_enable_modul(PWM_MODUL_1);
	//PWM
    PWM1->_1_CTL |= PWM_CTL_COUNT_DOWN;
    PWM1->_1_GENA = GEN_PIN_LOW(ACTION_COMP_A_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM1->_1_LOAD = 3300;  //Set the period.
    PWM1->_1_CMPA = PWM1->_1_LOAD*(10/100.0); //duty cycle
    PWM1->_1_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}

__STATIC_INLINE void M1PWM3_count_down(void){

	pwm_enable_modul(PWM_MODUL_1);
	//PWM
	//
    PWM1->_1_CTL |= PWM_CTL_COUNT_DOWN;
    PWM1->_1_GENB = GEN_PIN_LOW(ACTION_COMP_B_DOWN) | GEN_PIN_HIGH(ACTION_COUNTER_ZERO);
    PWM1->_1_LOAD = 3300;  //Set the period.
    PWM1->_1_CMPB = PWM1->_1_LOAD*(10/100.0); //duty cycle
    PWM1->_1_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}

__STATIC_INLINE void M1PWM4_count_down(void){
//todo check if right settings M1PWM4
	pwm_enable_modul(PWM_MODUL_1);
	//PWM
    PWM1->_2_CTL |= PWM_CTL_COUNT_DOWN;
    PWM1->_2_GENA = GEN_PIN_HIGH(ACTION_COMP_A_DOWN) | GEN_PIN_LOW(ACTION_COUNTER_ZERO);
    PWM1->_2_LOAD = 3300;  //Set the period.
    PWM1->_2_CMPA = PWM1->_2_LOAD*(10/100.0); //duty cycle
    PWM1->_2_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}

__STATIC_INLINE void M1PWM5_count_down(void){
//PF1
	pwm_enable_modul(PWM_MODUL_1);
	//PWM
	//
    PWM1->_2_CTL |= PWM_CTL_COUNT_DOWN;
    PWM1->_2_GENB = GEN_PIN_HIGH(ACTION_COMP_B_DOWN) | GEN_PIN_LOW(ACTION_COUNTER_ZERO);
    PWM1->_2_LOAD = 3300;  //Set the period.
    PWM1->_2_CMPB = PWM1->_2_LOAD*(10/100.0); //duty cycle
    PWM1->_2_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}
__STATIC_INLINE void M1PWM6_count_down(void){

	pwm_enable_modul(PWM_MODUL_1);
	//PWM
    PWM1->_3_CTL |= PWM_CTL_COUNT_DOWN;
    PWM1->_3_GENA = GEN_PIN_HIGH(ACTION_COMP_A_DOWN) | GEN_PIN_LOW(ACTION_COUNTER_ZERO);
    PWM1->_3_LOAD = 3300;  //Set the period.
    PWM1->_3_CMPA = PWM1->_3_LOAD*(10/100.0); //duty cycle
    PWM1->_3_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}
__STATIC_INLINE void M1PWM7_count_down(void){

	pwm_enable_modul(PWM_MODUL_1);
	//PWM
    PWM1->_3_CTL |= PWM_CTL_COUNT_DOWN;
    PWM1->_3_GENB = GEN_PIN_HIGH(ACTION_COMP_B_DOWN) | GEN_PIN_LOW(ACTION_COUNTER_ZERO);
    PWM1->_3_LOAD = 3300;  //Set the period.
    PWM1->_3_CMPB = PWM1->_3_LOAD*(10/100.0); //duty cycle
    PWM1->_3_CTL |= PWM_CTL_ENABLE;	//PWM timer start
}

__STATIC_INLINE void nvic_enable_port_ir(GPIOA_Type* gpio){
	if(gpio == GPIOA_AHB){
		NVIC_EnableIRQ(GPIOA_IRQn);
	}else if(gpio == GPIOB_AHB){
		NVIC_EnableIRQ(GPIOB_IRQn);
	}else if(gpio == GPIOC_AHB){
		NVIC_EnableIRQ(GPIOC_IRQn);
	}else if(gpio == GPIOD_AHB){
		NVIC_EnableIRQ(GPIOD_IRQn);
	}else if(gpio == GPIOE_AHB){
		NVIC_EnableIRQ(GPIOE_IRQn);
	}else if(gpio == GPIOF_AHB){
		NVIC_EnableIRQ(GPIOF_IRQn);
	}
}
__STATIC_INLINE void pwm_enable_portA_moduls(pin_value_t pin){
	switch(pin){
		case PIN6:
			M1PWM2_count_down();
			break;
		case PIN7:
			M1PWM3_count_down();
			break;
		default:
			//todo write error log
			break;
	}
}
__STATIC_INLINE void pwm_enable_portB_moduls(pin_value_t pin){
	switch(pin){
		case PIN4:
			M0PWM2_count_down();
			break;
		case PIN5:
			M0PWM3_count_down();
			break;
		case PIN6:
			M0PWM0_count_down();
			break;
		case PIN7:
			M0PWM1_count_down();
			break;
		default:
			//todo write error log
			break;
	}
}
__STATIC_INLINE void pwm_enable_portC_moduls(pin_value_t pin){  //todo check if modul is used
	switch(pin){
		case PIN4:
			M0PWM6_count_down();
			break;
		case PIN5:
			M0PWM7_count_down();
			break;
		default:
			//todo write error log

			break;
	}
}
__STATIC_INLINE void pwm_enable_portD_moduls(pin_value_t pin){  //todo check if modul is used
	switch(pin){
		case PIN0:
			M1PWM0_count_down();
			break;
		case PIN1:
			M1PWM1_count_down();
			break;
		default:
			//todo write error log
			break;
	}
}
__STATIC_INLINE void pwm_enable_portE_moduls(pin_value_t pin){  //todo check if modul is used
	switch(pin){
		case PIN4:
			M0PWM4_count_down();
			break;
		case PIN5:
			M0PWM5_count_down();
			break;
		default:
			//todo write error log
			break;
	}
}

__STATIC_INLINE void pwm_enable_portF_moduls(pin_value_t pin){  //todo check if modul is used
	switch(pin){
		case PIN0:
			M1PWM4_count_down();
			break;
		case PIN1:
			M1PWM5_count_down();
			break;
		case PIN2:
			M1PWM6_count_down();
			break;
		case PIN3:
			M1PWM7_count_down();
			break;
		default:
			//! \todo write error log
			break;
	}
}

__STATIC_INLINE void pwm_pin_config(GPIOA_Type* gpio,pin_bits_t pin_bit){
	pin_value_t pin = (pin_value_t)(1<<pin_bit);

	if(gpio == GPIOA_AHB){
		//SYSCTL->RCGC2 |= PORTA;//todo ???? wird benötigt?Clock (PWM)
		pwm_enable_portA_moduls(pin);
		gpio->PCTL |= GPIO_PCTL_M1PWM(pin_bit);
	}else if(gpio == GPIOB_AHB){
		//SYSCTL->RCGC2 |= PORTB;//todo ???? wird benötigt?Clock (PWM)
		pwm_enable_portB_moduls(pin);
		gpio->PCTL |= GPIO_PCTL_M0PWM(pin_bit);
	}else if(gpio == GPIOC_AHB){
		//SYSCTL->RCGC2 |= PORTC;//todo ???? wird benötigt?Clock (PWM)
		pwm_enable_portC_moduls(pin);
		gpio->PCTL |= GPIO_PCTL_M0PWM(pin_bit);
	}else if(gpio == GPIOD_AHB){
		//SYSCTL->RCGC2 |= PORTD;//todo ???? wird benötigt?Clock (PWM)
		pwm_enable_portD_moduls(pin);
		gpio->PCTL |= GPIO_PCTL_M1PWM(pin_bit);
	}else if(gpio == GPIOE_AHB){
		//SYSCTL->RCGC2 |= PORTE;//todo ???? wird benötigt?Clock (PWM)
		pwm_enable_portE_moduls(pin);
		gpio->PCTL |= GPIO_PCTL_M0PWM(pin_bit);
	}else if(gpio == GPIOF_AHB){
		//SYSCTL->RCGC2 |= PORTF;//todo ???? wird benötigt?Clock (PWM)
		pwm_enable_portF_moduls(pin);
		gpio->PCTL |= GPIO_PCTL_M1PWM(pin_bit);
	}

}
__STATIC_INLINE void portA_clock_enable(void){
	SYSCTL->RCGCGPIO |=PORTA;
	//wait for peref. ready
	while((SYSCTL->PRGPIO & PORTA) == 0);
    SYSCTL->GPIOHBCTL |= PORTA;
}
__STATIC_INLINE void portB_clock_enable(void){
	SYSCTL->RCGCGPIO |=PORTB;
	//wait for peref. ready
	while((SYSCTL->PRGPIO & PORTB) == 0);
    SYSCTL->GPIOHBCTL |= PORTB;
}
__STATIC_INLINE void portC_clock_enable(void){
	SYSCTL->RCGCGPIO |=PORTC;
	//wait for peref. ready
	while((SYSCTL->PRGPIO & PORTC) == 0);
    SYSCTL->GPIOHBCTL |= PORTC;
}
__STATIC_INLINE void portD_clock_enable(void){
	SYSCTL->RCGCGPIO |=PORTD;
	//wait for peref. ready
	while((SYSCTL->PRGPIO & PORTD) == 0);
    SYSCTL->GPIOHBCTL |= PORTD;
}
__STATIC_INLINE void portE_clock_enable(void){
	SYSCTL->RCGCGPIO |=PORTE;
	//wait for peref. ready
	while((SYSCTL->PRGPIO & PORTE) == 0);
    SYSCTL->GPIOHBCTL |= PORTE;
}
__STATIC_INLINE void portF_clock_enable(void){
	SYSCTL->RCGCGPIO |=PORTF;
	//wait for peref. ready
	while((SYSCTL->PRGPIO & PORTF) == 0);
    SYSCTL->GPIOHBCTL |= PORTF;
}


static void gpio_config_standard(GPIOA_Type* gpio, pin_bits_t pin_bit, gpio_type_t type){
	pin_value_t pin = (pin_value_t) (1<<pin_bit);
	if(gpio == GPIOF_AHB && pin == PIN0){
		gpio->LOCK |= 0x4C4F434B;	//! The GPIOLOCK register enables write access to the GPIOCR register (see page 685). Writing 0x4C4F.434B to the GPIOLOCK register unlocks the GPIOCR register.
		gpio->CR |= pin;
	}
	switch (type){
	  case GPIO_TYPE_BUTTON_INTERRUPT:
		nvic_enable_port_ir(gpio);
		gpio->IM &= (~pin);	//! Disable Interrupts for GPIO-Pin of Button (GPIOIM)
		gpio->IS &= (~pin);	//! Configure Interrupts for Falling Edges for GPIO-Pin of Button (GPIOIS, GPIOIBE, GPIOIEV)
		gpio->IBE &= (~pin);
		gpio->IEV &= (~pin);
		gpio->ICR |= pin;		//! Clear Interrupts for GPIO-Pin of Button (GPIOICR)
		gpio->IM |= pin;		//! Enable Interrupts for GPIO-Pin of Button (GPIOIM
	  case GPIO_TYPE_DIGITAL_INPUT_PULL_UP:
		  gpio->PUR |= pin; //! Pull-Up GPIO-Pin of Button (GPIOPUR)
	  case GPIO_TYPE_DIGITAL_INPUT:
		  gpio->DIR &= (~pin);	//Set as input
		  gpio->DEN |= pin;	//! Enable Digital Function of GPIO-Pin of Button (GPIOEEN)
		  break;
	  case GPIO_TYPE_DIGITAL_INPUT_PULL_DOWN:
		  gpio->PDR |= pin; //! Pull-down GPIO-Pin of Button (GPIOPUR)
		  gpio->DIR &= (~pin);	//Set as input
		  gpio->DEN |= pin;	//! Enable Digital Function of GPIO-Pin of Button (GPIOEEN)
		  break;
	  case GPIO_TYPE_PWM_OUTPUT:
		pwm_pin_config(gpio,pin_bit);
		gpio->AFSEL |= pin;
	  case GPIO_TYPE_DIGITAL_OUTPUT_HIGH_CURRENT:
		  gpio->DR8R |= pin;
	  case GPIO_TYPE_DIGITAL_OUTPUT:
		  gpio->DIR |= pin;
		  gpio->DEN |= pin;
		  break;
	  case GPIO_TYPE_DIGITAL_OUTPUT_OPEN_DRAIN:
		  gpio->ODR |= pin;
		  gpio->DIR |= pin;
		  gpio->DEN |= pin;
		  break;
	  case GPIO_TYPE_I2C_SDA:
		  gpio->ODR 	|= pin;
	  case GPIO_TYPE_I2C_SCL:
		  gpio->AFSEL   |= pin;
		  gpio->DEN 	|= pin;
		  gpio->PCTL 	|= GPIO_PCTL_I2C(pin_bit);
		  break;
	  case GPIO_TYPE_UART:
		  gpio->AFSEL   |= pin;
		  gpio->DEN 	|= pin;
		  gpio->PCTL 	|= GPIO_PCTL_UART(pin_bit);
		  break;
	  case GPIO_TYPE_NOT_INIT:
		  // set all other pins as output zero on the port
		  //gpio->DIR |= pin;
		  //gpio->DEN &= ~pin;
		  break;
	  default:
		  break;
	}
}
void gpio_pin_init(gpio_pins_t pin, gpio_type_t type){
	gpio[pin] = type;
	if(pin >= PA0 && pin <= PA7){
		portA_clock_enable();
		gpio_config_standard(GPIOA_AHB,(pin_bits_t)(pin-PA0),gpio[pin]);
	}else if(pin >= PB0 && pin <= PB7){
		portB_clock_enable();
		gpio_config_standard(GPIOB_AHB,(pin_bits_t)(pin-PB0),gpio[pin]);
	}else if(pin >= PC0 && pin <= PC7){
		portC_clock_enable();
		gpio_config_standard(GPIOC_AHB,(pin_bits_t)(pin-PC0),gpio[pin]);
	}else if(pin >= PD0 && pin <= PD7){
		portD_clock_enable();
		gpio_config_standard(GPIOD_AHB,(pin_bits_t)(pin-PD0),gpio[pin]);
	}else if(pin >= PE0 && pin <= PE5){
		portE_clock_enable();
		gpio_config_standard(GPIOE_AHB,(pin_bits_t)(pin-PE0),gpio[pin]);
	}else if(pin >= PF0 && pin <= PF4){
		portF_clock_enable();
		gpio_config_standard(GPIOF_AHB,(pin_bits_t)(pin-PF0),gpio[pin]);
	}
}
void gpio_pins_init(gpio_pins_t* pins,uint8_t pin_quantity, gpio_type_t type){

	while(pin_quantity){
		pin_quantity--;
		gpio_pin_init(pins[pin_quantity],type);
	}
}

void gpio_init(){
	uint8_t pin_counter;
	//init Port A
	pin_counter = 0;
	portA_clock_enable();
	while(pin_counter < 8){
		gpio_config_standard(GPIOA_AHB,(pin_bits_t)pin_counter,gpio[PA0+pin_counter]);
		pin_counter++;
	}
	//init Port B
	pin_counter = 0;
	portB_clock_enable();
	while(pin_counter < 8){
		gpio_config_standard(GPIOB_AHB,(pin_bits_t)pin_counter,gpio[PB0+pin_counter]);
		pin_counter++;
	}
	//init Port C
	pin_counter = 0;
	portC_clock_enable();
	while(pin_counter < 8){
		gpio_config_standard(GPIOC_AHB,(pin_bits_t)pin_counter,gpio[PC0+pin_counter]);
		pin_counter++;
	}
	//init Port D
	pin_counter = 0;
	portD_clock_enable();
	while(pin_counter < 8){
		gpio_config_standard(GPIOD_AHB,(pin_bits_t)pin_counter,gpio[PD0+pin_counter]);
		pin_counter++;
	}
	//init Port E
	pin_counter = 0;
	portE_clock_enable();
	while(pin_counter < 6){
		gpio_config_standard(GPIOE_AHB,(pin_bits_t)pin_counter,gpio[PE0+pin_counter]);
		pin_counter++;
	}
	//init Port F
	pin_counter = 0;
	portF_clock_enable();
	while(pin_counter < 5){
		gpio_config_standard(GPIOF_AHB,(pin_bits_t)pin_counter,gpio[PF0+pin_counter]);
		pin_counter++;
	}

//	gpio[GPIO_PINS_INIT] = GPIO_TYPE_PINS_INIT;
}

void gpio_set_type(gpio_pins_t pin, gpio_type_t type){
	gpio[pin] = type;
}


void gpio_set_type_pins(gpio_pins_t* pins,uint8_t pin_quantity, gpio_type_t type){

	while(pin_quantity){
		pin_quantity--;
		gpio[pins[pin_quantity]] = type;
	}
}

void gpio_pwm_start(gpio_pins_t pin){
//	if(gpio[GPIO_PINS_INIT] == 0) {return;}
	if(gpio[pin] == GPIO_TYPE_NOT_INIT) {return;}
	if(gpio[pin] != GPIO_TYPE_PWM_OUTPUT) {return;}

	switch(pin){
	case PA6:
		PWM1->ENABLE |=  ENABLE_MnPWM2;
		break;
	case PA7:
		PWM1->ENABLE |=  ENABLE_MnPWM3;
		break;
	case PB4:
		PWM0->ENABLE |=  ENABLE_MnPWM2;
		break;
	case PB5:
		PWM0->ENABLE |=  ENABLE_MnPWM3;
		break;
	case PB6:
		PWM0->ENABLE |=  ENABLE_MnPWM0;
		break;
	case PB7:
		PWM0->ENABLE |=  ENABLE_MnPWM1;
		break;
	case PC4:
		PWM0->ENABLE |=  ENABLE_MnPWM6;
		break;
	case PC5:
		PWM0->ENABLE |=  ENABLE_MnPWM7;
		break;
	case PD0:
		PWM1->ENABLE |=  ENABLE_MnPWM0;
		break;
	case PD1:
		PWM1->ENABLE |=  ENABLE_MnPWM1;
		break;
	case PE4:
		PWM0->ENABLE |=  ENABLE_MnPWM4;
		break;
	case PE5:
		PWM0->ENABLE |=  ENABLE_MnPWM5;
		break;
	case PF0:
		PWM1->ENABLE |=  ENABLE_MnPWM4;	//enable PWM
		break;
	case PF1:
		PWM1->ENABLE |=  ENABLE_MnPWM5;	//enable PWM
		break;
	case PF2:
		PWM1->ENABLE |=  ENABLE_MnPWM6;	//enable PWM
		break;
	case PF3:
		PWM1->ENABLE |=  ENABLE_MnPWM7;	//enable PWM
		break;
	}
}

void gpio_pwm_stop(gpio_pins_t pin){
//	if(gpio[GPIO_PINS_INIT] == 0) {return;}
	if(gpio[pin] == GPIO_TYPE_NOT_INIT) {return;}
	if(gpio[pin] != GPIO_TYPE_PWM_OUTPUT) {return;}

	switch(pin){
	case PA6:
		PWM1->ENABLE &= ~ENABLE_MnPWM2;
		break;
	case PA7:
		PWM1->ENABLE &= ~ENABLE_MnPWM3;
		break;
	case PB4:
		PWM0->ENABLE &= ~ENABLE_MnPWM2;
		break;
	case PB5:
		PWM0->ENABLE &= ~ENABLE_MnPWM3;
		break;
	case PB6:
		PWM0->ENABLE &= ~ENABLE_MnPWM0;
		break;
	case PB7:
		PWM0->ENABLE &= ~ENABLE_MnPWM1;
		break;
	case PC4:
		PWM0->ENABLE &= ~ENABLE_MnPWM6;
		break;
	case PC5:
		PWM0->ENABLE &= ~ENABLE_MnPWM7;
		break;
	case PD0:
		PWM1->ENABLE &= ~ENABLE_MnPWM0;
		break;
	case PD1:
		PWM1->ENABLE &= ~ENABLE_MnPWM1;
		break;
	case PE4:
		PWM0->ENABLE &= ~ENABLE_MnPWM4;
		break;
	case PE5:
		PWM0->ENABLE &= ~ENABLE_MnPWM5;
		break;
	case PF0:
		PWM1->ENABLE &= ~ENABLE_MnPWM4;	//enable PWM
		break;
	case PF1:
		PWM1->ENABLE &= ~ENABLE_MnPWM5;	//enable PWM
		break;
	case PF2:
		PWM1->ENABLE &= ~ENABLE_MnPWM6;	//enable PWM
		break;
	case PF3:
		PWM1->ENABLE &= ~ENABLE_MnPWM7;	//enable PWM
		break;
	}
}

void gpio_pwm_start_pins(gpio_pins_t* pins,uint8_t pin_quantity){
	while(pin_quantity){
		pin_quantity--;
		gpio_pwm_start(pins[pin_quantity]);
	}
}
void gpio_pwm_stop_pins(gpio_pins_t* pins,uint8_t pin_quantity){
	while(pin_quantity){
		pin_quantity--;
		gpio_pwm_stop(pins[pin_quantity]);
	}
}

void gpio_pwm_set_duty_cycle(gpio_pins_t pin,float value){
//	if(gpio[GPIO_PINS_INIT] == 0) {return;}
	if(gpio[pin] == GPIO_TYPE_NOT_INIT) {return;}
	if(gpio[pin] != GPIO_TYPE_PWM_OUTPUT) {return;}

	if(value >= 100 || value < 0){
		return;
	}
	switch(pin){
	case PA6:
		PWM1->_1_CMPA = PWM1->_1_LOAD*(value/100.0);
		break;
	case PA7:
		PWM1->_1_CMPB = PWM1->_1_LOAD*(value/100.0);
		break;
	case PB4:
		PWM0->_1_CMPA = PWM0->_1_LOAD*(value/100.0);
		break;
	case PB5:
		PWM0->_1_CMPB = PWM0->_1_LOAD*(value/100.0);
		break;
	case PB6:
		PWM0->_0_CMPA = PWM0->_0_LOAD*(value/100.0);
		break;
	case PB7:
		PWM0->_0_CMPB = PWM0->_0_LOAD*(value/100.0);
		break;
	case PC4:
		PWM0->_3_CMPA = PWM0->_3_LOAD*(value/100.0);
		break;
	case PC5:
		PWM0->_3_CMPB = PWM0->_3_LOAD*(value/100.0);
		break;
	case PD0:
		PWM1->_0_CMPA = PWM1->_0_LOAD*(value/100.0);
		break;
	case PD1:
		PWM1->_0_CMPB = PWM1->_0_LOAD*(value/100.0);
		break;
	case PE4:
		PWM0->_2_CMPA = PWM0->_2_LOAD*(value/100.0);
		break;
	case PE5:
		PWM0->_2_CMPB = PWM0->_2_LOAD*(value/100.0);
		break;
	case PF0:
		PWM1->_2_CMPA = PWM1->_2_LOAD*(value/100.0);
		break;
	case PF1:
		PWM1->_2_CMPB = PWM1->_2_LOAD*(value/100.0);
		break;
	case PF2:
		PWM1->_3_CMPB = PWM1->_3_LOAD*(value/100.0); //duty cycle
		break;
	case PF3:
		PWM1->_3_CMPA = PWM1->_3_LOAD*(value/100.0); //duty cycle
		break;
	}
}
float gpio_pwm_get_duty_cycle(gpio_pins_t pin){
	float value = 0;
//	if(gpio[GPIO_PINS_INIT] == 0) {return 0;}
	if(gpio[pin] == GPIO_TYPE_NOT_INIT) {return 0;}
	if(gpio[pin] != GPIO_TYPE_PWM_OUTPUT) {return 0;}

	switch(pin){
	case PA6:
		value = PWM1->_1_CMPA *100.0 / PWM1->_1_LOAD;
		break;
	case PA7:
		value = PWM1->_1_CMPB *100.0 / PWM1->_1_LOAD;
		break;
	case PB4:
		value = PWM0->_1_CMPA *100.0 / PWM0->_1_LOAD;
		break;
	case PB5:
		value = PWM0->_1_CMPB *100.0 / PWM0->_1_LOAD;
		break;
	case PB6:
		value = PWM0->_0_CMPA *100.0 / PWM0->_0_LOAD;
		break;
	case PB7:
		value = PWM0->_0_CMPB *100.0 / PWM0->_0_LOAD;
		break;
	case PC4:
		value = PWM0->_3_CMPA *100.0 / PWM0->_3_LOAD;
		break;
	case PC5:
		value = PWM0->_3_CMPB *100.0 / PWM0->_3_LOAD;
		break;
	case PD0:
		value = PWM1->_0_CMPA *100.0 / PWM1->_0_LOAD;
		break;
	case PD1:
		value = PWM1->_0_CMPB *100.0 / PWM1->_0_LOAD;
		break;
	case PE4:
		value = PWM0->_2_CMPA *100.0 / PWM0->_2_LOAD;
		break;
	case PE5:
		value = PWM0->_2_CMPB *100.0 / PWM0->_2_LOAD;
		break;
	case PF0:
		value = PWM1->_2_CMPA *100.0 / PWM1->_2_LOAD;
		break;
	case PF1:
		value = PWM1->_2_CMPB *100.0 / PWM1->_2_LOAD;
		break;
	case PF2:
		value = PWM1->_3_CMPB*100.0 / PWM1->_3_LOAD; //duty cycle
		break;
	case PF3:
		value = PWM1->_3_CMPA *100.0 /PWM1->_3_LOAD; //duty cycle
		break;
	}
	return value;
}

void gpio_pwm_set_duty_cycle_pins(gpio_pins_t* pins,uint8_t pin_quantity,float value){
	while(pin_quantity){
		pin_quantity--;
		gpio_pwm_set_duty_cycle(pins[pin_quantity],value);
	}
}

void gpio_set(gpio_pins_t pin){
//	if(gpio[GPIO_PINS_INIT] == 0) {return;}
	if(gpio[pin] == GPIO_TYPE_NOT_INIT) {return;}
	//if(gpio[pin] != GPIO_TYPE_DIGITAL_OUTPUT ) {return;}
	//if(gpio[pin] != GPIO_TYPE_DIGITAL_OUTPUT_HIGH_CURRENT ) {return;}
	//if(gpio[pin] != GPIO_TYPE_DIGITAL_OUTPUT_OPEN_DRAIN ) {return;}

	if(pin >= PA0 && pin <= PA7){
		GPIOA_AHB->DATA |= 1<<(pin - PA0);
	}else if(pin >= PB0 && pin <= PB7){
		GPIOB_AHB->DATA |= 1<<(pin - PB0);
	}else if(pin >= PC0 && pin <= PC7){
		GPIOC_AHB->DATA |= 1<<(pin - PC0);
	}else if(pin >= PD0 && pin <= PD7){
		GPIOD_AHB->DATA |= 1<<(pin - PD0);
	}else if(pin >= PE0 && pin <= PE5){
		GPIOE_AHB->DATA |= 1<<(pin - PE0);
	}else if(pin >= PF0 && pin <= PF4){
		GPIOF_AHB->DATA |= 1<<(pin - PF0);
	}
}
void gpio_clear(gpio_pins_t pin){
//	if(gpio[GPIO_PINS_INIT] == 0) {return;}
	if(gpio[pin] == GPIO_TYPE_NOT_INIT) {return;}
	//if(gpio[pin] != GPIO_TYPE_DIGITAL_OUTPUT ) {return;}
	//if(gpio[pin] != GPIO_TYPE_DIGITAL_OUTPUT_HIGH_CURRENT ) {return;}
	//if(gpio[pin] != GPIO_TYPE_DIGITAL_OUTPUT_OPEN_DRAIN ) {return;}

	if(pin >= PA0 && pin <= PA7){
		GPIOA_AHB->DATA &= ~(1<<(pin - PA0));
	}
	if(pin >= PB0 && pin <= PB7){
		GPIOB_AHB->DATA &= ~(1<<(pin - PB0));
	}
	if(pin >= PC0 && pin <= PC7){
		GPIOC_AHB->DATA &= ~(1<<(pin - PC0));
	}
	if(pin >= PD0 && pin <= PD7){
		GPIOD_AHB->DATA &= ~(1<<(pin - PD0));
	}
	if(pin >= PE0 && pin <= PE5){
		GPIOE_AHB->DATA &= ~(1<<(pin - PE0));
	}
	if(pin >= PF0 && pin <= PF4){
		GPIOF_AHB->DATA &= ~(1<<(pin - PF0));
	}
}


void gpio_toggel(gpio_pins_t pin){
//	if(gpio[GPIO_PINS_INIT] == 0) {return;}
	if(gpio[pin] == GPIO_TYPE_NOT_INIT) {return;}
	//if(gpio[pin] != GPIO_TYPE_DIGITAL_OUTPUT ) {return;}
	//if(gpio[pin] != GPIO_TYPE_DIGITAL_OUTPUT_HIGH_CURRENT ) {return;}
	//if(gpio[pin] != GPIO_TYPE_DIGITAL_OUTPUT_OPEN_DRAIN ) {return;}

	if(pin >= PA0 && pin <= PA7){
		GPIOA_AHB->DATA ^= (1<<(pin - PA0));
	}
	if(pin >= PB0 && pin <= PB7){
		GPIOB_AHB->DATA ^= (1<<(pin - PB0));
	}
	if(pin >= PC0 && pin <= PC7){
		GPIOC_AHB->DATA ^= (1<<(pin - PC0));
	}
	if(pin >= PD0 && pin <= PD7){
		GPIOD_AHB->DATA ^= (1<<(pin - PD0));
	}
	if(pin >= PE0 && pin <= PE5){
		GPIOE_AHB->DATA ^= (1<<(pin - PE0));
	}
	if(pin >= PF0 && pin <= PF4){
		GPIOF_AHB->DATA ^= (1<<(pin - PF0));
	}

}

void gpio_set_call_back(gpio_pins_t pin, void (*call_back)(uint32_t)){

	if(pin >= PA0 && pin <= PA7){
		portA_call_backs[(pin - PA0)]=call_back;;
	}
	if(pin >= PB0 && pin <= PB7){
		portB_call_backs[(pin - PB0)]=call_back;;
	}
	if(pin >= PC0 && pin <= PC7){
		portC_call_backs[(pin - PC0)]=call_back;;
	}
	if(pin >= PD0 && pin <= PD7){
		portD_call_backs[(pin - PD0)]=call_back;;
	}
	if(pin >= PE0 && pin <= PE5){
		portE_call_backs[(pin - PE0)]=call_back;;
	}
	if(pin >= PF0 && pin <= PF4){
		portF_call_backs[(pin - PF0)]=call_back;;
	}
}
