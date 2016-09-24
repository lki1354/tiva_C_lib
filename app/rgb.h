/*! \file rgb.h
 *  \brief Functions for handling RGB led
 *  \author Lukas Kiechle
 *  \date 2015-11-19 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 *
 */

#ifndef PROJECT_HAL_RGB_H_
#define PROJECT_HAL_RGB_H_

#include <stdint.h>

typedef enum{RED,GREEN,BLUE,WHITE,BLACK}rgb_color_t;

void rgb_init(void);

void rgb_brighter(uint32_t val);
void rgb_darker(uint32_t val);
void rgb_set_color(rgb_color_t color);
void toggel_rgb(uint32_t val);

#endif /* PROJECT_HAL_RGB_H_ */
