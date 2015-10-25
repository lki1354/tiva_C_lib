/*
 * main.c
 */

#include "hal/syscontrol/syscontrol.h"
#include "hal/gpio/gpio.h"

void delay(void){
  volatile int i = 0;
  for(;i<1000000;i++){
	  (void)i;
  }
}


void main(void) {

	sysctl_GPIO_enable(PORTF,HIGH_BUS);
	uint8_t rgb = PIN1|PIN2|PIN3;
	gpio_pad_config_hbus(PORTF,rgb,HW_TYPE_GPIO_DIR,HW_TYPE_GPIO_OUTPUT);
	gpio_pad_config_hbus(PORTF,rgb,HW_TYPE_GPIO_DIGITAL_FUNTION,HW_TYPE_ENABLE);

	
  while(1){
	  delay();
	  gpio_enable(PORTF,rgb);
	  delay();
	  gpio_disable(PORTF,rgb);
  }
}
