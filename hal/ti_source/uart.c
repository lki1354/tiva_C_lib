/*! \file uart.c
 *  \brief Implementation of uart modul register handling.
 *  \author Lukas Kiechle
 *  \date 2015-12-06 creat date
 *  \copyright  All rights belong to
 *  \todo - create more modular
 *  	  - use system defined Clock
 *  	  - should I make for each uart modul a own functions or with a enum? Same as in i2c.h
 *
 *  $Revision: 0.1$
 *  $LastChangedDate: $
 */
#include "mcu_type.h"
#include "uart.h"
#include "gpio.h"

SERIAL_IF(uart0, 255);

//Port A pin 0 und 1
#define UART0_PIN_RX PA0
#define UART0_PIN_RT PA1

/*!
* \details A function which initialize all importend (needed) registers of the controller for the uart0 interface
* @param baudrate initilize the uart interface with the baudrate to use
*/
void uart0_init(uint32_t baudrate){
	SYSCTL->RCGCUART |= UART_MODUL0;
	NVIC_EnableIRQ(UART0_IRQn);
	//SYSCTL->RCGCGPIO |=PORTA;
	//wait for peref. ready
	while((SYSCTL->PRUART & UART_MODUL0) == 0);
	//Configure Baud-Rate of 115200 (UARTIBRD, UARTFBRD)
	float UARTSysClk = 16000000;
	float ClkDiv = 16;
	float brd = UARTSysClk / (ClkDiv * baudrate);
	gpio_pin_init(UART0_PIN_RX,GPIO_TYPE_UART);
	gpio_pin_init(UART0_PIN_RT,GPIO_TYPE_UART);
	//    5. Disable UART (UARTCTL)
	UART0->CTL = UART0->CTL&0xFFFFFFFE;

	UART0->IBRD = (uint16_t) brd;
	UART0->FBRD = (uint8_t)( (brd - UART0->IBRD)*64 + 0.5);
	//7. Enable FIFO (UARTLCRH)
	//8. Set Word-Length to 8 bit (UARTLCRH)
	//9. Disable Parity (UARTLCRH)
	UART0->LCRH = UART_FEN | UART_WLEN_8_BIT;
	//10. Set Clock to SysClock (UARTCC)
	UART0->CC = 0;
	UART0->IFLS = UART_IFLS_RX_1_4_F; //|UART_IFLS_TX_7_8_E
	UART0->IM = UART_RXISR; //|UART_TXISR
	//11. Enable UART (UARTCTL)
	UART0->CTL |= 0x01;

}

/*!
* \details A function which returns the internal serial interface.
* @return returns the serial interface pointer for the uart0 modul
*/
serial_t* uart0_get_serial_if(){
	return &uart0;
}

/*!
* \details puts the oldest byte from uart0 input fifo to the uart0 output fifo
*/
void uart0_echo(){
	if( (UART0->FR & UART_RXFE) == 0){
		UART0->DR = UART0->DR;
	}
}

/*!
* \details writes one byte to the uart0 output buffer
* @param byte which will be written into the output buffer
*/
void uart0_write_byte(uint8_t byte){
	if(UART0->FR & UART_TXFF) {
		return ;
	}
	UART0->DR = byte;
}

/*!
* \details reads one byte from the uart0 incoming buffer, waits as long as no bye is in the buffer to read
* @return gives one byte from the incoming fifo
*/
uint8_t uart0_read_byte_wait(void){
	while( (UART0->FR & UART_RXFE) == 0){
		return UART0->DR;
	}
	return 0;
}

/*!
* \details reads all bytes from the uart0 incoming buffer to the serial interface buffer
* @return returns an error if serial buffer is full, otherwise 0
* \todo check if serial interface buffer is full
*/
uint8_t uart0_read_FIFO_empty(void){
	while( (UART0->FR & UART_RXFE) == 0){
		buffer_write_byte(uart0.in_buffer,UART0->DR);
	}
	return 0;
}

/*!
* \details puts all bytes from serial interface buffer to uart0 buffer
* \todo check if uart0 buffer is full
*/
void uart0_start_transmit(void){
	while( buffer_get_size(uart0.out_buffer) ){
		if(UART0->FR & UART_TXFF){
			return;
		}
		UART0->DR = buffer_read_byte(uart0.out_buffer);
	}
}

/*!
* \details interrupt routine from uart0 modul, puts all bytes from incoming buffer to serial interface input buffer
* \todo check if serial interface buffer is full
* \todo check if unused code is useful
* \todo do the variable 'val' still needed
*/
void UART0_ISR(void){
	uint16_t val=0;
/*	if(UART0->RIS & UART_TXISR){
		UART0->ICR |= UART_TXISR;
		if( buffer_get_size(uart0.out_buffer) ){
			if( UART0->FR & UART_TXFF ) {
				return;
			}
			UART0->DR = buffer_read_byte(uart0.out_buffer);
		}
	}
*/
	if(UART0->RIS & UART_RXISR){
		UART0->ICR |= UART_RXISR;
		while( (UART0->FR & UART_RXFE) == 0){
			val=UART0->DR;
			buffer_write_byte(uart0.in_buffer,val);
		}

	}
}
