/**************************************************************************/
/* Filename						: NVIC.h                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 12, 2023  	           	 	         	 */ 
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/


#ifndef NVIC_NVIC_H_
#define NVIC_NVIC_H_



/********************************** Includes *********************************************/



/********************************** Macros Declarations *******************************/


/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/
typedef enum {
NVIC_WWDG,
NVIC_PVD,
NVIC_TAMPER_STAMP,
NVIC_RTC_WKUP,
NVIC_FLASH,
NVIC_RCC,
NVIC_EXTI0,
NVIC_EXTI1,
NVIC_EXTI2,
NVIC_EXTI3,
NVIC_EXTI4,
NVIC_DMA1_Stream0,
NVIC_DMA1_Stream1,
NVIC_DMA1_Stream2,
NVIC_DMA1_Stream3,
NVIC_DMA1_Stream4,
NVIC_DMA1_Stream5,
NVIC_DMA1_Stream6,
NVIC_ADC,

NVIC_CAN1_TX,
NVIC_CAN1_RX0,
NVIC_CAN1_RX1,
NVIC_CAN1_SCE,

NVIC_EXTI9_5,
NVIC_TIM1_BRK_TIM9,
NVIC_TIM1_UP_TIM10,
NVIC_TIM1_TRG_COM_TIM11,
NVIC_TIM1_CC,
NVIC_TIM2,
NVIC_TIM3,
NVIC_TIM4,
NVIC_I2C1_EV,
NVIC_I2C1_ER,
NVIC_I2C2_EV,
NVIC_I2C2_ER,
NVIC_SPI1,
NVIC_SPI2,
NVIC_USART1,
NVIC_USART2,
NVIC_USART3,
NVIC_EXTI15_10,
NVIC_RTC_Alarm,
NVIC_OTG_FS_WKUP,
NVIC_TIM8_BRK_TIM12,
NVIC_TIM8_TRG_TIM13,
NVIC_TIM8_TRG_COM_TIM1,
NVIC_TIM8_CC,
NVIC_DMA1_Stream7,

NVIC_FSMO,
NVIC_SDIO,
NVIC_TIM5,
NVIC_UART4,
NVIC_SPI3,
NVIC_JART5,
NVIC_TIM6_DAC,
NVIC_TIM7,
NVIC_DMA2_Stream0,
NVIC_DMA2_Stream1,
NVIC_DMA2_Stream2,
NVIC_DMA2_Stream3,
NVIC_DMA2_Stream4,
NVIC_ETH,
NVIC_WUKUP,
NVIC_CAN2_TX,
NVIC_CAN2_RX1,
NVIC_CAN2_RX0,
NVIC_CAN2_SCE,

NVIC_OTG_FS,
NVIC_DMA2_Stream5,
NVIC_DMA2_Stream6,
NVIC_DMA2_Stream7,
NVIC_UART6,
NVIC_I2C3_EV,
NVIC_I2C3_ER,
NVIC_OTG_HS_EP1_OUT,
NVIC_OTG_HS_EP1_IN,
NVIC_OTG_HS_WKUP,
NVIC_OTG_HS,
NVIC_DCMI,
NVIC_CRYP,
NVIC_HASH_RNG,
NVIC_FPU,
NVIC_UART7,
NVIC_UART8,
NVIC_SPI4,
NVIC_SPI5,
NVIC_SPI6,
NVIC_SAI1,
NVIC_LCD_TFT,
NVIC_LCD_TFT_ERROR,
NVIC_DMA2D
}Nvic_IndexPeripheralType;


typedef enum{
	NVIC_ACTIVE_FLAG_IS_NOT_ACTIVE,
	NVIC_ACTIVE_FLAG_IS_ACTIVE
}Nvic_ActiveFlagType;


typedef enum{
	NVIC_SELECT_GROUP_PRIORITY_16_AND_SUB_PRIORITY_ZERO,
	NVIC_SELECT_GROUP_PRIORITY_4_AND_SUB_PRIORITY_4= 0b100,
	NVIC_SELECT_GROUP_PRIORITY_2_AND_SUB_PRIORITY_8=0b110,
	NVIC_SELECT_GROUP_PRIORITY_ZERO_AND_SUB_PRIORITY_16=0b111
}Nvic_SelectGroupPrioiriesAndSubPrioiriesType;


typedef enum{
	NVIC_STATUS_FAIL,
	NVIC_STATUS_OK,
	NVIC_STATUS_NULL_POINTER_ADDRESS
}Nvic_ErrorStatusType;

/********************************** Software Interfaces Declarations *******************/



#endif /* NVIC_NVIC_H_ */
