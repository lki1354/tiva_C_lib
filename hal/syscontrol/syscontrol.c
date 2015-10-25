/*
 * syscontrol.c
 *
 *  Created on: Oct 10, 2015
 *      Author: lukas
 */
#include "syscontrol.h"

void sysctl_GPIO_enable(HW_TYPE_GPIO_PORTS port, HW_TYPE_GPIO_BUS bus){

  switch(port){
   case PORTA:
	 SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_PORTA;
     switch(bus){
       case PERIPHERAL_BUS:
         break;
       case HIGH_BUS:
    	   SYSCTL_GPIOHBCTL_R |= SYSCTL_GPIOHBCTL_PORTA;
         break;
	}
    case PORTB:
  	 SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_PORTB;
	   switch(bus){
		 case PERIPHERAL_BUS:
		   break;
		 case HIGH_BUS:
		   SYSCTL_GPIOHBCTL_R |= SYSCTL_GPIOHBCTL_PORTB;
		   break;
   }
   case PORTC:
	 SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_PORTC;
	 switch(bus){
	   case PERIPHERAL_BUS:
		 break;
	   case HIGH_BUS:
		   SYSCTL_GPIOHBCTL_R |= SYSCTL_GPIOHBCTL_PORTC;
		 break;
	}
   case PORTD:
	 SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_PORTD;
	 switch(bus){
	   case PERIPHERAL_BUS:
		 break;
	   case HIGH_BUS:
		   SYSCTL_GPIOHBCTL_R |= SYSCTL_GPIOHBCTL_PORTD;
		 break;
	}
   case PORTE:
	 SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_PORTE;
	 switch(bus){
	   case PERIPHERAL_BUS:
		 break;
	   case HIGH_BUS:
		   SYSCTL_GPIOHBCTL_R |= SYSCTL_GPIOHBCTL_PORTE;
		 break;
	}
   case PORTF:
	 SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_PORTF;
	 switch(bus){
	   case PERIPHERAL_BUS:
		 break;
	   case HIGH_BUS:
		   SYSCTL_GPIOHBCTL_R |= SYSCTL_GPIOHBCTL_PORTF;
		 break;
	}
  }
}

