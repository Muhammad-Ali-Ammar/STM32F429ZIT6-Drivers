/**************************************************************************/
/* Filename						: SCB.c                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 12, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/





/********************************** Includes *********************************************/

#include "../../SERVICES/BIT_UTILS.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/MAGIC_NUMBERS.h"
#include "../../SERVICES/HELPERS.h"

#include "SCB.h"
#include "SCB_private.h"

/**********************************  declaration **********************************/

/* it's used for NVIC Driver */
Scb_SelectGroupPriorityAndSubPriorityType Global_GroupPrioritySelection;

/********************************** Data Type Declarations ****************************/


/********************************** Macros Declarations *******************************/

/********************************** Macros Function Declarations *********************/




/******************************* Software Interfaces Implementation *******************/
SCB_ErrorStatusType Scb_enuSetGroupPrioirty(Scb_SelectGroupPriorityAndSubPriorityType Copy_enuSelectGroupPriority){

	SCB_ErrorStatusType Loc_enuScbErrorStatus = SCB_STATUS_OK;

	Scb_SetGroupPrioirty(Copy_enuSelectGroupPriority);

	/* it's used for NVIC Driver */
	Global_GroupPrioritySelection =Copy_enuSelectGroupPriority;
	return Loc_enuScbErrorStatus;
}


/**************************** Private Software Interface Implementation **************/

