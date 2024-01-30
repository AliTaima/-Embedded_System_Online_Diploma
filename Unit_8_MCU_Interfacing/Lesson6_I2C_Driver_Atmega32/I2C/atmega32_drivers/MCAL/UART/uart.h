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


#define DefaultStop		'\r'

#define UART_RX_Interrupt_En	SET_PIN(UCSRB, 7) //Bit 7 – RXCIE:?RX Complete Interrupt Enable
#define UART_RX_Interrupt_Dis	CLR_PIN(UCSRB, 7) //Bit 7 – RXCIE:?RX Complete Interrupt Enable
#define UART_TX_Interrupt_En	SET_PIN(UCSRB, 6) //Bit 6 – TXCIE:?TX Complete Interrupt Enable
#define UART_TX_Interrupt_Dis	CLR_PIN(UCSRB, 6) //Bit 6 – TXCIE:?TX Complete Interrupt Enable



void UART_Init(void);
void UART_Send(char data);
char UART_Receive(void);
void UART_Send_Str(uint8_t* str);
void UART_Rec_Str(uint8_t* buf);
uint8_t UART_Rec_Periodic_Check(uint8_t* Pdata);

#endif /* UART_H_ */