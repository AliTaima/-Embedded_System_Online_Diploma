 /*
 * Stm32_F103x6.h
 *
 *  Created on: Feb 22, 2023
 *      Author: Ali Mohamed Taima
 */

#ifndef INC_STM32_F103X6_H_
#define INC_STM32_F103X6_H_

//-----------------------------
//Includes
//-----------------------------

#include <stdlib.h>
#include <stdint.h>
//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_Memory_BASE						0x08000000UL
#define System_Memory_BASE						0x1FFFF000UL
#define SRAM_BASE								0x20000000UL

#define Peripherals_BASE						0x40000000UL
#define Cortex_M3_Internal_Peripherals_BASE		0xE0000000UL
//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE 		0x40021000UL
//#define RCC_BASE 		(Peripherals_BASE+ 0x00021000UL)

//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//-------------GPIO-------------------
//A, B fully included in LQF48 Package
#define GPIOA_BASE 		0x40010800UL
#define GPIOB_BASE 		0x40010C00UL


//C, D partial included in LQF48 package
#define GPIOC_BASE 		0x40011000UL
#define GPIOD_BASE 		0x40011400UL
//E not included in LQF48 Package
#define GPIOE_BASE 		0x40011800UL

//------------------------------------
#define  EXTI_BASE		0x40010400UL
#define  AFIO_BASE		0x40010000UL

//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------

//===============================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
	volatile uint32_t AHBSTR;
	volatile uint32_t CFGR2;


}RCC_TypeDef;
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: EXTI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
			 uint32_t RESERVED0;//0x18
	volatile uint32_t MAPR2;//0x1C

}AFIO_TypeDef;
//===================================================

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-
//GPIO_TypeDef *GPIOA = (GPIO_TypeDef *)GPIOA_BASE;
//GPIO_TypeDef *GPIOA = GPIOA;
#define GPIOA		((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB		((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC		((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD		((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE		((GPIO_TypeDef *)GPIOE_BASE)

#define RCC			((RCC_TypeDef *)RCC_BASE)
#define EXTI		((EXTI_TypeDef *)EXTI_BASE)
#define AFIO		((AFIO_TypeDef *)AFIO_BASE)


//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
//GPIO
#define RCC_GPIOA_CLK_EN()		(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()		(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()		(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()		(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()		(RCC->APB2ENR |= 1<<6)
//AFIO
#define AFIO_GPIOE_CLK_EN()		(RCC->APB2ENR |= 1<<0)

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#endif /* INC_STM32_F103X6_H_ */
