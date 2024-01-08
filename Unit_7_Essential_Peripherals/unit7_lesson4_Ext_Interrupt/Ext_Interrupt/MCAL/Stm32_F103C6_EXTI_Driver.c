/*
 * Stm32_F103C6_GPIO_Driver.c
 *
 *  Created on: Feb 22, 2023
 *      Author: Ali Mohamed Taima
 */

#include "Stm32_F103C6_GPIO_Driver.h"
#include "Stm32_F103C6_EXTI_Driver.h"


/**
 * =================================================================
 * 					Generic Variables
 * =================================================================
 */
void(* GP_IRQ_CallBack[15])(void);

/**
 * =================================================================
 * 					Generic Macros
 * =================================================================
 */
#define AFIO_GPIO_EXTI_Mapping(x)		((x == GPIOA)?0:\
										(x == GPIOB)?1:\
										(x == GPIOC)?2:\
										(x == GPIOD)?3:0)

/**
 * =================================================================
 * 					Generic Functions
 * =================================================================
 */
void Enalbe_NVIC(uint16_t IRQ)
{
	switch(IRQ)
	{
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;

	}
}
void Disalbe_NVIC(uint16_t IRQ)
{
	switch(IRQ)
		{
		case 0:
			NVIC_IRQ6_EXTI0_Disable;
			break;
		case 1:
			NVIC_IRQ7_EXTI1_Disable;
			break;
		case 2:
			NVIC_IRQ8_EXTI2_Disable;
			break;
		case 3:
			NVIC_IRQ9_EXTI3_Disable;
			break;
		case 4:
			NVIC_IRQ10_EXTI4_Disable;
			break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			NVIC_IRQ23_EXTI5_9_Disable;
			break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			NVIC_IRQ40_EXTI10_15_Disable;
			break;

		}
}

void Update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	// 1- Configure GPIO to be AF input --> Floating input
	GPIO_PinConfig_t PinCfg;
	// Update the GPIO Pin to be floating input
	PinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &PinCfg);
	//=======================================================
	// 2- Update AFIO To Route between EXTI line with PORT A, B, C, D
	uint8_t AFIO_EXICR_Index = EXTI_Config->EXTI_PIN.EXT_InputNumber/4;
	uint8_t AFIO_EXICR_Position = (EXTI_Config->EXTI_PIN.EXT_InputNumber % 4)* 4;
	// Clear the four bit
	AFIO->EXTICR[AFIO_EXICR_Index] &= ~(0xf << AFIO_EXICR_Position);
	AFIO->EXTICR[AFIO_EXICR_Index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port)& 0xF) << AFIO_EXICR_Position);
	//=============================================================
	//3- Update Rising or falling Register
	EXTI->RTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXT_InputNumber);
	EXTI->FTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXT_InputNumber);
	if(EXTI_Config->Trigger_Case == EXTI_Trigger_RISING)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXT_InputNumber);
	}else if(EXTI_Config->Trigger_Case == EXTI_Trigger_FALLING)
	{
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXT_InputNumber);

	}else if(EXTI_Config->Trigger_Case == EXTI_Trigger_RisingAndFaling)
	{
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXT_InputNumber);
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXT_InputNumber);
	}
	//=============================================================
	//4- Update IRQ Handling CallBack
	GP_IRQ_CallBack[EXTI_Config->EXTI_PIN.EXT_InputNumber] = EXTI_Config->P_IRQ_CallBack;
	//=============================================================
	//5- Enable/Disable EXTI & NVIC
	if(EXTI_Config->IRQ_EN == EXTI_IRQ_Enable)
	{
		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.EXT_InputNumber);
		Enalbe_NVIC(EXTI_Config->EXTI_PIN.EXT_InputNumber);
	}else
	{
		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.EXT_InputNumber);
		Disalbe_NVIC(EXTI_Config->EXTI_PIN.EXT_InputNumber);
	}
}

/**
 * =================================================================
 * 					APIs Functions Definitions
 * =================================================================
 */

/**================================================================
 * @Fn			- MCAL_EXTI_GPIO_DeInit
 * @brief 		- Reset EXTI Registers and NVIC corresponding IRQ Mask
 * @retval		-none
 * Note			-none
 */
void MCAL_EXTI_GPIO_DeInit(void)
{
	// The reset register in RCC doesn't reset the EXTI
	// So we need to reset it manually
	EXTI->IMR 	= 0x00000000;
	EXTI->EMR 	= 0x00000000;
	EXTI->RTSR 	= 0x00000000;
	EXTI->FTSR 	= 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR 	= 0xFFFFFFFF; //rc_w -->cleared by writing a ‘1’ into the bit

	// Disable EXTI IRQ From NVIC
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;
}
/*
 * The MCAL_EXTI_GPIO_Init and MCAL_EXTI_GPIO_Update are the same implementation
 * but there is no meaning to call MCAL_EXTI_GPIO_Init during the running of the program, so I make the MCAL_EXTI_GPIO_Update function
 * As a result I don't want to duplicate my code in each of them, so I will make private fun (Update_EXTI)and call it inside them
 */
/**================================================================
 * @Fn			- MCAL_EXTI_GPIO_Init
 * @brief 		-This is used to initialize from specific GPIO PIN and specify the Mask/Trigger condition and IRQ CallBack
 * @param [in] 	- EXTI_Config set by @ref_EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @retval		-none
 * Note			- STM32F103C6 MCU has GPIO A, B, C, D, E Modules
 * 				but LQFP48 package has only GPIO A,B,C Part of C/D exported as external PINS from MCU
 * 				- Also Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
 */

void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}
/**================================================================
 * @Fn			- MCAL_EXTI_GPIO_Update
 * @brief 		-This is used to initialize from specific GPIO PIN and specify the Mask/Trigger condition and IRQ CallBack
 * @param [in] 	- EXTI_Config set by @ref_EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @retval		-none
 * Note			- STM32F103C6 MCU has GPIO A, B, C, D, E Modules
 * 				but LQFP48 package has only GPIO A,B,C Part of C/D exported as external PINS from MCU
 * 				- Also Mandatory to Enable RCC Clock for AFIO and the corresponding GPIO
 */

void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config)
{
	Update_EXTI(EXTI_Config);
}



/**
 * =================================================================
 * 					ISR Functions
 * =================================================================
 */
void EXTI0_IRQHandler(void)
{
	//Pending Register --> cleared by writing a '1' into it
	EXTI->PR |= 1<<0;
	//Call IRQ_CALL
	GP_IRQ_CallBack[0]();
}
void EXTI1_IRQHandler(void)
{
	//Pending Register --> cleared by writing a '1' into it
	EXTI->PR |= 1<<0;
	//Call IRQ_CALL
	GP_IRQ_CallBack[0]();
}
void EXTI2_IRQHandler(void)
{
	//Pending Register --> cleared by writing a '1' into it
	EXTI->PR |= 1<<0;
	//Call IRQ_CALL
	GP_IRQ_CallBack[0]();
}
void EXTI3_IRQHandler(void)
{
	//Pending Register --> cleared by writing a '1' into it
	EXTI->PR |= 1<<0;
	//Call IRQ_CALL
	GP_IRQ_CallBack[0]();
}
void EXTI4_IRQHandler(void)
{
	//Pending Register --> cleared by writing a '1' into it
	EXTI->PR |= 1<<0;
	//Call IRQ_CALL
	GP_IRQ_CallBack[0]();
}
void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR & 1<<5)		{EXTI->PR |= (1<<5)		; GP_IRQ_CallBack[5]();}
	if(EXTI->PR & 1<<6)		{EXTI->PR |= (1<<6)		; GP_IRQ_CallBack[6]();}
	if(EXTI->PR & 1<<7)		{EXTI->PR |= (1<<7)		; GP_IRQ_CallBack[7]();}
	if(EXTI->PR & 1<<8)		{EXTI->PR |= (1<<8)		; GP_IRQ_CallBack[8]();}
	if(EXTI->PR & 1<<9)		{EXTI->PR |= (1<<9)		; GP_IRQ_CallBack[9]();}
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR & 1<<10)	{EXTI->PR |= (1<<10)	; GP_IRQ_CallBack[10]();}
	if(EXTI->PR & 1<<11)	{EXTI->PR |= (1<<11)	; GP_IRQ_CallBack[11]();}
	if(EXTI->PR & 1<<12)	{EXTI->PR |= (1<<12)	; GP_IRQ_CallBack[12]();}
	if(EXTI->PR & 1<<13)	{EXTI->PR |= (1<<13)	; GP_IRQ_CallBack[13]();}
	if(EXTI->PR & 1<<14)	{EXTI->PR |= (1<<14)	; GP_IRQ_CallBack[14]();}
	if(EXTI->PR & 1<<15)	{EXTI->PR |= (1<<15)	; GP_IRQ_CallBack[15]();}

}


