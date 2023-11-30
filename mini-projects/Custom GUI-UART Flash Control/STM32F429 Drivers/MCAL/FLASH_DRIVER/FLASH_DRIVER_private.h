/**************************************************************************/
/* Filename						: FLASH_DRIVER_private.h                             */
/* Author  	    				: Muhammad (Ali )Ammar                          */
/* Date 						: Nov 24, 2023	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/

#ifndef FLASH_DRIVER_FLASH_DRIVER_PRIVATE_H_
#define FLASH_DRIVER_FLASH_DRIVER_PRIVATE_H_



/********************************** Private Declaration  *********************************************/


static void (*Flash_ErrorInterruptHandler[FOUR_VALUE])( void);
static void (*Flash_EndOfOperationInterruptHandler)( void);

/********************************** Data Type Declarations ****************************/

typedef volatile struct{
  	u32 FLASH_ACR;
  	u32 FLASH_KEYR;
  	u32 FLASH_OPTKEYR;
  	u32 FLASH_SR;
  	u32 FLASH_CR;
  	u32 FLASH_OPTCR[TWO_VALUE];
  }FLASH_Type;




#define FLASH1 	((volatile FLASH_Type*)(0x40023C00))




/********************************** Macros Declarations *******************************/

#define FLASH_LOCK_KEY1				0x45670123
#define FLASH_LOCK_KEY2				0xCDEF89AB

#define FLASH_OPTION_BYTE_LOCK_KEY1				0x08192A3B
#define FLASH_OPTION_BYTE_LOCK_KEY2				0x4C5D6E7F


#define FLASH_WRITE_PROTECTION_ERROR_INDEX				0
#define FLASH_PROGRAM_ALIGNEMNT_ERROR_INDEx				1
#define FLASH_PROGRAM_PARALLELISM_ERROR_INDEx			2
#define FLASH_PROGRAM_SEQUANCE_ERROR_INDEx				3


/*
 * for configuration
 */

#define FLASH_VOLT_RANGE_1point8_TO_2point1								0
#define FLASH_VOLT_RANGE_2point1_TO_2point4								1
#define FLASH_VOLT_RANGE_2point4_TO_2point7								1
#define FLASH_VOLT_RANGE_2point7_TO_3point6								2
#define FLASH_VOLT_RANGE_2point7_TO_3point6_WTH_EXTERNAL_VPP			3


/********************************** Macros Function Declarations *********************/

#define Flash_Unlock()							do{\
													ASSIGN_REG((FLASH1->FLASH_KEYR),(FLASH_LOCK_KEY1)) ;\
													ASSIGN_REG((FLASH1->FLASH_KEYR),(FLASH_LOCK_KEY2)) ;\
											}while(ZERO_VALUE)


#define Flash_Lock()							(   SET_BIT( (FLASH1->FLASH_CR),THIRTYONE_VALUE )   )



#define Flash_SetProgramSize(_VALUE_)		( (  FLASH1->FLASH_CR ) = ((  FLASH1->FLASH_CR )&0xFFFFFCFF) | (((_VALUE_)<<EIGHT_VALUE ) &   0x300  )  )

#define Flash_IsFlashOperatingBusy()					(   READ_BIT( (FLASH1->FLASH_SR),THIRTYONE_VALUE )  == ONE_VALUE  )


#define Flash_SetEraseModeSectorx(_VALUE_)			do{\
															( (  FLASH1->FLASH_CR ) = ((  FLASH1->FLASH_CR )&0xFFFFFF07) | (((_VALUE_)<<THREE_VALUE ) &   0xF8  ) );\
															(   SET_BIT( (FLASH1->FLASH_CR),ONE_VALUE )   );\
														}while(ZERO_VALUE)

#define Flash_SetEraseModeBankx(_VALUE_)				(   SET_BIT( (FLASH1->FLASH_CR),_VALUE_ )  )


#define Flash_SetEraseModeMass()			do{\
															Flash_SetEraseModeBankx(TWO_VALUE) ;\
															Flash_SetEraseModeBankx(FIFTEEN_VALUE) ;\
														}while(ZERO_VALUE)


#define Flash_StartErasingAction()					do{\
													while(Flash_IsFlashOperatingBusy() ==ONE_VALUE );\
													(   SET_BIT( (FLASH1->FLASH_CR),SIXTEEN_VALUE )  ) ;\
													while(Flash_IsFlashOperatingBusy() ==ONE_VALUE );\
											}while(ZERO_VALUE)


#define Flash_GetOutOfEraseMode()					(   CLEAR_BIT( (FLASH1->FLASH_CR),ONE_VALUE )   )


#define Flash_SetFlashWritingMode()						(   SET_BIT( (FLASH1->FLASH_CR),ZERO_VALUE )  )
#define Flash_GetOutOfFlashWritingMode()						(   CLEAR_BIT( (FLASH1->FLASH_CR),ZERO_VALUE )  )

/* Error Part */

#define Flash_IsOperationErrorHappended()					(   READ_BIT( (FLASH1->FLASH_SR),ONE_VALUE )  == ONE_VALUE  )
#define Flash_ClearOperationErrorFlag()						(   SET_BIT( (FLASH1->FLASH_SR),ONE_VALUE ))


#define Flash_IsWriteProtoectionErrorHappended()					(   READ_BIT( (FLASH1->FLASH_SR),FOUR_VALUE )  == ONE_VALUE  )
#define Flash_ClearWriteProtoectionErrorFlag()						(   SET_BIT( (FLASH1->FLASH_SR),FOUR_VALUE ))


#define Flash_IsProgramAlignmentErrorHappended()					(   READ_BIT( (FLASH1->FLASH_SR),FIVE_VALUE )  == ONE_VALUE  )
#define Flash_ClearProgramAlignmentErrorFlag()						(   SET_BIT( (FLASH1->FLASH_SR),FIVE_VALUE ))


#define Flash_IsProgramParallelismErrorHappended()					(   READ_BIT( (FLASH1->FLASH_SR),SIX_VALUE )  == ONE_VALUE  )
#define Flash_ClearProgramParallelismErrorFlag()						(   SET_BIT( (FLASH1->FLASH_SR),SIX_VALUE ))

#define Flash_IsProgramSequenceErrorHappended()					(   READ_BIT( (FLASH1->FLASH_SR),SEVEN_VALUE )  == ONE_VALUE  )
#define Flash_ClearProgramSequenceErrorFlag()						(   SET_BIT( (FLASH1->FLASH_SR),SEVEN_VALUE ))

/* Enable / disable error interrupt */
#define Flash_EnableErrorInterrupt()						(   SET_BIT( (FLASH1->FLASH_CR),TWENTYFIVE_VALUE ))
#define Flash_DisableErrorInterrupt()						(   CLEAR_BIT( (FLASH1->FLASH_CR),TWENTYFIVE_VALUE ))

/* End of operation Flag, interrupt */

#define Flash_IsEndOfOperationrHappended()					(   READ_BIT( (FLASH1->FLASH_SR),ZERO_VALUE )  == ONE_VALUE  )
#define Flash_ClearEndOfOperationrFlag()						(   SET_BIT( (FLASH1->FLASH_SR),ZERO_VALUE ))


#define Flash_EnableEndOfOperationInterrupt()						(   SET_BIT( (FLASH1->FLASH_CR),FOURYFIVE_VALUE ))
#define Flash_DisableEndOfOperationInterrupt()						(   CLEAR_BIT( (FLASH1->FLASH_CR),FOURYFIVE_VALUE ))



#define Flash_EnablePrefetch()								(   SET_BIT( (FLASH1->FLASH_CR),EIGHT_VALUE ))
#define Flash_DisablePrefetch()								(   CLEAR_BIT( (FLASH1->FLASH_CR),EIGHT_VALUE ))

#define Flash_EnableInstructionCache()								(   SET_BIT( (FLASH1->FLASH_CR),NINE_VALUE ))
#define Flash_DisableInstructionCache()								(   CLEAR_BIT( (FLASH1->FLASH_CR),NINE_VALUE ))

#define Flash_EnableDataCache()								(   SET_BIT( (FLASH1->FLASH_CR),TEN_VALUE ))
#define Flash_DisableDataCache()								(   CLEAR_BIT( (FLASH1->FLASH_CR),TEN_VALUE ))

#define Flash_ResetInstrctionCache()							(   SET_BIT( (FLASH1->FLASH_CR),ELEVEN_VALUE ))
#define Flash_ResetDataCache()							(   SET_BIT( (FLASH1->FLASH_CR),TWELVE_VALUE ))



/********** Byte Options *****************************/

#define Flash_UnlockByteOption()							do{\
													ASSIGN_REG((FLASH1->FLASH_OPTKEYR),(FLASH_OPTION_BYTE_LOCK_KEY1)) ;\
													ASSIGN_REG((FLASH1->FLASH_OPTKEYR),(FLASH_OPTION_BYTE_LOCK_KEY2)) ;\
											}while(ZERO_VALUE)

#define Flash_LockByteOption()							(   SET_BIT( (FLASH1->FLASH_OPTCR[ZERO_VALUE]),ZERO_VALUE )   )

#define Flash_StartOptionByteAction()					do{\
													while(Flash_IsFlashOperatingBusy() ==ONE_VALUE );\
													(   SET_BIT( (FLASH1->FLASH_OPTCR[ZERO_VALUE]),ONE_VALUE )  ) ;\
													while(Flash_IsFlashOperatingBusy() ==ONE_VALUE );\
											}while(ZERO_VALUE)


#define Flash_WriteProtectionAtSectorx(_BANK_INDEX_, _SECTOR_NUMBER_)		(CLEAR_BIT( (FLASH1->FLASH_OPTCR[_BANK_INDEX_]) , (_SECTOR_NUMBER_+SIXTEEN_VALUE)))
#define Flash_StartWriteProtectionAction()									(   SET_BIT( (FLASH1->FLASH_OPTCR[ZERO_VALUE]),ONE_VALUE )  )

#define Flash_RemoveWriteProtectionAtSectorx(_BANK_INDEX_, _SECTOR_NUMBER_)		(SET_BIT( (FLASH1->FLASH_OPTCR[_BANK_INDEX_]) , (_SECTOR_NUMBER_+SIXTEEN_VALUE)))


/********************************** Software Interfaces Declarations *******************/




#endif /* FLASH_DRIVER_FLASH_DRIVER_PRIVATE_H_ */
