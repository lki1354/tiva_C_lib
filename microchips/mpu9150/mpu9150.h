/*! \file mpu9150.h
 *  \brief Functions for handling of the communication with the 9 axes sensore mpu9150
 *  \author Lukas Kiechle
 *  \date 2015-12-01 creat date
 *  \copyright  All rights belong to
 *  \version 0.1
 *  \todo - add all functionality and do self test of the sensor at initialization
 *
 */

#ifndef MPU9150_H
#define MPU9150_H

#include <stdint.h>

#include "motion_data.h"
#include "hal_timer.h"
#include "i2c.h"


/** @addtogroup MPU9150_Modul
  * @{
  */

/*!
 * \brief the enum acc_scale_range_t defines the possible scale range of the sensor for acceleration measurement  */
typedef enum {ACC_SCALE_2g=0,ACC_SCALE_4g,ACC_SCALE_8g,ACC_SCALE_16g}acc_scale_range_t;
/*!
 * \brief the enum gyro_scale_range_t defines the possible scale range of the sensor for angular velocity (Wikelgeschwindigkeit) measurement */
typedef enum {GYRO_SCALE_250=0,GYRO_SCALE_500,GYRO_SCALE_1000,GYRO_SCALE_2000}gyro_scale_range_t;

/*!
* \brief The function initialize the i2c interface and the sensore*/
uint8_t mpu9150_initialize(i2c_modules_t,acc_scale_range_t,gyro_scale_range_t);

/*!
* \brief The function reads temperature of the IC and also acceleration and angular velocity of all three axes (x,y,z) with a timestamp */
uint8_t mpu9150_read_data(motion_data_t*,hal_timer_t* timer);
/*!
* \brief The function reads only the acceleration of the x axes*/
int_fast32_t mpu9150_get_x_acc();
/*!
* \brief The function reads only the acceleration of the y axes*/
int_fast32_t mpu9150_get_y_acc();
/*!
* \brief The function reads only the acceleration of the z axes*/
int_fast32_t mpu9150_get_z_acc();
/*!
* \brief The function reads only the angular velocity of the x axes*/
int_fast32_t mpu9150_get_x_gyro();
/*!
* \brief The function reads only the angular velocity of the y axes*/
int_fast32_t mpu9150_get_y_gyro();
/*!
* \brief The function reads only the angular velocity of the z axes*/
int_fast32_t mpu9150_get_z_gyro();
/*!
* \brief The function reads only the temperature inside the chip*/
int_fast32_t mpu9150_get_temp();

/** @} */ /* End of group MPU9150_Modul */

#endif
