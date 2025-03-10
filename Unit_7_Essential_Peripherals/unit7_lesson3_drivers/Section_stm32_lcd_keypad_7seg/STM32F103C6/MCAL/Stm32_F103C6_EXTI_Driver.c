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
void Update_EXTI(EXTI_PinConfig_t* EXTI_Config)
{
	// 1- Configure GPIO to be AF input --> Floating input
	GPIO_PinConfig_t PinCfg;
	// Update the GPIO Pin to be floating input
	PinCfg.GPIO_PinNumber = EXTI_Config->EXTI_PIN.GPIO_PIN;

	//=======================================================
	// 2- Update AFIO To Route between EXTI line wiht PORT A, B, C, D
	uint8_t AFIO_EXICR_Index = EXTI_Config->EXTI_PIN.EXT_InputNumber/4;
	uint8_t AFIO_EXICR_Position = (EXTI_Config->EXTI_PIN.EXT_InputNumber % 4)* 4;
	// Clear the four bit
	AFIO->EXTICR[AFIO_EXICR_Index] &= ~(0xf << AFIO_EXICR_Position);
	AFIO->EXTICR[AFIO_EXICR_Index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port)& 0xF) << AFIO_EXICR_Position);
}

/**
 * =================================================================
 * 					APIs Functions Definitions
 * =================================================================
 */
/**================================================================
 * @Fn			- MCAL_GPIO_LockPin
 * @brief 		- The locking mechanism allows the IO configuration to be forzen
 * @param [in] 	-GPIOx: Where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 	-Value: Specifies the port bit to read according @ref GPIO_PIN_define
 * @retval		-OK if pin config is locked OR ERROR if pin not locked (OK & ERROR are defined @ref GPIO_RETURN_LOCK
 * Note			-none
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
