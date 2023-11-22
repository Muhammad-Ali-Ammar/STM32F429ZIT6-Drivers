/**************************************************************************/
/* Filename						: SCB.h                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 12, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/


#ifndef SCB_SCB_H_
#define SCB_SCB_H_



/********************************** Includes *********************************************/



/********************************** Macros Declarations *******************************/



/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/

typedef enum{
	SCB_STATUS_FAIL,
	SCB_STATUS_OK,
	SCB_STATUS_NULL_POINTER_ADDRESS
}SCB_ErrorStatusType;

/********************************** Software Interfaces Declarations *******************/
//SCB_ErrorStatusType Scb_enuSetGroupPrioirty(Nvic_SelectGroupPrioiriesAndSubPrioiriesType Copy_enuGroupPrioirty);


#endif /* SCB_SCB_H_ */
