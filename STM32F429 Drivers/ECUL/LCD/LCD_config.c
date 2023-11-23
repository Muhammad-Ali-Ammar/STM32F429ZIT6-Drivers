/**************************************************************************/
/* Filename						: LCD_config.c                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 14, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/





/********************************** Includes *********************************************/
#include "../../SERVICES/BIT_UTILS.h"
#include "../../SERVICES/HELPERS.h"
#include "../../SERVICES/MAGIC_NUMBERS.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/calculation_functions.h"

#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/SYSTICK/SYSTICK.h"

#include "LCD_config.h"
#include "LCD.h"
/********************************** Private declaration **********************************/



/********************************** Data Type Declarations ****************************/
Lcd_4bitType Lcd ={
		.lcd_data_pins[0] = LCD_4BIT_D4,
		.lcd_data_pins[1] = LCD_4BIT_D5,
		.lcd_data_pins[2] = LCD_4BIT_D6,
		.lcd_data_pins[3] = LCD_4BIT_D7,

		.lcd_enable_pin = LCD_4BIT_EN,
		.lcd_rs_pin = LCD_4BIT_RS
};


/********************************** Macros Declarations *******************************/

/********************************** Macros Function Declarations *********************/




/******************************* Software Interfaces Implementation *******************/



/**************************** Private Software Interface Implementation **************/

