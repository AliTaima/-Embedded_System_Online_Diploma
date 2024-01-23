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
	while (!READ_PIN(UCSRA, 7));
	return UDR;
}

void UART_Send_Str(uint8_t* str)
{
	uint8_t i;
	for(i = 0;i<str[i];i++)
	{
		UART_Send(str[i]);
	}
	UART_Send(DefaultStop);
}

void UART_Rec_Str(uint8_t* buf)
{
	 uint8_t i = 0;
	 buf[i] = UART_Receive();
	 while(buf[i] != DefaultStop)
	 {
		 i++;
		 buf[i] = UART_Receive();
	 }
	 buf[i] = '\0';
}

uint8_t UART_Rec_Periodic_Check(uint8_t* Pdata) 
{
	//this func will help us to make other things 
	//while there is no data on the rx, so we can check every 
	//some period of time
	if(READ_PIN(UCSRA, 7))
	{
		*Pdata = UDR;
		return 1;
	}
	return 0;
}

void UART_Send_NoBlock(uint8_t data)
{
	UDR = data;
}

uint8_t UART_Rec_NoBlock(void)
{
	return UDR ;
}
