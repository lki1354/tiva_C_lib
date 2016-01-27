/*! \file i2c.c
 *  \brief Implementation of i2c modul functions.
 *  \author Lukas Kiechle
 *  \date 2015-11-24 creat date
 *  \copyright  All rights belong to
 *	\todo check if all errors are handled
 *
 *  $Date:  $
 *  $Revision: 0.1$
 *  $LastChangedDate: $
 */
#include "i2c.h"
#include "gpio.h"

#define I2C_MODUL_0_SCL PB2
#define I2C_MODUL_0_SDA PB3
#define I2C_MODUL_1_SCL PA6
#define I2C_MODUL_1_SDA PA7
#define I2C_MODUL_2_SCL PE4
#define I2C_MODUL_2_SDA PE5
#define I2C_MODUL_3_SCL PD0
#define I2C_MODUL_3_SDA PD1


/*!
* \details A function which initialize all importend (needed) registers of the controller for the uart0 interface
* @param i2c needs the pointer of a i2c object, which is to initialize
* @param modul which i2c hardware modul will be use
* @param address the slave address for the connection device
* @param buffer a pointer of a buffer for the data exchange
* @return if the initialization was successful or not, one of the i2c_result_t defination
*/
i2c_result_t i2c_master_init(i2c_object_t* i2c, i2c_modules_t modul, uint8_t address, buffer_t* buffer){
	switch (modul) {
	case I2C_MODULE_0:
		i2c->_modul = I2C0;
		SYSCTL->RCGCI2C |= I2C_MODULE_0;
		gpio_pin_init(I2C_MODUL_0_SDA,GPIO_TYPE_I2C_SDA);
		gpio_pin_init(I2C_MODUL_0_SCL,GPIO_TYPE_I2C_SCL);
		break;
	case I2C_MODULE_1:
		i2c->_modul = I2C1;
		SYSCTL->RCGCI2C |= I2C_MODULE_1;
		gpio_pin_init(I2C_MODUL_1_SDA,GPIO_TYPE_I2C_SDA);
		gpio_pin_init(I2C_MODUL_1_SCL,GPIO_TYPE_I2C_SCL);
		break;
	case I2C_MODULE_2:
		i2c->_modul = I2C2;
		SYSCTL->RCGCI2C |= I2C_MODULE_2;
		gpio_pin_init(I2C_MODUL_2_SDA,GPIO_TYPE_I2C_SDA);
		gpio_pin_init(I2C_MODUL_2_SCL,GPIO_TYPE_I2C_SCL);
		break;
	case I2C_MODULE_3:
		i2c->_modul = I2C3;
		SYSCTL->RCGCI2C |= I2C_MODULE_3;
		gpio_pin_init(I2C_MODUL_3_SDA,GPIO_TYPE_I2C_SDA);
		gpio_pin_init(I2C_MODUL_3_SCL,GPIO_TYPE_I2C_SCL);
		break;
	default:
		return I2C_ERROR;
	}
	i2c->address = address<<1;
	i2c->buffer = buffer;
	i2c->_modul->MCR |= I2C_MCR_MASTER_ENABLE;
	return I2C_NO_ERROR;

}

/*!
* \details A function which writes bytes to the slave device, first the transmited bytes have to be stored in the buffer
* @param i2c pointer of an i2c object with the required infromation
* @param start_register where the data in the slave as to be store
* @param quantity how many bytes want to be transmited to the slave
* @return if transmit data was successful or not, one of the i2c_result_t defination
*
* \todo check if uncommented code is useful
*/
i2c_result_t i2c_write_nbytes(i2c_object_t* i2c,uint8_t start_register,uint8_t quantity){
	uint8_t i = 0;
	int16_t buffer_byte = 0;
	i2c->_modul->MSA = i2c->address | I2C_TRANSMIT;
	i2c->_modul->MDR = start_register;
	while( (i2c->_modul->MCS & I2C_MCS_R_BUSBSY) );
	i2c->_modul->MCS = I2C_MCS_W_RUN | I2C_MCS_W_START;
	//while( (I2C3->MCS & I2C_MCS_R_BUSY) );//&& (I2C3->MCS & I2C_MCS_R_ERROR) == 0);
	while (i <= quantity){
		while( (i2c->_modul->MCS & I2C_MCS_R_BUSY) );//&& (I2C3->MCS & I2C_MCS_R_ERROR) == 0);
			if( (i2c->_modul->MCS & I2C_MCS_R_ERROR) ){
				if( i2c->_modul->MCS & I2C_MCS_R_ARBLST){
					i2c->_modul->MCS = I2C_MCS_W_RUN | I2C_MCS_W_STOP;
				}
				return I2C_TRANSMIT_ERROR;
			}
			if(i >= quantity){
				return I2C_NO_ERROR;
			}
			buffer_byte=buffer_read_byte(i2c->buffer);
			if(buffer_byte != -1){
				i2c->_modul->MDR = buffer_byte;
			}else{
				i2c->_modul->MCS = I2C_MCS_W_RUN | I2C_MCS_W_STOP;
				return I2C_BUFFER_EMPTY;
			}
			i++;
			i2c->_modul->MCS = I2C_MCS_W_RUN | ( (i<quantity)? 0: I2C_MCS_W_STOP );

	}
	return I2C_ERROR;
}

/*!
* \details A function which reads bytes from the slave device, the recived bytes are stored in the buffer
* @param i2c pointer of an i2c object with the required infromation
* @param start_register where the desired data in the slave are placed
* @param quantity how many bytes want to be read from the slave
* @return if recieve data was successful or not, one of the i2c_result_t defination
*/
i2c_result_t i2c_read_nbytes(i2c_object_t* i2c,uint8_t start_register,uint8_t quantity){
	uint8_t i = 0;
	int16_t buffer_byte = 0;

	i2c->_modul->MSA  = i2c->address  | I2C_TRANSMIT;
	while( (i2c->_modul->MCS & I2C_MCS_R_BUSBSY) );
	i2c->_modul->MDR = start_register;
	i2c->_modul->MCS = I2C_MCS_W_RUN | I2C_MCS_W_START;
	while( (i2c->_modul->MCS & I2C_MCS_R_BUSY) );//&& (i2c->_modul->MCS & I2C_MCS_R_ERROR) == 0);
	if( (i2c->_modul->MCS & I2C_MCS_R_ERROR) ){
		i2c->_modul->MCS = I2C_MCS_W_STOP;
		return I2C_TRANSMIT_ERROR;
	}

	i2c->_modul->MSA = i2c->address | I2C_RECEIVE;
	while( (i2c->_modul->MCS & I2C_MCS_R_BUSY) );
	i2c->_modul->MCS = I2C_MCS_W_RUN | I2C_MCS_W_START | ( (quantity == 1)? I2C_MCS_W_STOP:I2C_MCS_W_ACK );
	while (i < quantity){
		while( (i2c->_modul->MCS & I2C_MCS_R_BUSY) );//&& (i2c->_modul->MCS & I2C_MCS_R_ERROR) == 0);
		if( (i2c->_modul->MCS & I2C_MCS_R_ERROR) ){
			if( i2c->_modul->MCS & I2C_MCS_R_ARBLST){
				i2c->_modul->MCS = I2C_MCS_W_RUN | I2C_MCS_W_STOP;
			}
			return I2C_RECIEVE_ERROR;
		}
		buffer_byte=buffer_write_byte(i2c->buffer,i2c->_modul->MDR);
		if(buffer_byte == -1){
			i2c->_modul->MCS = I2C_MCS_W_RUN | I2C_MCS_W_STOP;
			return I2C_BUFFER_FULL;
		}
		i++;
		if(i >= (quantity)){
			return I2C_NO_ERROR;
		}
		i2c->_modul->MCS = I2C_MCS_W_RUN | ( (i<(quantity-1))? I2C_MCS_W_ACK : I2C_MCS_W_STOP );
	}

	return I2C_ERROR;
}

/*!
* \details A function which set one defined bit at the slave
* @param i2c pointer of an i2c object with the required infromation
* @param data_register where the desired bit in the slave are placed
* @param bit_position which bit has to be set to 1
* @return if set bit was successful or not, one of the i2c_result_t defination
*/
i2c_result_t i2c_set_bit(i2c_object_t* i2c, uint8_t data_register, uint8_t bit_position){
	    uint8_t b;
	    i2c_read_nbytes(i2c, data_register,1);
	    b = buffer_read_byte(i2c->buffer);
	    b |= (1 << bit_position);
	    buffer_write_byte(i2c->buffer,b);
	    return i2c_write_nbytes(i2c, data_register,1);
}

/*!
* \details A function which clear one defined bit at the slave
* @param i2c pointer of an i2c object with the required infromation
* @param data_register where the desired bit in the slave are placed
* @param bit_position which bit has to be cleared to 0
* @return if clear bit was successful or not, one of the i2c_result_t defination
*/
i2c_result_t i2c_clear_bit(i2c_object_t* i2c, uint8_t data_register, uint8_t bit_position){
	    uint8_t b;
	    i2c_read_nbytes(i2c, data_register,1);
	    b = buffer_read_byte(i2c->buffer);
	    b &= ~(1 << bit_position);
	    buffer_write_byte(i2c->buffer,b);
	    return i2c_write_nbytes(i2c, data_register,1);
}

/*!
* \details A function which write a defined amount of bits to one register
* @param i2c pointer of an i2c object with the required infromation
* @param data_register where the desired bits in the slave are placed
* @param bit_start where the bits to write starts
* @param bit_length how many bits to write
* @return if write bits was successful or not, one of the i2c_result_t defination
*/
i2c_result_t i2c_write_bits(i2c_object_t* i2c, uint8_t data_register, uint8_t bit_start, uint8_t bit_length) {
    uint8_t b;
    uint8_t data;
    uint8_t mask;
    data = buffer_read_byte(i2c->buffer);
    i2c_read_nbytes(i2c, data_register,1);
    b = buffer_read_byte(i2c->buffer);
    mask = ((1 << bit_length) - 1) << (bit_start - bit_length + 1);
    data <<= (bit_start - bit_length + 1); //! shift data into correct position
    data &= mask; //! delete (0) all non-important bits in data
    b &= ~(mask); //! delete (0) all important bits in existing byte
    b |= data; //! combine data with existing byte
    buffer_write_byte(i2c->buffer,b);
    return i2c_write_nbytes(i2c, data_register,1);
}
