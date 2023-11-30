/**************************************************************************/
/* Filename						: USART_config.c                                 */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 22, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/********************************************************************************/



/********************************** Includes *********************************************/

#include "../../SERVICES/BIT_UTILS.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/MAGIC_NUMBERS.h"
#include "../../SERVICES/HELPERS.h"

#include "../../MCAL/RCC/RCC.h"

#include "USART.h"
#include "USART_config.h"
#include "USART_private.h"
/********************************** Private declaration **********************************/



/********************************** Data Type Declarations ****************************/


/********************************** Macros Declarations *******************************/

/********************************** Macros Function Declarations *********************/

Usart_ConfigType Usart1 ={
		.baude_rate = 115200,
		.select_channel_number = USART_SELECT_CHANNEL_1,
		.select_character_size = USART_SELECT_CHARACTER_SIZE_8_BIT,
		.select_clock_phase = USART_SELECT_CLOCK_PHASE_DONT_CARE_ASYNC_MODE,
		.select_clock_polarity = USART_SELECT_CLOCK_POLARITY_DONT_CARE_ASYNC_MODE,
		.select_dma_tx_enable_rx_enable = USART_SELECT_DMA_TX_DISABLE_DMA_RX_DISABLE,
		.select_full_duplex_half_duplex = USART_SELECT_FULL_DUPLEX,
		.select_oversample = USART_SELECT_OVERSAMPLE_BY_16_THREE_SAMPLE_METHOD,
		.select_parity_bits = USART_SELECT_PARITY_DISABLE,
		.select_stop_bits = USART_SELECT_STOP_1_BIT,
		.select_sync_mode = USART_SELECT_ASYNCHRONOUS_MODE
};



/******************************* Software Interfaces Implementation *******************/



/**************************** Private Software Interface Implementation **************/

