/**************************************************************************/
/* Filename						: RCC_config.c                             */
/* Author  	    				: Muhammad (Ali )Ammar                          */
/* Date 						: Nov 27, 2023	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/





/********************************** Includes *********************************************/
#include "../../SERVICES/BIT_UTILS.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/MAGIC_NUMBERS.h"
#include "../../SERVICES/HELPERS.h"

#include "RCC_private.h"
#include "RCC.h"
#include "RCC_config.h"

/********************************** Private declaration **********************************/



/********************************** Data Type Declarations ****************************/
Rcc_ConfigType rcc={
		.address_pll_cfg = NULL,
		.address_pll_sai_cfg = NULL,
		.adress_pll_i2s_cfg = NULL,

		.rcc_ahb_select_prescaler = RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_NO_DIV,
		.rcc_apb1_select_prescaler = RCC_APB1_SELECT_PRESCALER_AHB_NO_DIV,
		.rcc_apb2_select_prescaler = RCC_APB2_SELECT_PRESCALER_AHB_NO_DIV,

		.rcc_hse_on_or_off = RCC_ON,
		.rcc_hsi_on_or_off = RCC_ON,
		.rcc_pllSAI_on_or_off = RCC_OFF,
		.rcc_pllSAI_on_or_off = RCC_OFF,
		.rcc_pll_on_or_off = RCC_OFF,
		.rcc_sysmte_clk_soruce = RCC_SYSTEM_CLK_HSE_INDEX
};


/********************************** Macros Declarations *******************************/

/********************************** Macros Function Declarations *********************/




/******************************* Software Interfaces Implementation *******************/



/**************************** Private Software Interface Implementation **************/
