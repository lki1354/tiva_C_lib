/*! \file motor_controller.c
 *  \brief implemenataion of controller for motor
 *  \author Lukas Kiechle
 *  \date 2016-01-09 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 *
 */
#include "motor_controller.h"

void motor_controller_process(drive_t* drive,motion_data_t* data){
	uint16_t new_speed;

	motion_data_calc_angles(data);

	//new_speed = (uint16_t)(4400 + data->acc_y*0.45); //old process unit

	new_speed = (uint16_t)(5000+ data->roll/20.0);//! process unit with angle input and percent output

	drive_set_speed(drive,DRIVE_MOTOR_BACK_LEFT,new_speed);
	drive_set_speed(drive,DRIVE_MOTOR_BACK_RIGHT,new_speed);

	drive_set_speed(drive,DRIVE_MOTOR_FRONT_LEFT,9900-new_speed);
	drive_set_speed(drive,DRIVE_MOTOR_FRONT_RIGHT,9900-new_speed);
}
