/**************************************************************************/
/* Filename						: FLASH_DRIVER.c                             */
/* Author  	    				: Muhammad (Ali )Ammar                          */
/* Date 						: Nov 24, 2023	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/





/********************************** Includes *********************************************/

#include "../../SERVICES/BIT_UTILS.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/MAGIC_NUMBERS.h"
#include "../../SERVICES/HELPERS.h"

#include "../../MCAL/RCC/RCC.h"

#include "FLASH_DRIVER.h"
#include "FLASH_DRIVER_config.h"
#include "FLASH_DRIVER_private.h"


/********************************** Private declaration **********************************/



/********************************** Data Type Declarations ****************************/


/********************************** Macros Declarations *******************************/

/********************************** Macros Function Declarations *********************/




/******************************* Software Interfaces Implementation *******************/

Flash_ErrorStatusType Flash_enuInit(void){

	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_Unlock();

	Flash_SetProgramSize(FLASH_SELECT_VOLT_RAGE);

	Flash_Lock();
	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuLock(void){

		Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

		Flash_Lock();


		return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuUnlock(void){

		Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

		Flash_Unlock();


		return Loc_enuFlashErrorStatus;
}


Flash_ErrorStatusType Flash_enuWriteWordAt_Sync(u32 Copy_u32Address,u8 Copy_u8Data[]){

	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	u32 Loc_u32Data;
	/* wait busy flag */
	while(Flash_IsFlashOperatingBusy() == ONE_VALUE);

	/* Enter Write Mode */
	Flash_SetFlashWritingMode();

	/* Write To the address */
	Loc_u32Data =*((u32*)(Copy_u8Data));
	*((volatile u32*)(Copy_u32Address)) = Loc_u32Data;


	/* wait busy flag */
	while(Flash_IsFlashOperatingBusy() == ONE_VALUE);

	/* Get Out of Write Mode */
	Flash_GetOutOfFlashWritingMode();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuReadWordAt_Sync(u32 Copy_u32Address,u8 Address_Result[]){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	u32 Loc_u32Data;
	while(Flash_IsFlashOperatingBusy() == ONE_VALUE);

	Loc_u32Data= *((u32*)(Copy_u32Address));
	*((u32*)(Address_Result)) = Loc_u32Data;


		return Loc_enuFlashErrorStatus;
}

/*
 * From 0 To 11 (BANK 1 )
 * from (12 to 23) + 4  (BANK 2 )
 *
 */
Flash_ErrorStatusType Flash_enuEraseSectorAt_Sync(u8 Copy_u8SectorIndex){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;


	/* wait busy flag */
	while(Flash_IsFlashOperatingBusy() == ONE_VALUE);

	/* Select Sector */
	Flash_SetEraseModeSectorx(Copy_u8SectorIndex);


	/* Start Erasing */
	Flash_StartErasingAction();


	/* Get Out */
	Flash_GetOutOfEraseMode();

	return Loc_enuFlashErrorStatus;
}


/*
 * Copy_u8SectorIndex = from 0 TO 11
 * or From 12 To 23
 *
 */
Flash_ErrorStatusType Flash_enuWriteProtectionForSectorx_Sync(u8 Copy_u8SectorIndex){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	u8 Loc_u8BankIndex;

	if(Copy_u8SectorIndex<=11){
		Loc_u8BankIndex = ZERO_VALUE;
	}
	else{
		Loc_u8BankIndex = ONE_VALUE;
		Copy_u8SectorIndex-=12;
	}

	/* wait busy flag */
	while(Flash_IsFlashOperatingBusy() == ONE_VALUE);

	/* Write Protection */
	Flash_WriteProtectionAtSectorx(Loc_u8BankIndex,Copy_u8SectorIndex);

	/* Start Write Protection ACtion */
	Flash_StartWriteProtectionAction();

	/* wait busy flag */
	while(Flash_IsFlashOperatingBusy() == ONE_VALUE);

	return Loc_enuFlashErrorStatus;
}


/*
 * Copy_u8SectorIndex = from 0 TO 11
 * or From 12 To 23
 *
 */
Flash_ErrorStatusType Flash_enuRemoveWriteProtectionForSectorx_Sync(u8 Copy_u8SectorIndex){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	u8 Loc_u8BankIndex;

	if(Copy_u8SectorIndex<=11){
		Loc_u8BankIndex = ZERO_VALUE;
	}
	else{
		Loc_u8BankIndex = ONE_VALUE;
		Copy_u8SectorIndex-=12;
	}

	/* wait busy flag */
	while(Flash_IsFlashOperatingBusy() == ONE_VALUE);

	/* Remove Write Protection */
	Flash_RemoveWriteProtectionAtSectorx(Loc_u8BankIndex,Copy_u8SectorIndex);

	/* Start Write Protection ACtion */
	Flash_StartWriteProtectionAction();

	/* wait busy flag */
	while(Flash_IsFlashOperatingBusy() == ONE_VALUE);

	return Loc_enuFlashErrorStatus;
}



Flash_ErrorStatusType Flash_enuLockOptionByte(void){

	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_LockByteOption();


	return Loc_enuFlashErrorStatus;
}


Flash_ErrorStatusType Flash_enuUnlockOptionByte(void){

	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_UnlockByteOption();


	return Loc_enuFlashErrorStatus;
}









/* Errors And Interrupts */

Flash_ErrorStatusType Flash_enuEnableWriteProtectionErrorInterrupt(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_EnableErrorInterrupt();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuDisableWriteProtectionErrorInterrupt(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_DisableErrorInterrupt();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuSetCallbackWriteProtectionErrorInterruptFunction(void (*callback)(void)){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	if(callback == NULL){
		Loc_enuFlashErrorStatus = FLASH_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		Flash_ErrorInterruptHandler[FLASH_WRITE_PROTECTION_ERROR_INDEX]=callback;
	}
	return Loc_enuFlashErrorStatus;
}


Flash_ErrorStatusType Flash_enuEnableProgramAlignmentErrorInterrupt(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_EnableErrorInterrupt();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuDisableProgramAlignmentErrorInterrupt(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_DisableErrorInterrupt();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuSetCallbackProgramAlignmentErrorInterruptFunction(void (*callback)(void)){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	if(callback == NULL){
		Loc_enuFlashErrorStatus = FLASH_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		Flash_ErrorInterruptHandler[FLASH_PROGRAM_ALIGNEMNT_ERROR_INDEx]=callback;
	}
	return Loc_enuFlashErrorStatus;
}



Flash_ErrorStatusType Flash_enuEnableProgramParallelismErrorInterrupt(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_EnableErrorInterrupt();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuDisableProgramParallelismErrorInterrupt(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_DisableErrorInterrupt();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuSetCallbackProgramParallelismErrorInterruptFunction(void (*callback)(void)){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	if(callback == NULL){
		Loc_enuFlashErrorStatus = FLASH_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		Flash_ErrorInterruptHandler[FLASH_PROGRAM_PARALLELISM_ERROR_INDEx]=callback;
	}
	return Loc_enuFlashErrorStatus;
}



Flash_ErrorStatusType Flash_enuEnableProgramSequanceErrorInterrupt(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_EnableErrorInterrupt();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuDisableProgramSequanceErrorInterrupt(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_DisableErrorInterrupt();

	return Loc_enuFlashErrorStatus;
}


Flash_ErrorStatusType Flash_enuSetCallbackProgramSequanceErrorInterruptFunction(void (*callback)(void)){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	if(callback == NULL){
		Loc_enuFlashErrorStatus = FLASH_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		Flash_ErrorInterruptHandler[FLASH_PROGRAM_SEQUANCE_ERROR_INDEx]=callback;
	}
	return Loc_enuFlashErrorStatus;
}


Flash_ErrorStatusType Flash_enuEnableEndOfOperationInterrupt(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_EnableErrorInterrupt();

	return Loc_enuFlashErrorStatus;
}
Flash_ErrorStatusType Flash_enuDisableEndOfOperationInterrupt(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_DisableErrorInterrupt();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuSetCallbackEndOfOperationInterruptFunction(void (*callback)(void)){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	if(callback == NULL){
		Loc_enuFlashErrorStatus = FLASH_STATUS_NULL_POINTER_ADDRESS;
	}
	else{

		Flash_EndOfOperationInterruptHandler=callback;
	}
	return Loc_enuFlashErrorStatus;
}




Flash_ErrorStatusType Flash_enuEnablePrefetch(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_EnablePrefetch();

	return Loc_enuFlashErrorStatus;
}
Flash_ErrorStatusType Flash_enuDisablePrefetch(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_DisablePrefetch();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuEnableInstructionCache(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_EnableInstructionCache();

	return Loc_enuFlashErrorStatus;
}
Flash_ErrorStatusType Flash_enuDisableInstructionCache(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_DisableInstructionCache();

	return Loc_enuFlashErrorStatus;
}


Flash_ErrorStatusType Flash_enuEnableDataCache(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_EnableDataCache();

	return Loc_enuFlashErrorStatus;
}
Flash_ErrorStatusType Flash_enuDisableDataCache(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_DisableDataCache();

	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuResetDataCache(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_ResetDataCache();

	return Loc_enuFlashErrorStatus;
}
Flash_ErrorStatusType Flash_enuResetInstructionCache(void){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;

	Flash_ResetInstrctionCache();

	return Loc_enuFlashErrorStatus;
}


Flash_ErrorStatusType Flash_enuIsProgramAlignmentErrorHappended(Std_True_or_FalseType* Address_Result){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	if(Address_Result == NULL){

	}
	else{
		if(Flash_IsProgramAlignmentErrorHappended() == ONE_VALUE ){
			*Address_Result = STD_TRUE;
			Flash_ClearProgramAlignmentErrorFlag();
		}
		else{
			*Address_Result = STD_FALSE;
		}
	}
	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuIsProgramParallelismErrorHappended(Std_True_or_FalseType* Address_Result){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	if(Address_Result == NULL){

	}
	else{
		if(Flash_IsProgramParallelismErrorHappended() == ONE_VALUE ){
			*Address_Result = STD_TRUE;
			Flash_ClearProgramParallelismErrorFlag();
		}
		else{
			*Address_Result = STD_FALSE;
		}
	}
	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuIsProgramSequenceErrorHappended(Std_True_or_FalseType* Address_Result){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	if(Address_Result == NULL){

	}
	else{
		if(Flash_IsProgramSequenceErrorHappended() == ONE_VALUE ){
			*Address_Result = STD_TRUE;
			Flash_ClearProgramSequenceErrorFlag();
		}
		else{
			*Address_Result = STD_FALSE;
		}
	}
	return Loc_enuFlashErrorStatus;
}

Flash_ErrorStatusType Flash_enuIsWriteProtoectionErrorHappended(Std_True_or_FalseType* Address_Result){
	Flash_ErrorStatusType Loc_enuFlashErrorStatus = FLASH_STATUS_OK;
	if(Address_Result == NULL){

	}
	else{
		if(Flash_IsWriteProtoectionErrorHappended() == ONE_VALUE ){
			*Address_Result = STD_TRUE;
			Flash_ClearWriteProtoectionErrorFlag();
		}
		else{
			*Address_Result = STD_FALSE;
		}
	}
	return Loc_enuFlashErrorStatus;
}




/**************************** Private Software Interface Implementation **************/


void FLASH_IRQHandler(void){

	/* Error Part FIrst */

	if(Flash_IsOperationErrorHappended() == ONE_VALUE){

		/* Which Error */
		if(Flash_IsProgramAlignmentErrorHappended() == ONE_VALUE ){

			if( Flash_ErrorInterruptHandler[FLASH_PROGRAM_ALIGNEMNT_ERROR_INDEx] != NULL){
			Flash_ErrorInterruptHandler[FLASH_PROGRAM_ALIGNEMNT_ERROR_INDEx]();
			}

			/* Clear Flag */
			Flash_ClearProgramAlignmentErrorFlag();

		}

		if(Flash_IsProgramParallelismErrorHappended() == ONE_VALUE){

			if( Flash_ErrorInterruptHandler[FLASH_PROGRAM_PARALLELISM_ERROR_INDEx] != NULL){

				Flash_ErrorInterruptHandler[FLASH_PROGRAM_PARALLELISM_ERROR_INDEx]();
			}
			/* Clear Flag */
			Flash_ClearProgramParallelismErrorFlag();

		}

		if(Flash_IsProgramSequenceErrorHappended() == ONE_VALUE){

			if( Flash_ErrorInterruptHandler[FLASH_PROGRAM_SEQUANCE_ERROR_INDEx] != NULL){

			Flash_ErrorInterruptHandler[FLASH_PROGRAM_SEQUANCE_ERROR_INDEx]();
			}
			/* Clear Flag */
			Flash_ClearProgramSequenceErrorFlag();

		}

		if(Flash_IsWriteProtoectionErrorHappended() == ONE_VALUE){

			if( Flash_ErrorInterruptHandler[FLASH_WRITE_PROTECTION_ERROR_INDEX] != NULL){

			Flash_ErrorInterruptHandler[FLASH_WRITE_PROTECTION_ERROR_INDEX]();

			}
			/* Clear Flag */
			Flash_ClearWriteProtoectionErrorFlag();

		}

		Flash_ClearOperationErrorFlag();
	}



	/* End Of Operation Part */
	if(Flash_IsEndOfOperationrHappended() == ONE_VALUE){

			if(Flash_EndOfOperationInterruptHandler != NULL){
				Flash_EndOfOperationInterruptHandler();

			}

				/* Clear Flag */
				Flash_ClearProgramAlignmentErrorFlag();


			Flash_ClearEndOfOperationrFlag();

	}


}
