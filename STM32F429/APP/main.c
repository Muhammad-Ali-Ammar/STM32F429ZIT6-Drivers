/**************************************************************************/
/* Filename						: main.c                                    */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 5, 2023  	           	 	      	 */
/* Version 	 					: V01                                     */
/* MicroController  			: STM32F429 							 */
/**************************************************************************/


/* Systick Using Busy wait */

//#include "main.h"
//
//int main(void)
//{
//	*((volatile u32*)(0x40023830))=0xFFFFFFF;
//	Gpio_enuInit();
//	Systick_enuInit();
//
//
//
//
//	for(;;){
//
//		Gpio_enuSetPinChannelAtomic(GPIO_PING13);
//		Systick_enuSetBusyWait(2000000);
//
//
//		Gpio_enuClearPinChannelAtomic(GPIO_PING13);
//		Systick_enuSetBusyWait(2000000);
//
//
//
//	}
//}


////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////// CAN Example ///////////////////////////////////////////////////////////

//#include "main.h"
//
//
//Rcc_ConfigType rcc={
//		.address_pll_cfg = NULL,
//		.address_pll_sai_cfg = NULL,
//		.adress_pll_i2s_cfg = NULL,
//
//		.rcc_ahb_select_prescaler = RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_NO_DIV,
//		.rcc_apb1_select_prescaler = RCC_APB1_SELECT_PRESCALER_AHB_NO_DIV,
//		.rcc_apb2_select_prescaler = RCC_APB2_SELECT_PRESCALER_AHB_NO_DIV,
//
//		.rcc_hse_on_or_off = RCC_ON,
//		.rcc_hsi_on_or_off = RCC_ON,
//		.rcc_pllSAI_on_or_off = RCC_OFF,
//		.rcc_pllSAI_on_or_off = RCC_OFF,
//		.rcc_pll_on_or_off = RCC_OFF,
//		.rcc_sysmte_clk_soruce = RCC_SYSTEM_CLK_HSE_INDEX
//};
//
//Can_ConfigType can1 ={
//		.can_select_back_from_bus_off_state_automatic = CAN_SELECT_BACK_FROM_BUS_OFF_STATE_AUTOMATIC,
//		.can_select_during_debug_mode_can_working = CAN_SELECT_DURING_DEBUG_MODE_CAN_WORKING,
//		.can_select_node_mode = CAN_SELECT_NODE_MODE_LOOPBACK,
//		.can_select_retransmission_automatic = CAN_SELECT_RETRANSMISSION_AUTOMATIC,
//		.can_select_rx_lock_mode = CAN_SELECT_RX_FIFO_NOT_LOCKED_ON_OVERRUN,
//		.can_select_time_trigger_communcation_mode = CAN_SELECT_TIME_TRIGGER_COMMUNICATION_MODE_DISABLED,
//		.can_select_tx_fifo_priority = CAN_SELECT_TX_FIFO_BY_THE_REQUEST_ORDER,
//		.can_select_wakeup_automatic = CAN_SELECT_WAKEUP_NOT_AUTOMATIC_DURING_SLEEP,
//		.can_bit_time_calculation = 0x001c0003  // http://www.bittiming.can-wiki.info/
//};
//
//Can_MessageType message1={
//		.can_DLC_FROM_0_TO_8 = FIVE_VALUE,
//		.can_extended_id_remaining_18_bit = ZERO_VALUE,
//		.can_select_ide_mode = CAN_SELECT_IDE_STANDARD,
//		.can_select_rtr_mode = CAN_SELECT_RTR_DATA_FRAME,
//		.can_standard_id_11_bit = 0x100
//};
//
//Can_MessageType message2;
//
//int main(void)
//{
//	/********************************** It must *************************************/
//
//	/* RCC PART */
// 	Rcc_enuInit(&rcc);
//	Gpio_enuEnableClockAllGPIOs();
//	Rcc_enuInitMCO2(RCC_MCO2_PIN_SELECT_HSE_CLK,RCC_MCO2_PIN_SELECT_PRESCALER_NO_DIV);
//
//	/* Systic Part */
//	Systick_enuInit();
//
//
//	Gpio_enuInit();
//
//	Gpio_enuSetAF(GPIO_PINA11, GPIO_SELET_AF9_CAN1_CAN2_LTDC_TIM12_TIM13_TIM14); // for can
//	Gpio_enuSetAF(GPIO_PINA12, GPIO_SELET_AF9_CAN1_CAN2_LTDC_TIM12_TIM13_TIM14); // for can
//	Gpio_enuSetAF(GPIO_PIND1, GPIO_SELET_AF9_CAN1_CAN2_LTDC_TIM12_TIM13_TIM14); // for can
//
//	Can_enuInit(&can1);
//
//
//	u8 arr1[8]={1};
//
//	u8 arr3[8];
//
//
//	//Lcd_4bit_enuInit(&Lcd);
/////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//	for(;;){
//
//
//
//		Can_enuTransmitMessage_MustSend(&message1, arr1);
//
//		Can_enuReceiveMessageFifox_MustReceive(CAN_RX_FIFO_MAIL_BOX_INDEX_0, &message2, arr3, NULL);
//		if(arr3[0]==0){
//
//			Gpio_enuClearPinChannelAtomic(GPIO_PING13);
//
//		}
//
//		else if( arr3[0]==1){
//			Gpio_enuSetPinChannelAtomic(GPIO_PING13);
//		}
//
//
//		arr1[0] = !arr1[0];
//
//			Systick_enuSetBusyWaitTicks(1000000);
//
//
//
//
//	}
//}

///////////////////////////////////////////// UART Blocking ///////////////////////////////////////////////////////////////////////////////
//
//#include "main.h"
//
//
//Rcc_ConfigType rcc={
//		.address_pll_cfg = NULL,
//		.address_pll_sai_cfg = NULL,
//		.adress_pll_i2s_cfg = NULL,
//
//		.rcc_ahb_select_prescaler = RCC_AHB_SELECT_PRESCALER_SYSTEM_CLK_NO_DIV,
//		.rcc_apb1_select_prescaler = RCC_APB1_SELECT_PRESCALER_AHB_NO_DIV,
//		.rcc_apb2_select_prescaler = RCC_APB2_SELECT_PRESCALER_AHB_NO_DIV,
//
//		.rcc_hse_on_or_off = RCC_ON,
//		.rcc_hsi_on_or_off = RCC_ON,
//		.rcc_pllSAI_on_or_off = RCC_OFF,
//		.rcc_pllSAI_on_or_off = RCC_OFF,
//		.rcc_pll_on_or_off = RCC_OFF,
//		.rcc_sysmte_clk_soruce = RCC_SYSTEM_CLK_HSE_INDEX
//};
//
//Can_ConfigType can1 ={
//		.can_select_back_from_bus_off_state_automatic = CAN_SELECT_BACK_FROM_BUS_OFF_STATE_AUTOMATIC,
//		.can_select_during_debug_mode_can_working = CAN_SELECT_DURING_DEBUG_MODE_CAN_WORKING,
//		.can_select_node_mode = CAN_SELECT_NODE_MODE_LOOPBACK,
//		.can_select_retransmission_automatic = CAN_SELECT_RETRANSMISSION_AUTOMATIC,
//		.can_select_rx_lock_mode = CAN_SELECT_RX_FIFO_NOT_LOCKED_ON_OVERRUN,
//		.can_select_time_trigger_communcation_mode = CAN_SELECT_TIME_TRIGGER_COMMUNICATION_MODE_DISABLED,
//		.can_select_tx_fifo_priority = CAN_SELECT_TX_FIFO_BY_THE_REQUEST_ORDER,
//		.can_select_wakeup_automatic = CAN_SELECT_WAKEUP_NOT_AUTOMATIC_DURING_SLEEP,
//		.can_bit_time_calculation = 0x001c0003  // http://www.bittiming.can-wiki.info/
//};
//
//Can_MessageType message1={
//		.can_DLC_FROM_0_TO_8 = FIVE_VALUE,
//		.can_extended_id_remaining_18_bit = ZERO_VALUE,
//		.can_select_ide_mode = CAN_SELECT_IDE_STANDARD,
//		.can_select_rtr_mode = CAN_SELECT_RTR_DATA_FRAME,
//		.can_standard_id_11_bit = 0x100
//};
//
//Can_MessageType message2;
//
//
//
//Usart_ConfigType Usart1 ={
//		.baude_rate = 115200,
//		.select_channel_number = USART_SELECT_CHANNEL_1,
//		.select_character_size = USART_SELECT_CHARACTER_SIZE_8_BIT,
//		.select_clock_phase = USART_SELECT_CLOCK_PHASE_DONT_CARE_ASYNC_MODE,
//		.select_clock_polarity = USART_SELECT_CLOCK_POLARITY_DONT_CARE_ASYNC_MODE,
//		.select_dma_tx_enable_rx_enable = USART_SELECT_DMA_TX_DISABLE_DMA_RX_DISABLE,
//		.select_full_duplex_half_duplex = USART_SELECT_FULL_DUPLEX,
//		.select_oversample = USART_SELECT_OVERSAMPLE_BY_16_THREE_SAMPLE_METHOD,
//		.select_parity_bits = USART_SELECT_PARITY_DISABLE,
//		.select_stop_bits = USART_SELECT_STOP_1_BIT,
//		.select_sync_mode = USART_SELECT_ASYNCHRONOUS_MODE
//};
//
//
//int main(void)
//{
//	/********************************** It must *************************************/
//
//	/* RCC PART */
// 	Rcc_enuInit(&rcc);
//	Gpio_enuEnableClockAllGPIOs();
//	Rcc_enuInitMCO2(RCC_MCO2_PIN_SELECT_HSE_CLK,RCC_MCO2_PIN_SELECT_PRESCALER_NO_DIV);
//
//	/* Systic Part */
//	Systick_enuInit();
//
//
//	Gpio_enuInit();
//
//	/* CAN PART */
//	Gpio_enuSetAF(GPIO_PINA11, GPIO_SELECT_AF9_CAN1_CAN2_LTDC_TIM12_TIM13_TIM14); // for can
//	Gpio_enuSetAF(GPIO_PINA12, GPIO_SELECT_AF9_CAN1_CAN2_LTDC_TIM12_TIM13_TIM14); // for can
//	Can_enuInit(&can1);
//
//
//	/* UART part */
//
//	Gpio_enuSetAF(GPIO_PINB6, GPIO_SELECT_AF7_USART1_USART2_USART3); // for Usart Tx1
//	Gpio_enuSetAF(GPIO_PINB7, GPIO_SELECT_AF7_USART1_USART2_USART3); // for Usart Rx1
//	Usart_enuInit(&Usart1);
//
//
//
//
//
//
//
//	//Lcd_4bit_enuInit(&Lcd);
//
//
/////////////////////////////////////////////////////////////////////////////////////////
//
////	u8 arr1[8]={6,5};
////
////	u8 arr3[8];
////
////	Can_enuTransmitMessage_MustSend(&message1, arr1);
////
////	Can_enuReceiveMessageFifox_CheckOneTime(CAN_RX_FIFO_MAIL_BOX_INDEX_0, &message2, arr3, NULL);
////	if(arr3[0]==5){
////
////		Gpio_enuClearPinChannelAtomic(GPIO_PING13);
////
////	}
////
////	else if( arr3[0]==6){
////		Gpio_enuSetPinChannelAtomic(GPIO_PING13);
////		Systick_enuSetBusyWaitTicks(1000000);
////	}
////
//
//	u8 UsartDataArr[]="Ammar";
//	u8 Loc_u8Recevied[10];
//	Std_True_or_FalseType Loc_Check;
//
//	for(;;){
//
//
////		Usart_enuReceiveCharBlocking(&Usart1, &Loc_u8Recevied);
////		if(Loc_u8Recevied=='1'){
////			Gpio_enuSetPinChannelAtomic(GPIO_PING13);
////			Systick_enuSetBusyWaitTicks(1000000);
////		}
////		else if(Loc_u8Recevied=='0'){
////			Gpio_enuClearPinChannelAtomic(GPIO_PING13);
////			Systick_enuSetBusyWaitTicks(1000000);
////		}
//
//
//		Usart_enuReceiveStringBlocking(&Usart1, Loc_u8Recevied);
//		CompareTwoStrings(UsartDataArr, Loc_u8Recevied, &Loc_Check);
//
//		if(Loc_Check == STD_TRUE){
//			Gpio_enuFlipChannel(GPIO_PING13);
//		}
//		else{
//			Gpio_enuClearPinChannelAtomic(GPIO_PING13);
//		}
//	}
//}



///////////////////////////////////////////////////////////////////////////////////////////////////


#include "main.h"


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


void Usart_Isr(u16 Copy_u16Result){

	if(Copy_u16Result == '1'){
		Gpio_enuFlipChannel(GPIO_PING13);
	}
	else if(Copy_u16Result == '0'){
		Gpio_enuClearPinChannelAtomic(GPIO_PING13);
	}
}

int main(void)
{
	/********************************** It must *************************************/

	/* RCC PART */
 	Rcc_enuInit(&rcc);
	Gpio_enuEnableClockAllGPIOs();
	Rcc_enuInitMCO2(RCC_MCO2_PIN_SELECT_HSE_CLK,RCC_MCO2_PIN_SELECT_PRESCALER_NO_DIV);


	/* Systic Part */
	Systick_enuInit();

	/* Interrupt Part */
	Scb_enuSetGroupPrioirty(SCB_SELECT_GROUP_PRIORITY_ZERO_AND_SUB_PRIORITY_16);



	Gpio_enuInit();

//	/* CAN PART */
//	Gpio_enuSetAF(GPIO_PINA11, GPIO_SELECT_AF9_CAN1_CAN2_LTDC_TIM12_TIM13_TIM14); // for can
//	Gpio_enuSetAF(GPIO_PINA12, GPIO_SELECT_AF9_CAN1_CAN2_LTDC_TIM12_TIM13_TIM14); // for can
//	Can_enuInit(&can1);
//



	/* UART part */

	Nvic_SetInterruptPriority(NVIC_USART1, NVIC_Select_Group_0, NVIC_Select_Sub_0);
	Gpio_enuSetAF(GPIO_PINB6, GPIO_SELECT_AF7_USART1_USART2_USART3); // for Usart Tx1
	Gpio_enuSetAF(GPIO_PINB7, GPIO_SELECT_AF7_USART1_USART2_USART3); // for Usart Rx1


	Usart_enuSetCallbackRxFunction(&Usart1, Usart_Isr);
	Usart_enuInit(&Usart1);
	Usart_enuEnableRxInterrupt(&Usart1);

	Nvic_enuEnableInterrupt(NVIC_USART1);







	//Lcd_4bit_enuInit(&Lcd);


///////////////////////////////////////////////////////////////////////////////////////


	for(;;){



	}
}
