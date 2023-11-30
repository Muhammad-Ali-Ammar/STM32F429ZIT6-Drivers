/**************************************************************************/
/* Filename						: FLASH_DRIVER.h                             */
/* Author  	    				: Muhammad (Ali )Ammar                          */
/* Date 						: Nov 24, 2023	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/

#ifndef FLASH_DRIVER_FLASH_DRIVER_H_
#define FLASH_DRIVER_FLASH_DRIVER_H_



/********************************** Includes *********************************************/



/********************************** Macros Declarations *******************************/



/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/

//typedef enum{
//	FLASH_SELECT_SECTOR_0,
//	FLASH_SELECT_SECTOR_1,
//	FLASH_SELECT_SECTOR_2,
//	FLASH_SELECT_SECTOR_3,
//	FLASH_SELECT_SECTOR_4,
//	FLASH_SELECT_SECTOR_5,
//	FLASH_SELECT_SECTOR_6,
//	FLASH_SELECT_SECTOR_7,
//	FLASH_SELECT_SECTOR_8,
//	FLASH_SELECT_SECTOR_9,
//	FLASH_SELECT_SECTOR_10,
//	FLASH_SELECT_SECTOR_11,
//
//	FLASH_SELECT_SECTOR_12 =0b10000,
//	FLASH_SELECT_SECTOR_13,
//	FLASH_SELECT_SECTOR_14,
//	FLASH_SELECT_SECTOR_15,
//	FLASH_SELECT_SECTOR_16,
//	FLASH_SELECT_SECTOR_17,
//	FLASH_SELECT_SECTOR_18,
//	FLASH_SELECT_SECTOR_19,
//	FLASH_SELECT_SECTOR_20,
//	FLASH_SELECT_SECTOR_21,
//	FLASH_SELECT_SECTOR_22,
//	FLASH_SELECT_SECTOR_23,
//
//
//}Flash_SelectSectorNumberType;

typedef enum{
	FLASH_SELECT_BANK_1 = TWO_VALUE,
	FLASH_SELECT_BANK_2 = FIFTEEN_VALUE
}Flash_SelectBankNumberType;

typedef enum{
  	FLASH_STATUS_FAIL,
  	FLASH_STATUS_OK,
  	FLASH_STATUS_NULL_POINTER_ADDRESS
  }Flash_ErrorStatusType;


/********************************** Software Interfaces Declarations *******************/

Flash_ErrorStatusType Flash_enuInit(void);
Flash_ErrorStatusType Flash_enuLock(void);
Flash_ErrorStatusType Flash_enuUnlock(void);
Flash_ErrorStatusType Flash_enuWriteWordAt_Sync(u32 Copy_u32Address,u8 Copy_u8Data[]);
Flash_ErrorStatusType Flash_enuReadWordAt_Sync(u32 Copy_u32Address,u8 Address_Result[]);
Flash_ErrorStatusType Flash_enuEraseSectorAt_Sync(u8 Copy_u8SectorIndex);
Flash_ErrorStatusType Flash_enuWriteProtectionForSectorx_Sync(u8 Copy_u8SectorIndex);
Flash_ErrorStatusType Flash_enuRemoveWriteProtectionForSectorx_Sync(u8 Copy_u8SectorIndex);
Flash_ErrorStatusType Flash_enuLockOptionByte(void);
Flash_ErrorStatusType Flash_enuUnlockOptionByte(void);

Flash_ErrorStatusType Flash_enuIsProgramAlignmentErrorHappended(Std_True_or_FalseType* Address_Result);
Flash_ErrorStatusType Flash_enuIsProgramParallelismErrorHappended(Std_True_or_FalseType* Address_Result);
Flash_ErrorStatusType Flash_enuIsProgramSequenceErrorHappended(Std_True_or_FalseType* Address_Result);
Flash_ErrorStatusType Flash_enuIsWriteProtoectionErrorHappended(Std_True_or_FalseType* Address_Result);

/* Errors And Interrupts */

Flash_ErrorStatusType Flash_enuEnableWriteProtectionErrorInterrupt(void);
Flash_ErrorStatusType Flash_enuDisableWriteProtectionErrorInterrupt(void);
Flash_ErrorStatusType Flash_enuSetCallbackWriteProtectionErrorInterruptFunction(void (*callback)(void));


Flash_ErrorStatusType Flash_enuEnableProgramAlignmentErrorInterrupt(void);
Flash_ErrorStatusType Flash_enuDisableProgramAlignmentErrorInterrupt(void);
Flash_ErrorStatusType Flash_enuSetCallbackProgramAlignmentErrorInterruptFunction(void (*callback)(void));

Flash_ErrorStatusType Flash_enuEnableProgramParallelismErrorInterrupt(void);
Flash_ErrorStatusType Flash_enuDisableProgramParallelismErrorInterrupt(void);
Flash_ErrorStatusType Flash_enuSetCallbackProgramParallelismErrorInterruptFunction(void (*callback)(void));

Flash_ErrorStatusType Flash_enuEnableProgramSequanceErrorInterrupt(void);
Flash_ErrorStatusType Flash_enuDisableProgramSequanceErrorInterrupt(void);
Flash_ErrorStatusType Flash_enuSetCallbackProgramSequanceErrorInterruptFunction(void (*callback)(void));


Flash_ErrorStatusType Flash_enuEnableEndOfOperationInterrupt(void);
Flash_ErrorStatusType Flash_enuDisableEndOfOperationInterrupt(void);
Flash_ErrorStatusType Flash_enuSetCallbackEndOfOperationInterruptFunction(void (*callback)(void));


/* Cahce Part */

Flash_ErrorStatusType Flash_enuEnablePrefetch(void);
Flash_ErrorStatusType Flash_enuDisablePrefetch(void);

Flash_ErrorStatusType Flash_enuEnableInstructionCache(void);
Flash_ErrorStatusType Flash_enuDisableInstructionCache(void);


Flash_ErrorStatusType Flash_enuEnableDataCache(void);
Flash_ErrorStatusType Flash_enuDisableDataCache(void);

Flash_ErrorStatusType Flash_enuResetDataCache(void);
Flash_ErrorStatusType Flash_enuResetInstructionCache(void);


#endif /* FLASH_DRIVER_FLASH_DRIVER_H_ */
