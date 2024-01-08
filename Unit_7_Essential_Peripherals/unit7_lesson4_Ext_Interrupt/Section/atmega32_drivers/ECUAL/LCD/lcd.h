/*
 * lcd.h
 *
 * Created: 12/23/2023 1:51:11 PM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../MCAL/Timer/timer.h"
#include "../../MCAL/DIO/dio.h"

#define LCD_Data_Port		PORTA
#define LCD_Data_Dir		DDRA
#define LCD_Control_Port	PORTB
#define LCD_Control_Dir		DDRB
#define EN					3
#define RW					2
#define RS					1


//To control four or eight bit modes
//#define	EIGHT_BIT_MODE
#define	FOUR_BIT_MODE


#define LCD_REGISTER_SELECT_PIN					(0)
#define LCD_READ_WRITE_PIN						(1)
#define LCD_ENABLE_PIN							(2)
#define	LCD_REGISTER_SELECT_ENABLE				(1)
#define LCD_REGISTER_SELECT_DISABLE				(0)
#define READ_FROM_LCD							(1)
#define WRITE_TO_LCD							(0)
#define LCD_ENABLE								(1)
#define LCD_DISABLE								(0)
#define LCD_FIRST_LINE							(0)
#define LCD_SECOND_LINE							(1)

#define LCD_FUNCTION_8BIT_2LINES				(0x38)
#define LCD_FUNCTION_4BIT_2LINES				(0x28)
#define LCD_MOVE_DISP_RIGHT						(0x1C)
#define LCD_MOVE_DISP_LEFT						(0x18)
#define LCD_MOVE_CURSOR_RIGHT					(0x14)
#define LCD_MOVE_CURSOR_LEFT					(0x10)
#define LCD_DISP_OFF							(0x08)
#define LCD_DISP_ON_CURSOR						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK				(0x0F)
#define LCD_DISP_ON_BLINK						(0x0D)
#define LCD_DISP_ON								(0x0C)
#define LCD_ENTRY_DEC   						(0x04)
#define LCD_ENTRY_DEC_SHIFT   					(0x05)
#define LCD_ENTRY_INC   						(0x06)
#define LCD_ENTRY_INC_SHIFT   					(0x07)
#define LCD_BEGIN_AT_FIRST_RAW					(0x80)
#define LCD_BEGIN_AT_SECOND_RAW					(0xC0)
#define LCD_CLEAR_SCREEN						(0x01)
#define LCD_ENTRY_MODE							(0x06)



void LCD_Init(void);
void LCD_Send_A_Command(unsigned char command);
void LCD_Send_A_Character(unsigned char char_data);
void LCD_Send_A_String(unsigned char* str_data);
void LCD_Kick(void);

#endif /* LCD_H_ */