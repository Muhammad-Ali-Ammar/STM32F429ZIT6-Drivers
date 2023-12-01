/**************************************************************************/
/* Filename						: CAN_config.c                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 15, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/





/********************************** Includes *********************************************/
#include "../../SERVICES/BIT_UTILS.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/MAGIC_NUMBERS.h"
#include "../../SERVICES/HELPERS.h"

#include "../../MCAL/RCC/RCC.h"

#include "CAN.h"
#include "CAN_config.h"
#include "CAN_private.h"

/********************************** Private declaration **********************************/



/********************************** Data Type Declarations ****************************/


/********************************** Macros Declarations *******************************/

/********************************** Macros Function Declarations *********************/

Can_ConfigType can1 ={
		.can_select_back_from_bus_off_state_automatic = CAN_SELECT_BACK_FROM_BUS_OFF_STATE_AUTOMATIC,
		.can_select_during_debug_mode_can_working = CAN_SELECT_DURING_DEBUG_MODE_CAN_WORKING,
		.can_select_node_mode = CAN_SELECT_NODE_MODE_LOOPBACK,
		.can_select_retransmission_automatic = CAN_SELECT_RETRANSMISSION_AUTOMATIC,
		.can_select_rx_lock_mode = CAN_SELECT_RX_FIFO_NOT_LOCKED_ON_OVERRUN,
		.can_select_time_trigger_communcation_mode = CAN_SELECT_TIME_TRIGGER_COMMUNICATION_MODE_DISABLED,
		.can_select_tx_fifo_priority = CAN_SELECT_TX_FIFO_BY_THE_REQUEST_ORDER,
		.can_select_wakeup_automatic = CAN_SELECT_WAKEUP_NOT_AUTOMATIC_DURING_SLEEP,
		.can_bit_time_calculation = 0x001c0003  // http://www.bittiming.can-wiki.info/
};



/******************************* Software Interfaces Implementation *******************/



/**************************** Private Software Interface Implementation **************/

