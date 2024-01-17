/*
 * uart.h
 *
 * Created: 1/14/2024 2:59:54 PM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef UART_H_
#define UART_H_
// include register header
#include "../../Utilities/registers.h"
// include the types header
#include "../../Utilities/types.h"
// include interrupt header
#include "../INTERRUPT/interrupts.h"

void UART_Init(void);
void UART_Send(char data);
char UART_Receive(void);



#endif /* UART_H_ */