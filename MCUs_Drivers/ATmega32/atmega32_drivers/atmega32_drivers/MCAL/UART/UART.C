/*
 * UART.C
 *
 * Created: 5/9/2023 11:37:29 AM
 *  Author: Ali Mohamed Taima
 */ 
#include "UART.h"
void UART_Init(void)
{
	//baud rate
	UBRRL = 51;
		//normal mode
	CLR_PIN(UCSRA, U2X);
	//frame
		// NO parity
		// 8-bits is inite by default
	
	
	//Enable
	SET_BIT(UCSRB, TXEN);
	SET_BIT(UCSRB, RXEN);
}
void UART_Send(uint8_t data)
{
	
	while(!READ_BIT(UCSRA,UDRE));
	UDR = data;
	
}
uint8_t UART_Receive(void)
{
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}