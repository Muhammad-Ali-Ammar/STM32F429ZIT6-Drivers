/**************************************************************************/
/* Filename						: LCD_config.h                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 14, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/


#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_



/********************************** Includes *********************************************/



/********************************** Macros Declarations *******************************/
#define LCD_ROW_NUMBERS			4
#define LCD_COL_NUMBERS			20


#define LCD_4BIT_D4				GPIO_PINB0
#define LCD_4BIT_D5				GPIO_PINB1
#define LCD_4BIT_D6				GPIO_PINB2
#define LCD_4BIT_D7				GPIO_PINB4



#define LCD_4BIT_EN				GPIO_PIND0
#define LCD_4BIT_RS 			GPIO_PIND1


/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/



/********************************** Software Interfaces Declarations *******************/



#endif /* LCD_LCD_CONFIG_H_ */
