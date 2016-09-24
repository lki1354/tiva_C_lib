/*! \file gpio.h
 *  \brief Modul handels the differen GPIO pin modes (configurations)
 *  \author Lukas Kiechle
 *  \date 2015-10-09 creat date
 *  \copyright  All rights belong to
 *	\version 0.1
 *	\todo - include more different pin configurations
 *	      - implement "GPIO_TYPE_PWM_TIMER_OUTPUT" configurations
 */

#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_

#include <stdint.h>

/** @addtogroup GPIO_Modul
  * @{
  */

/*!
 * \brief the enum gpio_type_t defines usable pin configurations  */
typedef enum gpio_type_t{
	GPIO_TYPE_NOT_INIT,	//!< was not init until now
	GPIO_TYPE_DIGITAL_INPUT, 	/*!< Digital Input (GPIO)*/
	GPIO_TYPE_DIGITAL_INPUT_PULL_UP, 	/*!< Digital Input with pull up (GPIO)*/
	GPIO_TYPE_DIGITAL_INPUT_PULL_DOWN, 	/* !<Digital Input with pull down(GPIO)*/
	GPIO_TYPE_DIGITAL_OUTPUT,	/*!< Digital Output (GPIO) */
	GPIO_TYPE_DIGITAL_OUTPUT_OPEN_DRAIN,	/*!< Digital Output Open Drain Output (GPIO) */
	GPIO_TYPE_DIGITAL_OUTPUT_HIGH_CURRENT,	/*!< Digital Output high current (GPIO) */
	GPIO_TYPE_PWM_OUTPUT,		/*!< Digital Output (PWM) */
//	GPIO_TYPE_PWM_TIMER_OUTPUT, /* Digital Output (Timer PWM) */
	GPIO_TYPE_BUTTON_INTERRUPT, /*!< Digital Input_butto */
	GPIO_TYPE_I2C_SDA, /*!< pin as SDA line of I2C bus */
	GPIO_TYPE_I2C_SCL, /*!< pin as SCL line of I2C bus */
	GPIO_TYPE_UART, /*!< pin for a UART bus*/
	GPIO_TYPE_PINS_INIT /*!< pins initialized*/
}gpio_type_t;

/*!
 * \brief the enum gpio_pins_t defines usable pins  */
typedef enum gpio_pins_t{GPIO_PINS_INIT,
			PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,
			PB0,PB1,PB2,PB3,PB4,PB5,PB6,PB7,
			PC0,PC1,PC2,PC3,PC4,PC5,PC6,PC7,
			PD0,PD1,PD2,PD3,PD4,PD5,PD6,PD7,
			PE0,PE1,PE2,PE3,PE4,PE5,
			PF0,PF1,PF2,PF3,PF4,
			GPIO_ALL_PINS
			}gpio_pins_t;


/*!
* \brief The function sets pin configuration type*/
void gpio_set_type(gpio_pins_t pin, gpio_type_t type);
/*!
* \brief The function sets more than one pin with the same configuration type*/
void gpio_set_type_pins(gpio_pins_t* pins,uint8_t pin_quantity, gpio_type_t type);
/*!
* \brief Initialize all configured pins, enable registers, ...*/
void gpio_init();
/*!
* \brief Initialize only the chosen pin with the configuration type*/
void gpio_pin_init(gpio_pins_t pin, gpio_type_t type);
/*!
* \brief Initialize a array of pins with the same configuration type*/
void gpio_pins_init(gpio_pins_t* pins,uint8_t pin_quantity, gpio_type_t type);

/*!
* \brief function sets the ON time of the PWM in percent*/
void gpio_pwm_set_duty_cycle(gpio_pins_t pin,float value);
/*!
* \brief function returns the ON time of the PWM in percent*/
float gpio_pwm_get_duty_cycle(gpio_pins_t pin);
/*!
* \brief function sets the ON time of the PWM in percent at a array of pins*/
void gpio_pwm_set_duty_cycle_pins(gpio_pins_t* pins,uint8_t pin_quantity,float value);
/*!
* \brief Start the PWM timer*/
void gpio_pwm_start(gpio_pins_t pin);
/*!
* \brief Start PWM timer of more pins*/
void gpio_pwm_start_pins(gpio_pins_t* pins,uint8_t pin_quantity);
/*!
* \brief Stop the PWM timer*/
void gpio_pwm_stop(gpio_pins_t pin);
/*!
* \brief Stop PWM timer of more pins*/
void gpio_pwm_stop_pins(gpio_pins_t* pins,uint8_t pin_quantity);
/*!
* \brief enable pin output, high state*/
void gpio_set(gpio_pins_t pin);
/*!
* \brief disable pin output, low state*/
void gpio_clear(gpio_pins_t pin);
/*!
* \brief change pin status each time the function with the same pin is called*/
void gpio_toggel(gpio_pins_t pin);
/*!
* \brief store the call back function of a PIN interrupt*/
void gpio_set_call_back(gpio_pins_t pin, void (*call_back)(uint32_t));

/** @} */ /* End of group GPIO_Modul */

#endif /* HAL_GPIO_H_ */
