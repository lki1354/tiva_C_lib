/*! \file motion_data.h
 *  \brief Defination of motion data structure and motion data funcions
 *  \author Lukas Kiechle
 *  \date 2016-01-09 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 *
 */

#ifndef MOTION_DATA_H
#define MOTION_DATA_H

#include <stdint.h>

/** @addtogroup MOTION_DATA_Modul
  * @{
  */

/*!
 * \brief structure motion_data_t stores all motion date */
typedef struct {
	uint_fast32_t timestamp;	//!< [ms]
	int_fast32_t acc_x;	//!< acceleration x direction [\f$  \frac{mm}{s^2}\f$, 1/1000 m/s ]
	int_fast32_t acc_y;	//!< acceleration y direction [\f$  \frac{mm}{s^2}\f$, 1/1000 m/s ]
	int_fast32_t acc_z;	//!< acceleration z direction [\f$  \frac{mm}{s^2}\f$, 1/1000 m/s ]
	int_fast32_t gyro_x; //!< angular velocity x direction [1/1000 °/s]
	int_fast32_t gyro_y; //!< angular velocity y direction [1/1000 °/s]
	int_fast32_t gyro_z; //!< angular velocity z direction [1/1000 °/s]
	int_fast32_t roll; //!< roll angular [1/1000 °]
	int_fast32_t pitch; //!< pitch angular [1/1000 °]
	int_fast32_t yaw; //!< yaw angular [1/1000 °]
	//int_fast32_t magnet_x;
	//int_fast32_t magnet_y;
	//int_fast32_t magnet_z;
	int_fast32_t temperature; //!< temperature [1/100 degree] ]
}motion_data_t;

/*!
 * \brief stores calculated angles, roll, pitch and yaw into the data structure */
void motion_data_calc_angles(motion_data_t*);

/** @} */ /* End of group MOTION_DATA_Modul */

#endif /* MICROCHIPS_MOTION_DATA_H_ */
