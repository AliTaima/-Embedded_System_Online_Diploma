/*
 * UART.h
 *
 * Created: 5/9/2023 11:37:46 AM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef UART_H_
#define UART_H_
// include register header
#include "../../Utilities/registers.h"
// include the types header
#include "../../Utilities/types.h"
#include "../../MCAL/DIO/dio.h"

void UART_Init(void);
void UART_Send(uint8_t data);
uint8_t UART_Receive(void);
//UCSRB pins
#define TXB8	0
#define RXB8	1
#define UCSZ2	2
#define TXEN	3
#define RXEN	4
#define UDRIE	5
#define TXCIE	6
#define RXCIE	7
//UCSRA pins
#define MPCM	0
#define U2X		1
#define PE		2
#define DOR		3
#define FE		4
#define UDRE	5
#define TXC		6
#define RXC		7
       

       


#endif /* UART_H_ */