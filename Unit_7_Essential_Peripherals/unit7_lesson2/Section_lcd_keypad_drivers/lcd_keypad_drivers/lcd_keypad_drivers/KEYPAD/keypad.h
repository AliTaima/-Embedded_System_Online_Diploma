/*
 * keypad.h
 *
 * Created: 12/23/2023 1:51:22 PM
 *  Author: Ali Mohamed Taima
 */ 
// set pin macro(make PIN_NO = 1)
#define SET_PIN(X, PIN_NO) X |= (1 << PIN_NO)
// clear pin macro(make PIN_NO = 0)
#define CLR_PIN(X, PIN_NO) X &= ~(1 << PIN_NO)
// toggle pin macro(make PIN_NO = 0 then PIN_NO = 1 and so on...)
#define TOGGLE_PIN(X, PIN_NO) X ^= (1 << PIN_NO)
// get status of the pin(read pin) to see it high or low(X--> the value, Y--> the PIN_name)for example(*value, PINA, PIN4)
#define GET_STATE(X, Y, PIN_NO) X = (Y & (1 << PIN_NO)) >> PIN_NO

#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <avr/io.h>

#define KEYPAD_Port		PORTA
#define KEYPAD_Dir		DDRA
#define KEYPAD_Pin		PINA

#define R0		0
#define R1		1
#define R2		2
#define R3		3
#define C0		4
#define C1		5
#define C2		6
#define C3		7
void KEYPAD_Init(void);
char KEYPAD_Get_Char(void);







#endif /* KEYPAD_H_ */