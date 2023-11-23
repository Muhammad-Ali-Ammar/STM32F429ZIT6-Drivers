/**************************************************************************/
/* Filename						: USART_private.h                                 */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 22, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/


#ifndef UART_USART_PRIVATE_H_
#define UART_USART_PRIVATE_H_



/********************************** Includes *********************************************/

/********************************** Private Function Declartion *********************************************/

static Usart_StatusErrorType Usart_enuSetBaudrate(const Usart_ConfigType* Address_Usart);
static Usart_StatusErrorType Usart_enuEnableRccClock(const Usart_ConfigType* Address_Usart);


/********************************** Macros Declarations *******************************/



/********************************** Macros Function Declarations *********************/


#define Usart_SetBaudrateIntPart(_CHANNEL_,_VALUE_)                     ((uartArr[(_CHANNEL_)]->USART_BRR ) = ((uartArr[(_CHANNEL_)]->USART_BRR ) & 0xFFFF000F) | (((_VALUE_)<< FOUR_VALUE ) & 0xFFF0))
#define Usart_SetBaudrateFractionPart(_CHANNEL_,_VALUE_)                     ((uartArr[(_CHANNEL_)]->USART_BRR ) = ((uartArr[(_CHANNEL_)]->USART_BRR ) & 0xFFFFFFF0) | (((_VALUE_)<< ZERO_VALUE ) & 0xF))
#define Usart_SetDataSize(_CHANNEL_,_VALUE_)                 				 WRITE_BIT((uartArr[(_CHANNEL_)]->USART_CR1),TWELVE_VALUE, (_VALUE_) )
#define Usart_SetClockPhase(_CHANNEL_,_VALUE_)                 				   WRITE_BIT((uartArr[(_CHANNEL_)]->USART_CR2),NINE_VALUE, (_VALUE_) )
#define Usart_SetClockPolarity(_CHANNEL_,_VALUE_)                 		   WRITE_BIT((uartArr[(_CHANNEL_)]->USART_CR2),TEN_VALUE, (_VALUE_) )
#define Usart_SetDmaMode(_CHANNEL_,_VALUE_)              			       ((uartArr[(_CHANNEL_)]->USART_CR3 ) = ((uartArr[(_CHANNEL_)]->USART_CR3 ) & 0xFFFFFF3F) | (((_VALUE_)<< SIX_VALUE ) & 0xC0))
#define Usart_SetDuplexMode(_CHANNEL_,_VALUE_)                 			   WRITE_BIT((uartArr[(_CHANNEL_)]->USART_CR3),THREE_VALUE, (_VALUE_) )

#define Usart_SelectOversampleMode(_CHANNEL_,_VALUE_)                 	  do{\
																				WRITE_BIT((uartArr[(_CHANNEL_)]->USART_CR3),ELEVEN_VALUE, (((_VALUE_)>>ZERO_VALUE) &0x01) ) ;\
																				WRITE_BIT((uartArr[(_CHANNEL_)]->USART_CR1),FIFTEEN_VALUE, (((_VALUE_)>>ONE_VALUE) &0x01) ) ;\
																		}while(ZERO_VALUE)

#define Usart_SelectParityBitMode(_CHANNEL_,_VALUE_)              	  ((uartArr[(_CHANNEL_)]->USART_CR1 ) = ((uartArr[(_CHANNEL_)]->USART_CR1 ) & 0xFFFFF9FF) | (((_VALUE_)<< NINE_VALUE ) & 0x600))

#define Usart_SelectStopBits(_CHANNEL_,_VALUE_)              	        ((uartArr[(_CHANNEL_)]->USART_CR2 ) = ((uartArr[(_CHANNEL_)]->USART_CR2 ) & 0xFFFFCFFF) | (((_VALUE_)<< TWELVE_VALUE ) & 3000))

#define Usart_Enable(_CHANNEL_)											SET_BIT((uartArr[(_CHANNEL_)]->USART_CR1),THIRTEEN_VALUE )
#define Usart_EnableTx(_CHANNEL_)										SET_BIT((uartArr[(_CHANNEL_)]->USART_CR1),THREE_VALUE )
#define Usart_EnableRx(_CHANNEL_)										SET_BIT((uartArr[(_CHANNEL_)]->USART_CR1),TWO_VALUE )



#define Usart_Disable(_CHANNEL_)										CLEAR_BIT((uartArr[(_CHANNEL_)]->USART_CR1),THIRTEEN_VALUE)
#define Usart_DisableTx(_CHANNEL_)										CLEAR_BIT((uartArr[(_CHANNEL_)]->USART_CR2),THREE_VALUE)
#define Usart_DisableRx(_CHANNEL_)										CLEAR_BIT((uartArr[(_CHANNEL_)]->USART_CR2),TWO_VALUE)


#define Usart_SetClkInSyncMode(_CHANNEL_,_VALUE_)                 	    WRITE_BIT((uartArr[(_CHANNEL_)]->USART_CR2),ELEVEN_VALUE, (_VALUE_) )


#define Usart_SendBreakFrame(_CHANNEL_)									SET_BIT((uartArr[(_CHANNEL_)]->USART_CR1),ZERO_VALUE )



#define Usart_SetDataReg(_CHANNEL_,_VALUE_)								ASSIGN_REG((uartArr[(_CHANNEL_)]->USART_DR) , (_VALUE_)  )
#define Usart_GetDataReg(_CHANNEL_)						        		(uartArr[(_CHANNEL_)]->USART_DR)


#define Usart_IsTransmitDataRegisterEmpty(_CHANNEL_)				 (READ_BIT( (uartArr[(_CHANNEL_)]->USART_SR),SEVEN_VALUE) == ONE_VALUE )
#define Usart_IsReceiveDataRegisterEmpty(_CHANNEL_)				    (READ_BIT( (uartArr[(_CHANNEL_)]->USART_SR),FIVE_VALUE) == ZERO_VALUE )


/********************************** Data Type Declarations ****************************/

extern u64 Global_u64ABP1Freq;
extern u64 Global_u64ABP2Freq;

typedef volatile struct{
  	u32 USART_SR;
  	u32 USART_DR;
  	u32 USART_BRR;
  	u32 USART_CR1;
  	u32 USART_CR2;
  	u32 USART_CR3;
  	u32 USART_GPTR;
  }USARTx_Type;


#define USART1 	((volatile USARTx_Type*)(0x40011000))
#define USART2 	((volatile USARTx_Type*)(0x40004400))
#define USART3 	((volatile USARTx_Type*)(0x40004800))
#define USART4 	((volatile USARTx_Type*)(0x40004C00))
#define USART5 	((volatile USARTx_Type*)(0x40005000))
#define USART6 	((volatile USARTx_Type*)(0x40011400))
#define USART7 	((volatile USARTx_Type*)(0x40007800))
#define USART8 	((volatile USARTx_Type*)(0x40007C00))



static volatile USARTx_Type* uartArr[] = {USART1,USART2,USART3,USART4,USART5,USART6,USART7,USART8};

/********************************** Software Interfaces Declarations *******************/
static Usart_StatusErrorType Usart_enuSetBaudrate(const Usart_ConfigType* Address_Usart){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;
	f64 Loc_f64Brr ;
	u64 Loc_u64Fraction ;
	u64 Loc_u64IntPart ;
	u8 Loc_u8OverRun;
	if(Address_Usart == NULL){
		Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
	}
	else if(Address_Usart->select_sync_mode == USART_SELECT_ASYNCHRONOUS_MODE){
		Loc_u8OverRun = Address_Usart->select_oversample & 0b10;

		switch(Address_Usart->select_channel_number){

		case USART_SELECT_CHANNEL_1:
		case USART_SELECT_CHANNEL_6:

			Loc_f64Brr = (f64)Global_u64ABP2Freq/(Address_Usart->baude_rate)/(8*(2-Loc_u8OverRun));
			Loc_u64IntPart = (u64)Loc_f64Brr;
			Loc_u64Fraction =(Loc_f64Brr-Loc_u64IntPart)*16+0.5;
			if(Loc_u64Fraction ==16){
				Loc_u64Fraction = 0;
				Loc_u64IntPart++;
			}
			Usart_SetBaudrateIntPart(Address_Usart->select_channel_number,Loc_u64IntPart);
			Usart_SetBaudrateFractionPart(Address_Usart->select_channel_number,Loc_u64Fraction);

			break;



		case USART_SELECT_CHANNEL_2:
		case USART_SELECT_CHANNEL_3:
		case USART_SELECT_CHANNEL_4:
		case USART_SELECT_CHANNEL_5:
		case USART_SELECT_CHANNEL_7:
		case USART_SELECT_CHANNEL_8:

			Loc_f64Brr = (f64)Global_u64ABP1Freq/(Address_Usart->baude_rate)/(8*(2-Loc_u8OverRun));
			Loc_u64IntPart = (u64)Loc_f64Brr;
			Loc_u64Fraction =(Loc_f64Brr-Loc_u64IntPart)*16+0.5;
			if(Loc_u64Fraction ==16){
				Loc_u64Fraction = 0;
				Loc_u64IntPart++;
			}
			Usart_SetBaudrateIntPart(Address_Usart->select_channel_number,Loc_u64IntPart);
			Usart_SetBaudrateFractionPart(Address_Usart->select_channel_number,Loc_u64IntPart);

			break;


		default :
			Loc_UsartStatusError = USART_STATUS_FAIL;




		}
	}
	else{
		/* Sync Mode */
		Loc_UsartStatusError = USART_STATUS_FAIL;
	}
	return Loc_UsartStatusError;

}


static Usart_StatusErrorType Usart_enuEnableRccClock(const Usart_ConfigType* Address_Usart){
	Usart_StatusErrorType Loc_UsartStatusError = USART_STATUS_OK;

		if(Address_Usart == NULL){
			Loc_UsartStatusError = USART_STATUS_NULL_POINTER_ADDRESS;
		}
		else {
			switch(Address_Usart->select_channel_number){
			case USART_SELECT_CHANNEL_1:
				Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_APB2, FOUR_VALUE);
				break;
			case USART_SELECT_CHANNEL_6:
				Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_APB2, FIVE_VALUE);
				break;

			case USART_SELECT_CHANNEL_2:
				Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_APB1, SEVENTEEN_VALUE);
			case USART_SELECT_CHANNEL_3:
				Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_APB1, EIGHTEEN_VALUE);
			case USART_SELECT_CHANNEL_4:
				Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_APB1, NINETEEN_VALUE);
			case USART_SELECT_CHANNEL_5:
				Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_APB1, TWENTY_VALUE);
			case USART_SELECT_CHANNEL_7:
				Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_APB1, THIRTY_VALUE);
			case USART_SELECT_CHANNEL_8:
				Rcc_enuEnablePeripheralClk(RCC_BUS_INDEX_APB1, THIRTYONE_VALUE);
				break;

			default :
					Loc_UsartStatusError = USART_STATUS_FAIL;

			}
		}

		return Loc_UsartStatusError;

}


#endif /* UART_USART_PRIVATE_H_ */

