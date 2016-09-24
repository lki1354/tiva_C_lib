/*! \file motor_controller.h
 *  \brief modul for control motor with sensor data
 *  \author Lukas Kiechle
 *  \date 2016-01-09 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 *
 */

#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "drive.h"
#include "motion_data.h"


/*!
 * \brief function for the controller process whiche steer the motors */
void motor_controller_process(drive_t* ,motion_data_t* );

#endif /* APP_CONTROLLER_MOTOR_CONTROLLER_H_ */
