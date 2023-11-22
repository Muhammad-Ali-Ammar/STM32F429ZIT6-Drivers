/**************************************************************************/
/* Filename						: NVIC_private.h                            */
/* Author  	    				: Muhammad Ammar                          */
/* Date 						: Nov 12, 2023  	           	 	       */
/* Version 	 					: V01                                     */
/* MicroController  			: STM32429 								   */
/**************************************************************************/


#ifndef NVIC_NVIC_PRIVATE_H_
#define NVIC_NVIC_PRIVATE_H_



/********************************** Includes *********************************************/



/********************************** Macros Declarations *******************************/

/* define Enable Register */
#define NVIC_ISER0 (*(volatile u32 *)(0xE000E100))
#define NVIC_ISER1 (*(volatile u32 *)(0xE000E104))
#define NVIC_ISER2 (*(volatile u32 *)(0xE000E108))
#define NVIC_ISER3 (*(volatile u32 *)(0xE000E10C))
#define NVIC_ISER4 (*(volatile u32 *)(0xE000E110))
#define NVIC_ISER5 (*(volatile u32 *)(0xE000E114))
#define NVIC_ISER6 (*(volatile u32 *)(0xE000E118))
#define NVIC_ISER7 (*(volatile u32 *)(0xE000E11C))


/* Define Disable Register */
#define NVIC_ICER0 (*(volatile u32 *)(0xE000E180))
#define NVIC_ICER1 (*(volatile u32 *)(0xE000E184))
#define NVIC_ICER2 (*(volatile u32 *)(0xE000E188))
#define NVIC_ICER3 (*(volatile u32 *)(0xE000E18C))
#define NVIC_ICER4 (*(volatile u32 *)(0xE000E190))
#define NVIC_ICER5 (*(volatile u32 *)(0xE000E194))
#define NVIC_ICER6 (*(volatile u32 *)(0xE000E198))
#define NVIC_ICER7 (*(volatile u32 *)(0xE000E19C))


/* Define Set Pending Flag Register */
#define NVIC_ISPR0 (*(volatile u32 *)(0xE000E200))
#define NVIC_ISPR1 (*(volatile u32 *)(0xE000E204))
#define NVIC_ISPR2 (*(volatile u32 *)(0xE000E208))
#define NVIC_ISPR3 (*(volatile u32 *)(0xE000E20C))
#define NVIC_ISPR4 (*(volatile u32 *)(0xE000E210))
#define NVIC_ISPR5 (*(volatile u32 *)(0xE000E214))
#define NVIC_ISPR6 (*(volatile u32 *)(0xE000E218))
#define NVIC_ISPR7 (*(volatile u32 *)(0xE000E21C))


/* Define Clear Pending Flag Register */
#define NVIC_ICPR0 (*(volatile u32 *)(0xE000E280))
#define NVIC_ICPR1 (*(volatile u32 *)(0xE000E284))
#define NVIC_ICPR2 (*(volatile u32 *)(0xE000E288))
#define NVIC_ICPR3 (*(volatile u32 *)(0xE000E28C))
#define NVIC_ICPR4 (*(volatile u32 *)(0xE000E290))
#define NVIC_ICPR5 (*(volatile u32 *)(0xE000E294))
#define NVIC_ICPR6 (*(volatile u32 *)(0xE000E298))
#define NVIC_ICPR7 (*(volatile u32 *)(0xE000E29C))


/* Define ACTIVE Flag Register */
#define NVIC_IABR0 (*(volatile u32 *)(0xE000E300))
#define NVIC_IABR1 (*(volatile u32 *)(0xE000E304))
#define NVIC_IABR2 (*(volatile u32 *)(0xE000E308))
#define NVIC_IABR3 (*(volatile u32 *)(0xE000E30C))
#define NVIC_IABR4 (*(volatile u32 *)(0xE000E310))
#define NVIC_IABR5 (*(volatile u32 *)(0xE000E314))
#define NVIC_IABR6 (*(volatile u32 *)(0xE000E318))
#define NVIC_IABR7 (*(volatile u32 *)(0xE000E31C))



/********************************** Macros Function Declarations *********************/


/********************************** Data Type Declarations ****************************/

static volatile u32* GlobalStatic_NvicIsrEnableArr[]={ &NVIC_ISER0, &NVIC_ISER1, &NVIC_ISER2, &NVIC_ISER3, &NVIC_ISER4, &NVIC_ISER5, &NVIC_ISER6, &NVIC_ISER7};
static volatile u32* GlobalStatic_NvicIsrDisableArr[]={ &NVIC_ICER0, &NVIC_ICER1, &NVIC_ICER2, &NVIC_ICER3, &NVIC_ICER4, &NVIC_ICER5, &NVIC_ICER6, &NVIC_ICER7};

static volatile u32* GlobalStatic_NvicPendingFlagSetArr[]={ &NVIC_ISPR0, &NVIC_ISPR1, &NVIC_ISPR2, &NVIC_ISPR3, &NVIC_ISPR4, &NVIC_ISPR5, &NVIC_ISPR6, &NVIC_ISPR7};
static volatile u32* GlobalStatic_NvicPendingFlagClearArr[]={ &NVIC_ICPR0, &NVIC_ICPR1, &NVIC_ICPR2, &NVIC_ICPR3, &NVIC_ICPR4, &NVIC_ICPR5, &NVIC_ICPR6, &NVIC_ICPR7};

static volatile u32* GlobalStatic_NvicActiveFlagArr[]={ &NVIC_IABR0, &NVIC_IABR1, &NVIC_IABR2, &NVIC_IABR3, &NVIC_IABR4, &NVIC_IABR5, &NVIC_IABR6, &NVIC_IABR7};


/********************************** Software Interfaces Declarations *******************/



#endif /* NVIC_NVIC_PRIVATE_H_ */
