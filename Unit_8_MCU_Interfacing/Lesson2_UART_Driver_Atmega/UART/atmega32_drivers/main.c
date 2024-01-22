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
	//LCD_Send_A_String("ALI");
	UART_Init();
	UART_Send('A');
	UART_Send('B');
	UART_Send('C');
	/* Replace with your application code */
	while (1)
	{
		LCD_Send_A_Character(UART_Receive());
	}
}

