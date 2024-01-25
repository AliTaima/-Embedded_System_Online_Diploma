/*
 * keypad.h
 *
 * Created: 12/23/2023 1:51:22 PM
 *  Author: Ali Mohamed Taima
 */ 

#include "../../MCAL/DIO/dio.h"

#ifndef KEYPAD_H_
#define KEYPAD_H_

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