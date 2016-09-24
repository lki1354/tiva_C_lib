/*! \file motion_data.c
 *  \brief Handels the data management
 *  \author Lukas Kiechle
 *  \date 2016-01-18 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 *
 */
#include <math.h>
#include "motion_data.h"

/*!
 * \brief define PI because it isn't defined in math.h */
#define M_PI   3.14159265358979323846	/* pi */

/*!
 * \details calculates the rotation angles for x, y and z
 * \param pointer of actual data storage
 *  */
void motion_data_calc_angles(motion_data_t* data){
	float acc_x,acc_y,acc_z;

	acc_x = data->acc_x/1000.0f;
	acc_y = data->acc_y/1000.0f;
	acc_z = data->acc_z/1000.0f;

	data->roll = (int_fast32_t) ( (atan2(acc_y, sqrt(acc_x*acc_x + acc_z*acc_z))*180.0)*1000.0/M_PI );
	/*! calculate roll angle [degree]: \f$ roll = \arctan\left( \frac{acc_y}{\sqrt[2]{acc_x^2 + acc_z^2} }\right) \cdot \frac{180}{\pi} \cdot 1000  \f$
	 * */
	data->pitch = (int_fast32_t) ( (atan2(acc_x, sqrt(acc_y*acc_y + acc_z*acc_z))*180.0)*1000.0/M_PI );
	/*! calculate pitch angle [degree]: \f$ pitch = \arctan\left( \frac{acc_x}{\sqrt[2]{acc_y^2 + acc_z^2} }\right) \cdot \frac{180}{\pi} \cdot 1000  \f$
	 * */
	data->yaw = (int_fast32_t)  ( (atan2(sqrt(acc_y*acc_y + acc_x*acc_x),acc_z)*180.0)*1000.0/M_PI );
	/*! calculate yaw angle [degree]: \f$ yaw = \arctan\left( \frac{\sqrt[2]{acc_y^2 + acc_x^2} }{acc_z}\right) \cdot \frac{180}{\pi} \cdot 1000  \f$
	 * */
}

