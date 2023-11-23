/**************************************************************************/
/* Filename						: USART.c                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 22, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/



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

static void (*Usart_RxInterruptHandler[NUMBER_OF_USART])( u16 Copy_u8Result);
static void (*Usart_TxCompleteInterruptHandler[NUMBER_OF_USART])( void);

/********************************** Data Type Declarations ****************************/


/********************************** Macros Declarations *******************************/

/********************************** Macros Function Declarations *********************/




/******************************* Software Interfaces Implementation *******************/

Usart_StatusErrorType Usart_enuInit(const Usart_ConfigType* Address_Usart){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;
	if(Address_Usart == NULL){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
			/* Enable Usartx Rcc Clock */
			Loc_UsartStatusError = Usart_enuEnableRccClock(Address_Usart);

			/* Set Baudrate */
			Loc_UsartStatusError = Usart_enuSetBaudrate(Address_Usart);

			/* Set Data Size */
			Usart_SetDataSize((Address_Usart->select_channel_number),(Address_Usart->select_character_size));

			/* Set Clock Phase if Sync */
			Usart_SetClockPhase((Address_Usart->select_channel_number),(Address_Usart->select_clock_phase));

			/* Set Clock Polarity if Sync */
			Usart_SetClockPolarity((Address_Usart->select_channel_number),(Address_Usart->select_clock_polarity));

			/* enable or disable DMA */
			Usart_SetDmaMode((Address_Usart->select_channel_number),(Address_Usart->select_dma_tx_enable_rx_enable));

			/* enable or disable FULL-Duplex */
			Usart_SetDuplexMode((Address_Usart->select_channel_number),(Address_Usart->select_full_duplex_half_duplex));

			/* Select OverSample mode  */
			Usart_SelectOversampleMode((Address_Usart->select_channel_number),(Address_Usart->select_oversample));


			/* Select Parity bit mode  */
			Usart_SelectParityBitMode((Address_Usart->select_channel_number),(Address_Usart->select_parity_bits));


			/* Select Stop bits  */
			Usart_SelectStopBits((Address_Usart->select_channel_number),(Address_Usart->select_stop_bits));

			/* Enable Clk if Sync  */
			Usart_SetClkInSyncMode((Address_Usart->select_channel_number),(Address_Usart->select_sync_mode));


			/* Enable Tx, Rx , UART */
			Usart_Enable(Address_Usart->select_channel_number);
			Usart_EnableTx(Address_Usart->select_channel_number);
			Usart_EnableRx(Address_Usart->select_channel_number);


	}
	return Loc_UsartStatusError;

}

Usart_StatusErrorType Usart_enuDeInit(const Usart_ConfigType* Address_Usart){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;
	if(Address_Usart == NULL){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{


		/* Disable Tx, Rx , UART */
		Usart_Disable(Address_Usart->select_channel_number);
		Usart_DisableTx(Address_Usart->select_channel_number);
		Usart_DisableRx(Address_Usart->select_channel_number);

	}

	return Loc_UsartStatusError;

}




Usart_StatusErrorType Usart_enuTransmitCharBlocking(const Usart_ConfigType* Address_Usart, u16 Copy_u16Data){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;
	if(Address_Usart == NULL){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		while( ( Usart_IsTransmitDataRegisterEmpty( Address_Usart->select_channel_number)  == ZERO_VALUE) );
		Usart_SetDataReg((Address_Usart->select_channel_number) , Copy_u16Data);
	}
	return Loc_UsartStatusError;

}
Usart_StatusErrorType Usart_enuTransmitStringBlocking(const Usart_ConfigType* Address_Usart, u8* Address_Data){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;
	u8 Loc_u8Counter = ZERO_VALUE;
	if(Address_Usart == NULL || Address_Data == NULL){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
		while(Address_Data[Loc_u8Counter] ){
		Loc_UsartStatusError = Usart_enuTransmitCharBlocking(Address_Usart,Address_Data[Loc_u8Counter++]);
		}

		Loc_UsartStatusError = Usart_enuTransmitCharBlocking(Address_Usart,Address_Data[Loc_u8Counter]);
	}
	return Loc_UsartStatusError;

}

Usart_StatusErrorType Usart_enuReceiveCharBlocking(const Usart_ConfigType* Address_Usart, u16* Address_Data){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;
	if(Address_Usart == NULL || Address_Data == NULL){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
		while( ( Usart_IsReceiveDataRegisterEmpty( Address_Usart->select_channel_number)  == ONE_VALUE) );
		*Address_Data = Usart_GetDataReg(( Address_Usart->select_channel_number));

	}
	return Loc_UsartStatusError;

}


Usart_StatusErrorType Usart_enuReceiveStringBlocking(const Usart_ConfigType* Address_Usart, u8* Address_Data){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;

	u8 Loc_u8Counter = ZERO_VALUE;
	u8 Loc_u8FlagCheck = ONE_VALUE;
	u8 Loc_u8ReceivedChar;
	if(Address_Usart == NULL || Address_Data == NULL){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		while( Loc_u8FlagCheck == ONE_VALUE){

		while( ( Usart_IsReceiveDataRegisterEmpty( Address_Usart->select_channel_number)  == ONE_VALUE)  );


		Loc_u8ReceivedChar = Usart_GetDataReg(( Address_Usart->select_channel_number));
		Address_Data[Loc_u8Counter++]= Loc_u8ReceivedChar;
		if( Loc_u8ReceivedChar == '\0' ){
			Loc_u8FlagCheck = ZERO_VALUE;
		}
		}


	}
	return Loc_UsartStatusError;

}


Usart_StatusErrorType Usart_enuSetBreakFrame(const Usart_ConfigType* Address_Usart){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;
	if(Address_Usart == NULL ){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
		Usart_SendBreakFrame((Address_Usart->select_channel_number));
	}
	return Loc_UsartStatusError;

}


/////////////////////////////// Interrupt Part ////////////////////////////////////////////

/*
 * Look At Page 1006
 */
Usart_StatusErrorType Usart_enuEnableRxInterrupt(const Usart_ConfigType* Address_Usart){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;

	if(Address_Usart == NULL ){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{


		Usart_EnableRxCompleteInterrupt(( Address_Usart->select_channel_number));
	}
	return Loc_UsartStatusError;
}

Usart_StatusErrorType Usart_enuDisableRxInterrupt(const Usart_ConfigType* Address_Usart){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;

	if(Address_Usart == NULL ){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
		Usart_DisableRxCompleteInterrupt(( Address_Usart->select_channel_number));

	}
	return Loc_UsartStatusError;
}

Usart_StatusErrorType Usart_enuSetCallbackRxFunction(const Usart_ConfigType* Address_Usart,void (*callback)(u16 Copy_u16Result)){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;

	if(Address_Usart == NULL || NULL == callback ){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
		Usart_RxInterruptHandler[( Address_Usart->select_channel_number)] =callback;
	}
	return Loc_UsartStatusError;
}



Usart_StatusErrorType Usart_enuEnableTxCompleteInterrupt(const Usart_ConfigType* Address_Usart){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;

	if(Address_Usart == NULL ){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
		Usart_EnableTxCompleteInterrupt(( Address_Usart->select_channel_number));
	}
	return Loc_UsartStatusError;
}

Usart_StatusErrorType Usart_enuDisableTxCompleteInterrupt(const Usart_ConfigType* Address_Usart){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;

	if(Address_Usart == NULL ){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		Usart_DisableTxCompleteInterrupt(( Address_Usart->select_channel_number));
	}
	return Loc_UsartStatusError;
}

Usart_StatusErrorType Usart_enuSetCallbackTxCompleteFunction(const Usart_ConfigType* Address_Usart,void (*callback)(void)){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;

	if(Address_Usart == NULL || NULL == callback ){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else{
		Usart_TxCompleteInterruptHandler[( Address_Usart->select_channel_number)] =callback;

	}
	return Loc_UsartStatusError;
}






/**************************** Private Software Interface Implementation **************/

void USART1_IRQHandler(void){

	u16 Loc_u16Result;

	if(Usart_GetRxCompleteFlag(USART_SELECT_CHANNEL_1) == ONE_VALUE && Usart_IsRxCompleteInterruptEnabled(USART_SELECT_CHANNEL_1) == ONE_VALUE ){

		Loc_u16Result = Usart_GetDataReg(USART_SELECT_CHANNEL_1);
		Usart_RxInterruptHandler[USART_SELECT_CHANNEL_1](Loc_u16Result);

		Usart_ClearRxCompleteFlag(USART_SELECT_CHANNEL_1);
	}

	if(Usart_GetTxCompleteFlag(USART_SELECT_CHANNEL_1) == ONE_VALUE && Usart_IsTxCompleteInterruptEnabled(USART_SELECT_CHANNEL_1) == ONE_VALUE ){

		Usart_TxCompleteInterruptHandler[USART_SELECT_CHANNEL_1]();
		Usart_ClearTxCompleteFlag(USART_SELECT_CHANNEL_1);
	}

}








