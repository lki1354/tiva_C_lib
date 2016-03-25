/*! \file buffer.c
 *  \brief 
 *  \author Lukas Kiechle
 *  \date 2016-01-11 creat date
 *  \copyright  
 *	\version 0.1
 */

#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>
#include <stdarg.h>
#include "modules.h"

/** @addtogroup buffer_Modul
  * @{
  */

//typedef uint8_t buffer_size_t;

/* common variables and data structures */
typedef struct buffer_t {
  uint8_t max_bytes; // maximum amount of bytes in the buffer
  uint8_t *data;            // pointer to the byte array
  uint8_t _position_in;   // index for current byte to write
  uint8_t _position_out;  // index for current byte to read
} buffer_t;

/* initialisation */
void buffer_init(buffer_t *, uint8_t *data, uint8_t len); // initialise the buffer (also used to clear)

/* general buffer function */
void buffer_clear(buffer_t *); // reset the buffer

int16_t buffer_write_byte(buffer_t *, uint8_t byte); // write a byte to the buffer, -1 returned if full
int16_t buffer_write_bytes(buffer_t *, uint8_t *data, uint8_t len); // write bytes to the buffer, -1 returned not enough space left

int16_t buffer_read_byte(buffer_t *); // read a byte from the buffer, -1 returned if empty
int16_t buffer_read_bytes(buffer_t *, uint8_t *data, uint8_t len); // read bytes from the buffer, -1 returned if not enough bytes in buffer

buffer_size_t buffer_get_size(buffer_t *buffer); // get the amount of bytes in the buffer
buffer_size_t buffer_get_capacity(buffer_t *buffer); // get the maximum amount of bytes that have been in the buffer

/* other definitions */
#define BUFFER_CREATE(name, len) uint8_t name ## _data[len]; \
          buffer_t name = {len, name ## _data,0,0}

/** @} */ /* End of group Buffer_Modul */

#endif
