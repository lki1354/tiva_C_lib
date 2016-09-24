/*! \file mpu9150.c
 *  \brief Implementation of i2c modul functions.
 *  \author Lukas Kiechle
 *  \date 2015-12-01 creat date
 *  \copyright  All rights belong to
 *	\todo - check if all errors are handled
 *	      - complete all functionality of the sensor chip
 *
 *  $Date:  $
 *  $Revision: 0.1$
 *  $LastChangedDate: $
 */
#include "mpu9150.h"
#include "mpu9150_defines.h"
#include "buffer.h"
#include "debug.h"

i2c_object_t mpu;
BUFFER(fifo_mpu,32);
float acc_factor = 1;
float gyro_factor= 1;

uint8_t  mpu9150_set_sample_rate(uint8_t sample_rate) {
	buffer_write_byte(mpu.buffer,sample_rate);
	return i2c_write_nbytes(&mpu, MPU9150_RA_SMPLRT_DIV, 1);
}
uint8_t  mpu9150_set_lowpas_filter(uint8_t filter) {
	buffer_write_byte(mpu.buffer,filter);
	return i2c_write_bits(&mpu, MPU9150_RA_CONFIG, MPU9150_CFG_DLPF_CFG_BIT, MPU9150_CFG_DLPF_CFG_LENGTH);
}
uint8_t  mpu9150_set_clock_source(uint8_t source) {
	buffer_write_byte(mpu.buffer,source);
	 return i2c_write_bits(&mpu, MPU9150_RA_PWR_MGMT_1, MPU9150_PWR1_CLKSEL_BIT, MPU9150_PWR1_CLKSEL_LENGTH);
}
uint8_t mpu9150_set_gyro_scale_range(gyro_scale_range_t range) {
	gyro_factor = (1<<range)/0.131;	/*!  calculate factor of gyro values:  <br> Formula: \f$ gyro\_factor = \frac{2^{range}}{ 131} \cdot 1000\f$ <br>
	|math | code | description|
	|:-----:|:------:|:------------|
	|\f$ 2^{range} \f$ |  (1<<range)  | for calculate right scaleing factor |
	|\f$ \frac{1000}{131 LSB} \frac{deg}{ s }\f$| \f$ \frac{1}{0.131} \f$ |value of the lowest scale range and multiplied with 1000 to use it with int and 3 comma [deg = °] |
	*/
	buffer_write_byte(mpu.buffer,range);
	return i2c_write_bits(&mpu, MPU9150_RA_GYRO_CONFIG, MPU9150_GCONFIG_FS_SEL_BIT, MPU9150_GCONFIG_FS_SEL_LENGTH);
}
uint8_t mpu9150_set_acc_scale_range(acc_scale_range_t range) {
	acc_factor = (1<<range)/16.384*9.81; /*!  calculate factor of acc values: <br> Formula: \f$ acc\_factor = \frac{2^{range}}{16.384} \cdot 9.81 \f$ <br>
	|math | code | description|
	|:-----:|:------:|:------------|
	| \f$ 2^{range}\f$ | (1<<range)   | for calculate right scaleing factor |
	|\f$ \frac{1000}{16384} \frac{g}{LSB} \f$ | \f$ \frac{1}{16.384} \f$ | value of the lowest scale range and multiplied with 1000 for use comma in integer|
	|\f$ 9.81 \frac{m}{s^2} \f$ | 9.81  | constant of gravitation, this constant replace g |
	*/
	buffer_write_byte(mpu.buffer,range);
	return i2c_write_bits(&mpu, MPU9150_RA_ACCEL_CONFIG, MPU9150_ACONFIG_AFS_SEL_BIT, MPU9150_ACONFIG_AFS_SEL_LENGTH);
}
uint8_t mpu9150_set_sleep() {
	return i2c_set_bit(&mpu, MPU9150_RA_PWR_MGMT_1, MPU9150_PWR1_SLEEP_BIT);
}
uint8_t mpu9150_clear_sleep() {
	return i2c_clear_bit(&mpu, MPU9150_RA_PWR_MGMT_1, MPU9150_PWR1_SLEEP_BIT);
}
uint8_t mpu9150_clear_cycle() {
	return i2c_clear_bit(&mpu, MPU9150_RA_PWR_MGMT_1, MPU9150_PWR1_CYCLE_BIT);
}
uint8_t mpu9150_clear_standby() {
	buffer_write_byte(mpu.buffer,0);
	return i2c_write_nbytes(&mpu, MPU9150_RA_PWR_MGMT_2,1);
}
uint8_t mpu9150_set_temp_sensor_enable() {
    // 1 is actually disabled here
    return i2c_clear_bit(&mpu, MPU9150_RA_PWR_MGMT_1, MPU9150_PWR1_TEMP_DIS_BIT);
}

int_fast32_t mpu9150_get_x_acc(){
	int16_t value;
	i2c_read_nbytes(&mpu,MPU9150_RA_ACCEL_XOUT_H,2);

	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	return (int_fast32_t)(value*acc_factor);
}
int_fast32_t mpu9150_get_y_acc(){
	int16_t value;
	i2c_read_nbytes(&mpu,MPU9150_RA_ACCEL_YOUT_H,2);

	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	return (int_fast32_t)(value*acc_factor);
}
int_fast32_t mpu9150_get_z_acc(){
	int16_t value;

	i2c_read_nbytes(&mpu,MPU9150_RA_ACCEL_ZOUT_H,2);

	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	return (int_fast32_t)(value*acc_factor);
}

int_fast32_t mpu9150_get_x_gyro(){
	int16_t value;

	i2c_read_nbytes(&mpu,MPU9150_RA_GYRO_XOUT_H,2);

	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	return (int_fast32_t)(value * gyro_factor);
}
int_fast32_t mpu9150_get_y_gyro(){
	int16_t value;

	i2c_read_nbytes(&mpu,MPU9150_RA_GYRO_YOUT_H,2);

	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	return (int_fast32_t)(value * gyro_factor);
}
int_fast32_t mpu9150_get_z_gyro(){
	int16_t value;

	i2c_read_nbytes(&mpu,MPU9150_RA_GYRO_ZOUT_H,2);

	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	return (int_fast32_t)(value * gyro_factor);
}

int_fast32_t mpu9150_get_temp(){
	int16_t value;
	i2c_read_nbytes(&mpu,MPU9150_RA_TEMP_OUT_H,2);
	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	return (int_fast32_t)(value/3.4) + 3653;
}

/*!
 * \details Read a lot of date form the sensor and calculate the right value for all axces
 * \todo check if buffer emtpy
 */
uint8_t mpu9150_read_data(motion_data_t* sensor_data,hal_timer_t* timer){
	int16_t value;
	i2c_read_nbytes(&mpu,MPU9150_RA_ACCEL_XOUT_H,14);
	sensor_data->timestamp=hal_timer_get_millisec_32bit(timer);

	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	sensor_data->acc_x = (int_fast32_t)(value*acc_factor);
	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	sensor_data->acc_y = (int_fast32_t)(value*acc_factor);
	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	sensor_data->acc_z = (int_fast32_t)(value*acc_factor);

	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	sensor_data->temperature = (int_fast32_t)(value/0.34) + 36530;


	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	sensor_data->gyro_x = (int_fast32_t)(value*gyro_factor);
	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	sensor_data->gyro_y = (int_fast32_t)(value*gyro_factor);
	value = (buffer_read_byte(mpu.buffer)<< 8);
	value |= buffer_read_byte(mpu.buffer);
	sensor_data->gyro_z = (int_fast32_t)(value*gyro_factor);
	return 0;
}


/*! \brief Initialize i2c modul and all importend registers of the sensor
\doto check if mpu9150 is reachable otherwise reset i2c device and do self test at all axes */
uint8_t mpu9150_initialize(i2c_modules_t i2c_modul,acc_scale_range_t acc_scale,gyro_scale_range_t gyro_scale) {
	uint8_t result =0;
	i2c_master_init(&mpu,i2c_modul,MPU9150_DEFAULT_ADDRESS,&fifo_mpu);
	result |= mpu9150_set_sample_rate(0);
	result |= mpu9150_set_lowpas_filter(MPU9150_DLPF_BW_98);
	result |= mpu9150_set_clock_source(MPU9150_CLOCK_PLL_XGYRO);
	result |= mpu9150_clear_cycle();
	result |= mpu9150_clear_standby();
	result |= mpu9150_set_gyro_scale_range(gyro_scale);
	result |= mpu9150_set_acc_scale_range(acc_scale);
	result |= mpu9150_clear_sleep();
	result |= mpu9150_set_temp_sensor_enable();
	return result;
}
