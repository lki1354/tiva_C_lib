/*! \file i2c.h
 *  \brief Functions for handling the i2c communication interface.
 *  \author Lukas Kiechle
 *  \date 2015-11-24 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 *
 */

#ifndef I2C_H
#define I2C_H

#include <stdint.h>
#include "buffer.h"
#include "mcu_type.h"

/*!
 * if the I2C_TYPE is not defined, a error massage will showen.
 */
#ifndef I2C_TYPE
	#error "Type for the I2C struct is not defined"
#endif

/** @addtogroup I2C_Modul
  * @{
  */

/*!
 * \brief the enum i2c_modules_t defines the modules which can be used */
typedef enum i2c_modules_t{I2C_MODULE_0=0x01,I2C_MODULE_1=0x02,I2C_MODULE_2=0x04,I2C_MODULE_3=0x08}i2c_modules_t;

/*!
 * \brief the enum i2c_result_t defines the return values for i2c functions */
typedef	enum i2c_result_t{
	I2C_NO_ERROR /*!< no problem, everything ok */,
	I2C_ERROR /*!< any problem occured */,
	I2C_TRANSMIT_ERROR /*!< something went wrong during transmiting data */,
	I2C_RECIEVE_ERROR, /*!< something went wrong during revieving data */
	I2C_BUFFER_EMPTY, /*!< no bytes in the buffer */
	I2C_BUFFER_FULL	/*!< buffer is full, it isn't possible to put more date in it */
}i2c_result_t;

/*!
 * \brief A structure for a i2c modul */
typedef struct i2c_object_t{
	I2C_TYPE* _modul;	/*!<  the i2c modul register pointer, internal use, is defined after init  */
	uint8_t address;	/*!< address of the i2c slave device, set with init function*/
	buffer_t* buffer;	/*!< a buffer for the transmit and revieve bytes, set with init function*/
}i2c_object_t;

/*!
* \brief The function initialize the i2c structure i2c_object_t.*/
i2c_result_t i2c_master_init(i2c_object_t* ,i2c_modules_t , uint8_t address, buffer_t* );

/*!
* \brief The function transmit the quantity of bytes to start_register in the slave device,
* but first the write bytes have to be but in the buffer. */
i2c_result_t i2c_write_nbytes(i2c_object_t* ,uint8_t start_register,uint8_t quantity);
/*!
* \brief The function recieves the quantity of bytes from start_register in the slave device,
* the read bytes from slave needed to get out of the buffer. */
i2c_result_t i2c_read_nbytes(i2c_object_t* ,uint8_t start_register,uint8_t quantity);

/*!
* \brief The function set only one bit (of 8 bits) at the position bitNum at the slave device.*/
i2c_result_t i2c_set_bit(i2c_object_t* i2c, uint8_t data_register, uint8_t bitNum);
/*!
* \brief The function clear only one bit (of 8 bits) at the position bitNum at the slave device.*/
i2c_result_t i2c_clear_bit(i2c_object_t* i2c, uint8_t data_register, uint8_t bitNum);
/*!
* \brief The function transmit a number of bits to the data_register in the slave device,
* but first the write bytes have to be but in the buffer. */
i2c_result_t i2c_write_bits(i2c_object_t* i2c, uint8_t data_register, uint8_t bit_start, uint8_t bit_length) ;

/** @} */ /* End of group I2C_Modul */


#endif /* PROJECT_HAL_HAL_TIVA_I2C_H_ */
