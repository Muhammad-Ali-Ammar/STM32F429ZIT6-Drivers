/**************************************************************************/
/* Filename						: main.h                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 5, 2023  	           	 	      	 */
/* Version 	 					: V01                                     */
/* MicroController  			: STM32F429 								  	  */
/* Trainee At					: NTI (4 Months)						  */
/* Instructor					: Mahmoud Embabi						  */
/**************************************************************************/



#ifndef MAIN_H_
#define MAIN_H_



/********************************** Includes *********************************************/

#include "../SERVICES/MAGIC_NUMBERS.h"
#include "../SERVICES/BIT_UTILS.h"
#include "../SERVICES/HELPERS.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/calculation_functions.h"

/////// MCAL //////
#include "../MCAL/RCC/RCC.h"
#include "../MCAL/GPIO/GPIO.h"
#include "../MCAL/SYSTICK/SYSTICK.h"
#include "../MCAL/NVIC/NVIC.h"
#include "../MCAL/CAN/CAN.h"
#include "../MCAL/UART/USART.h"
#include "../MCAL/SCB/SCB.h"
#include "../MCAL/FLASH_DRIVER/FLASH_DRIVER.h"

////////// HAL ////////////////
#include "../ECUL/LCD/LCD.h"


/********************************** Macros Declarations *******************************/


/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/

extern Lcd_4bitType Lcd;


/********************************** Software Interfaces Declarations *******************/

#endif /* MAIN_H_ */
