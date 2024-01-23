/*
 * atmega32_drivers.c
 *
 * Created: 11/29/2023 11:48:35 AM
 * Author : Ali Mohamed Taima
 */ 

#include "Application/application.h"


int main(void)
{
	LCD_Init();

	UART_Init();
	//UART_Send('A');
	//UART_Send('B');
	//UART_Send('C');
	UART_Send_Str("Ali Taima");
	/* Replace with your application code */
	while (1)
	{
		//LCD_Send_A_Character(UART_Receive());
	}
}

