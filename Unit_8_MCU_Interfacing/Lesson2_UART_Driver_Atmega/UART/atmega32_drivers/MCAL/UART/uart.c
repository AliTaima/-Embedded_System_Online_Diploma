/*
 * uart.c
 *
 * Created: 1/14/2024 2:59:39 PM
 *  Author: Ali Mohamed Taima
 */ 
#include "uart.h"


void UART_Init(void)
{
	//baud rate = 9600, clock = 8MHZ
	uint16_t baud_rate = 51;
	UBRRH = (uint8_t)(51>>8);
	UBRRL = (uint8_t)baud_rate;
	
	//Set frame format: Asynch, no-parity, 1-bit stop, 8-bit data
	SET_PIN(UCSRC, 7); //To enable writing to UCSRC reg.
	CLR_PIN(UCSRC, 6);//Asynch
	CLR_PIN(UCSRC, 5);//no parity
	CLR_PIN(UCSRC, 4);//no parity
	CLR_PIN(UCSRC, 3);//1-bit stop
	//8-bit data
	SET_PIN(UCSRC, 1);//UCSZ0
	SET_PIN(UCSRC, 2);//UCSZ1
	SET_PIN(UCSRB, 2);//UCSZ2

	//UART Enable 
	UCSRB |= ((1<<4) | (1<<3));//Enable RX-->4, TX-->3
	
}
void UART_Send(char data)
{
	while (!(UCSRA & (1<<5)));
	UDR = data;
	
}
char UART_Receive(void)
{
	while (!(UCSRA & (1<<7)));
	return UDR;
}