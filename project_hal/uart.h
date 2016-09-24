/*! \file uart.h
 *  \brief Functions for handling the uart interface.
 *  \author Lukas Kiechle
 *  \date 2015-12-06 creat date
 *  \copyright  All rights belong to
 *
 *  $Date:  $
 *  $Revision: 0.1$
 *  $LastChangedDate: $
 */

#ifndef UART_H
#define UART_H

#include <stdint.h>
#include "serial_if.h"

/** @addtogroup UART_Modul
  * @{
  */

/*!
* \brief The function uart0_init is used to initialize the uart modul.*/
void uart0_init(uint32_t baudrate);
/*!
* \brief The function uart0_get_serial_if is used to get the structure pointer of the created serial interface. */
serial_t* uart0_get_serial_if();
/*!
* \brief The function uart0_read_FIFO_empty reads all bytes from input uart buffer to serial interface buffer. */
uint8_t uart0_read_FIFO_empty(void);
/*!
* \brief The function uart0_start_transmit writes all bytes from serial interface buffer to output uart buffer. */
void uart0_start_transmit(void);
/*!
* \brief The function UART0_ISR is the UART0 interrupt call function, reads incoming bytes to the serial interface buffer. */
extern void UART0_ISR(void);

/** @} */ /* End of group UART_Modul */

#endif /* PROJECT_HAL_UART_H_ */
