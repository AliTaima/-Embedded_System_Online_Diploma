/*
 * atmega32_drivers.c
 *
 * Created: 11/29/2023 11:48:35 AM
 * Author : Ali Mohamed Taima
 */ 

#include "Application/application.h"


int main(void)
{
	SPI_Master_Init();
	SPI_Master_Send('A');
	while (1)
	{
		//LCD_Send_A_Character(UART_Receive());
	}
}

