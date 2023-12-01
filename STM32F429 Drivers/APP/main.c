///**************************************************************************/
///* Filename						: main.c                                    */
///* Author  	    				: Muhammad Ammar                          */
///* Date 						: Nov 5, 2023  	           	 	      	 */
///* Version 	 					: V01                                     */
///* MicroController  			: STM32F429 							 */
///**************************************************************************/
//
//#include "main.h"
//
//
//
//extern Rcc_ConfigType rcc;
//extern Usart_ConfigType Usart1;
//void Usart_Isr(u16 Copy_u16Result);
//
//
//
//
//typedef enum{
//	STATE_IDLE,
//	STATE_FLASH_LOCK,
//	STATE_FLASH_UnlOCK,
//	STATE_WRITE,
//	STATE_READ,
//	STATE_SECTOR_ERASE,
//	STATE_WRITE_PROTECTION,
//	STATE_REMOVE_WRITE_PROTECTION,
//	STATE_OPTION_BYTE_UNLOCK,
//	STATE_OPTION_BYTE_LOCK
//}StateMachineType;
//
//void App_IdleState(void);
//void App_WelcomeMesasage(void);
//
//void App_WaitCommandState(void);
//
//
//void App_FlashLockState(void);
//void App_FlashUnlockState(void);
//void App_WriteState(void);
//void App_ReadState(void);
//void App_SectorEraseState(void);
//void App_WriteProtectionState(void);
//void App_RemoveWriteProtectionState(void);
//void App_OptionByteLockState(void);
//void App_OptionByteUnlockState(void);
//void App_CheckErrors(Std_True_or_FalseType* Address_Result);
//
//static u8 Global_UartMessage[100];
//static Std_True_or_FalseType Global_UartMessageFlag = ZERO_VALUE;
//
//
//int main(void)
//{
//	/********************************** It must *************************************/
//
//	/* RCC PART */
//	Rcc_enuInit(&rcc);
//	Gpio_enuEnableClockAllGPIOs();
//
//
//
//	/* Interrupt Part */
//	Scb_enuSetGroupPrioirty(SCB_SELECT_GROUP_PRIORITY_ZERO_AND_SUB_PRIORITY_16);
//
//
//
//	Gpio_enuInit();
//
//
//
//	/* UART part */
//
//	Nvic_SetInterruptPriority(NVIC_USART1, NVIC_Select_Group_0, NVIC_Select_Sub_0);
//	Gpio_enuSetAF(GPIO_PINB6, GPIO_SELECT_AF7_USART1_USART2_USART3); // for Usart Tx1
//	Gpio_enuSetAF(GPIO_PINB7, GPIO_SELECT_AF7_USART1_USART2_USART3); // for Usart Rx1
//
//
//	Usart_enuSetCallbackRxFunction(&Usart1, Usart_Isr);
//	Usart_enuInit(&Usart1);
//	Usart_enuEnableRxInterrupt(&Usart1);
//	Nvic_enuEnableInterrupt(NVIC_USART1);
//
//
//	/* Flash Driver Part */
//	Flash_enuInit();
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////
//
//	App_IdleState();
//
//
//	App_WaitCommandState();
//
//	for(;;){
//
//
//	}
//}
//
//
//
//
//
//
//
//void App_IdleState(void){
//
//	u8 Loc_u8CheckFlag = ZERO_VALUE;
//	while(Loc_u8CheckFlag == ZERO_VALUE){
//
//		if(Global_UartMessageFlag == STD_TRUE){
//
//			Global_UartMessageFlag = STD_FALSE;
//
//
//			/* If True, then break from While */
//			if(CompareTwoStrings(Global_UartMessage,(u8*)"Start") == STD_TRUE){
//				Loc_u8CheckFlag = ONE_VALUE;
//				App_WelcomeMesasage();
//			}
//		}
//	}
//}
//
//void App_WelcomeMesasage(void){
//	Usart_enuTransmitStringBlocking(&Usart1,(u8*) "******WELCOME To Flash Controller******\n");
//	Usart_enuTransmitStringBlocking(&Usart1,(u8*) "Select Command From The Following: \n");
//	Usart_enuTransmitStringBlocking(&Usart1,(u8*) "***************************************\n");
//	Usart_enuTransmitStringBlocking(&Usart1,(u8*) "1- Flash Lock \n");
//	Usart_enuTransmitStringBlocking(&Usart1,(u8*) "2- Flash Unlock \n");
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"3- Write Data \n");
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"4- Read Data \n");
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"5- Sector Erase  \n");
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"6- Write Protection \n");
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"7- Remove Write Protection \n");
//	Usart_enuTransmitStringBlocking(&Usart1,(u8*) "8- Option Byte unlock \n");
//	Usart_enuTransmitStringBlocking(&Usart1,(u8*) "9- Option Byte Lock \n");
//	Usart_enuTransmitStringBlocking(&Usart1,(u8*) "***************************************\n");
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"Thanks To Eng/ Ahmed El-Deep... https://www.youtube.com/@ahmedeldeep \n\n");
//
//
//}
//
//
//
//void App_WaitCommandState(void){
//
//	while(1){
//		if(Global_UartMessageFlag == STD_TRUE){
//
//			Global_UartMessageFlag = STD_FALSE;
//
//
//			if( CompareTwoStrings(Global_UartMessage,(u8*)"1") == STD_TRUE){
//				App_FlashLockState();
//			}
//
//			else if( CompareTwoStrings(Global_UartMessage,(u8*)"2") == STD_TRUE){
//				App_FlashUnlockState();
//			}
//
//			else if( CompareTwoStrings(Global_UartMessage,(u8*)"3") == STD_TRUE){
//				App_WriteState();
//			}
//			else if( CompareTwoStrings(Global_UartMessage,(u8*)"4") == STD_TRUE){
//				App_ReadState();
//			}
//			else if( CompareTwoStrings(Global_UartMessage,(u8*)"5") == STD_TRUE){
//				App_SectorEraseState();
//			}
//			else if( CompareTwoStrings(Global_UartMessage,(u8*)"6") == STD_TRUE){
//				App_WriteProtectionState();
//			}
//			else if( CompareTwoStrings(Global_UartMessage,(u8*)"7") == STD_TRUE){
//				App_RemoveWriteProtectionState();
//			}
//			else if( CompareTwoStrings(Global_UartMessage,(u8*)"8") == STD_TRUE){
//
//				App_OptionByteUnlockState();
//			}
//			else if( CompareTwoStrings(Global_UartMessage,(u8*)"9") == STD_TRUE){
//				App_OptionByteLockState();
//			}
//
//			else{
//				/* No Nothing */
//			}
//
//
//
//
//		}
//
//	}
//}
//
//
//void App_FlashLockState(void){
//
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nFlash Is Locked \n\n");
//	Flash_enuLock();
//}
//void App_FlashUnlockState(void){
//
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nFlash Is UnLocked \n\n");
//	Flash_enuUnlock();
//}
//
//
//void App_WriteState(void){
//
//	u8 Loc_u8CheckFlag = ZERO_VALUE;
//	Std_True_or_FalseType Loc_Check = STD_FALSE;
//	u32 Loc_u32Address;
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nEnter Address To Write To : ");
//
//
//	/* Get Address Part */
//	while(Loc_u8CheckFlag == ZERO_VALUE){
//
//		if(Global_UartMessageFlag == STD_TRUE){
//
//			Global_UartMessageFlag = STD_FALSE;
//			Loc_u32Address = (*((u32*)Global_UartMessage));
//
//			Loc_u8CheckFlag = ONE_VALUE;
//		}
//	}
//
//
//	/* Get Data Part */
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nEnter Data To Write To : ");
//
//	Loc_u8CheckFlag = ZERO_VALUE;
//	while(Loc_u8CheckFlag == ZERO_VALUE){
//
//		if(Global_UartMessageFlag == STD_TRUE){
//			Global_UartMessageFlag = STD_FALSE;
//			Loc_u8CheckFlag = ONE_VALUE;
//		}
//	}
//
//	Flash_enuWriteWordAt_Sync(Loc_u32Address, Global_UartMessage);
//	App_CheckErrors(&Loc_Check);
//	if(Loc_Check != STD_TRUE){
//		Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nWriting Is Done \n");
//
//	}
//
//
//
//}
//
//void App_ReadState(void){
//	u8 Loc_u8CheckFlag = ZERO_VALUE;
//	u32 Loc_u32Address;
//	Std_True_or_FalseType Loc_Check = STD_FALSE;
//
//	u8 Loc_DataTempInAsci[4];
//	u8 Loc_DataTempString[100];
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nEnter Address To Read From : ");
//
//
//	/* Get Address Part */
//	while(Loc_u8CheckFlag == ZERO_VALUE){
//
//		if(Global_UartMessageFlag == STD_TRUE){
//
//			Global_UartMessageFlag = STD_FALSE;
//			Loc_u32Address = (*((u32*)Global_UartMessage));
//
//			Loc_u8CheckFlag = ONE_VALUE;
//		}
//	}
//	App_CheckErrors(&Loc_Check);
//
//	if(Loc_Check != STD_TRUE){
//		Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nThe Data Is : ");
//
//		Flash_enuReadWordAt_Sync(Loc_u32Address , Loc_DataTempInAsci);
//
//		Convert_IntToString(Loc_DataTempInAsci[0], Loc_DataTempString);
//		Usart_enuTransmitStringBlocking(&Usart1, Loc_DataTempString);
//
//
//		Convert_IntToString(Loc_DataTempInAsci[1], Loc_DataTempString);
//		Usart_enuTransmitStringBlocking(&Usart1, Loc_DataTempString);
//
//		Convert_IntToString(Loc_DataTempInAsci[2], Loc_DataTempString);
//		Usart_enuTransmitStringBlocking(&Usart1, Loc_DataTempString);
//
//		Convert_IntToString(Loc_DataTempInAsci[3], Loc_DataTempString);
//		Usart_enuTransmitStringBlocking(&Usart1, Loc_DataTempString);
//
//	}
//
//
//
//
//
//}
//
//
//void App_SectorEraseState(void){
//
//	u8 Loc_u8CheckFlag = ZERO_VALUE;
//	u8 Loc_u8SectorNumberInt;
//
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nEnter Sector Index To Write To : ");
//
//
//	/* Get sector number Part */
//	while(Loc_u8CheckFlag == ZERO_VALUE){
//
//		if(Global_UartMessageFlag == STD_TRUE){
//
//			Global_UartMessageFlag = STD_FALSE;
//			Usart_enuTransmitStringBlocking(&Usart1,Global_UartMessage );
//			Convert_StringTou8(&Loc_u8SectorNumberInt, Global_UartMessage);
//
//
//			Loc_u8CheckFlag = ONE_VALUE;
//		}
//	}
//	/*
//	 * user will enter 0 to 11  --->
//	 * and will enter  12 to 23
//	 */
//	if(Loc_u8SectorNumberInt> 11){
//		Loc_u8SectorNumberInt+=FOUR_VALUE;
//	}
//
//	Flash_enuEraseSectorAt_Sync(Loc_u8SectorNumberInt);
//
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nErasing Action Is Done \n");
//
//}
//void App_WriteProtectionState(void){
//	u8 Loc_u8CheckFlag = ZERO_VALUE;
//	Std_True_or_FalseType Loc_Check = STD_FALSE;
//
//		u8 Loc_u8SectorNumberInt;
//		Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nEnter Sector Index To Add Write Protection: ");
//
//
//		/* Get sector number Part */
//		while(Loc_u8CheckFlag == ZERO_VALUE){
//
//			if(Global_UartMessageFlag == STD_TRUE){
//
//				Global_UartMessageFlag = STD_FALSE;
//				Usart_enuTransmitStringBlocking(&Usart1,Global_UartMessage );
//				Convert_StringTou8(&Loc_u8SectorNumberInt, Global_UartMessage);
//
//
//				Loc_u8CheckFlag = ONE_VALUE;
//			}
//		}
//		/*
//		 * user will enter 0 to 11  --->
//		 * and will enter  12 to 23
//		 */
//
//		Flash_enuWriteProtectionForSectorx_Sync(Loc_u8SectorNumberInt);
//		App_CheckErrors(&Loc_Check);
//
//		if(Loc_Check != STD_TRUE){
//			Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nWrite Protection Is Done \n");
//
//
//		}
//
//
//}
//
//
//void App_RemoveWriteProtectionState(void){
//	u8 Loc_u8CheckFlag = ZERO_VALUE;
//		u8 Loc_u8SectorNumberInt;
//		Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nEnter Sector Index To Remove Write Protection : ");
//
//
//		/* Get sector number Part */
//		while(Loc_u8CheckFlag == ZERO_VALUE){
//
//			if(Global_UartMessageFlag == STD_TRUE){
//
//				Global_UartMessageFlag = STD_FALSE;
//				Usart_enuTransmitStringBlocking(&Usart1,Global_UartMessage );
//				Convert_StringTou8(&Loc_u8SectorNumberInt, Global_UartMessage);
//
//
//				Loc_u8CheckFlag = ONE_VALUE;
//			}
//		}
//		/*
//		 * user will enter 0 to 11  --->
//		 * and will enter  12 to 23
//		 */
//
//		Flash_enuRemoveWriteProtectionForSectorx_Sync(Loc_u8SectorNumberInt);
//
//		Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nRemove Write Protection Is Done \n");
//}
//
//void App_OptionByteLockState(void){
//
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nOption Byte Is Locked \n\n");
//	Flash_enuLockOptionByte();
//}
//
//void App_OptionByteUnlockState(void){
//
//	Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nOption Byte Is Unlocked \n\n");
//	Flash_enuUnlockOptionByte();
//}
//
//
//void App_CheckErrors(Std_True_or_FalseType* Address_Result){
//	Std_True_or_FalseType Loc_FLagCheck = STD_FALSE;
//	*Address_Result = STD_FALSE;
//	Flash_enuIsProgramSequenceErrorHappended(&Loc_FLagCheck);
//	if(Loc_FLagCheck == STD_TRUE){
//		Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nProgram Sequnce Error \n\n");
//		*Address_Result = STD_TRUE;
//
//	}
//
//	Flash_enuIsProgramParallelismErrorHappended(&Loc_FLagCheck);
//	if(Loc_FLagCheck == STD_TRUE){
//		Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nProgram Parallelism Error \n\n");
//		*Address_Result = STD_TRUE;
//	}
//
//
//	Flash_enuIsProgramAlignmentErrorHappended(&Loc_FLagCheck);
//	if(Loc_FLagCheck == STD_TRUE){
//		Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nProgram Alignment Error \n\n");
//		*Address_Result = STD_TRUE;
//	}
//
//	Flash_enuIsWriteProtoectionErrorHappended(&Loc_FLagCheck);
//	if(Loc_FLagCheck == STD_TRUE){
//		Usart_enuTransmitStringBlocking(&Usart1, (u8*)"\nWrite Protection Error \n\n");
//		*Address_Result = STD_TRUE;
//	}
//
//
//
//}
//
///* Uart String PArt */
//void Usart_Isr(u16 Copy_u16Result){
//
//	static u8 Loc_u8Counter = ZERO_VALUE;
//
//	Global_UartMessage[Loc_u8Counter++]=(u8)Copy_u16Result;
//	if(Copy_u16Result =='\r'){
//		Global_UartMessageFlag= STD_TRUE;
//		Loc_u8Counter = ZERO_VALUE;
//	}
//
//
//
//
//}


/**************************************************************************/
/* Filename						: main.c                                    */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 5, 2023  	           	 	      	 */
/* Version 	 					: V01                                     */
/* MicroController  			: STM32F429 							 */
/**************************************************************************/

#include "main.h"



extern Rcc_ConfigType rcc;
extern Can_ConfigType can1;


void Can_Isr (Can_MessageType* Receive_Message,u8 _ArrMessageData[EIGHT_VALUE],u8 Address_FilterIndex){


}



int main(void)
{
	/********************************** It must *************************************/

	/* RCC PART */
	Rcc_enuInit(&rcc);
	Gpio_enuEnableClockAllGPIOs();



	/* Interrupt Part */
	Scb_enuSetGroupPrioirty(SCB_SELECT_GROUP_PRIORITY_ZERO_AND_SUB_PRIORITY_16);



	Gpio_enuInit();


//
//	/* UART part */
//
//	Nvic_SetInterruptPriority(NVIC_USART1, NVIC_Select_Group_0, NVIC_Select_Sub_0);
//	Gpio_enuSetAF(GPIO_PINB6, GPIO_SELECT_AF7_USART1_USART2_USART3); // for Usart Tx1
//	Gpio_enuSetAF(GPIO_PINB7, GPIO_SELECT_AF7_USART1_USART2_USART3); // for Usart Rx1
//
//
//	Usart_enuSetCallbackRxFunction(&Usart1, Usart_Isr);
//	Usart_enuInit(&Usart1);
//	Usart_enuEnableRxInterrupt(&Usart1);
//	Nvic_enuEnableInterrupt(NVIC_USART1);
//


	/* CAN PART */

		Gpio_enuSetAF(GPIO_PINA11, GPIO_SELECT_AF9_CAN1_CAN2_LTDC_TIM12_TIM13_TIM14); // for can
		Gpio_enuSetAF(GPIO_PINA12, GPIO_SELECT_AF9_CAN1_CAN2_LTDC_TIM12_TIM13_TIM14); // for can

		Can_enuSetCallbackRxFunctionFifox(CAN_RX_FIFO_MAIL_BOX_INDEX_0, Can_Isr);
		Can_enuInit(&can1);
		Can_enuEnableRxInterruptFifox(CAN_RX_FIFO_MAIL_BOX_INDEX_0);
		Nvic_enuEnableInterrupt(NVIC_CAN1_RX0);

///////////////////////////////////////////////////////////////////////////////////////


	for(;;){


	}
}






