/*
 * lcd.c
 *
 * Created: 12/23/2023 1:51:01 PM
 *  Author: Ali Mohamed Taima
 */ 
#include "lcd.h"
void LCD_Init(void)
{
	LCD_Control_Dir |= (1<<RS|1<<EN|1<<RW);//make control pins as output
	LCD_Control_Port &= (1<<RS|1<<EN|1<<RW); //make sure that output is 0
	_delay_ms(20);
	
	#ifdef EIGHT_BIT_MODE
	LCD_Send_A_Command(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_Send_A_Command(0x02); //Send for 4bit initialization of LCD
	LCD_Send_A_Command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	LCD_Send_A_Command(LCD_DISP_ON_CURSOR_BLINK);
	LCD_Send_A_Command(LCD_ENTRY_INC);	//Auto increment
	LCD_Send_A_Command(LCD_CLEAR_SCREEN);
	LCD_Send_A_Command(LCD_BEGIN_AT_FIRST_RAW);
}
void LCD_Send_A_Command(unsigned char command)
{
	#ifdef EIGHT_BIT_MODE
	LCD_Data_Port = command;
	LCD_Control_Port &= ~(1<<RS | 1<<RW);//command register
	LCD_Kick();
	_delay_ms(3);
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_Data_Port = (LCD_Control_Port & 0x0F) | (command & 0xF0);//Sending upper niblle
	LCD_Control_Port &= ~(1<<RS | 1<<RW);//command register
	LCD_Kick();
	_delay_us(200);
	LCD_Data_Port = (LCD_Control_Port & 0x0F) | (command << 4 );//Sending upper niblle
	LCD_Kick();
	_delay_ms(2);
	#endif
}
void LCD_Send_A_Character(unsigned char char_data)
{
	
	#ifdef EIGHT_BIT_MODE
	LCD_Data_Port = char_data;
	LCD_Control_Port |= (1<<RS); //Data register
	LCD_Control_Port &= ~(1<<RW);//write operation
	LCD_Kick();
	_delay_ms(1);
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_Data_Port = (LCD_Control_Port & 0x0F) | (char_data & 0xF0);//Sending upper niblle
	LCD_Control_Port |= (1<<RS); //Data register
	LCD_Control_Port &= ~(1<<RW);//write operation
	LCD_Kick();
	_delay_us(200);
	LCD_Data_Port = (LCD_Control_Port & 0x0F) | (char_data << 4 );//Sending upper niblle
	LCD_Kick();
	_delay_ms(2);
	#endif
	
	
}
void LCD_Send_A_String(unsigned char* str_data)
{
	int i;
	for(i = 0;str_data[i] != 0; i++)
	{
		LCD_Send_A_Character(str_data[i]);
	}
	
}

void LCD_Kick(void)
{
	/*Enable pulse*/
	LCD_Control_Port |= (1<<EN);// Enable High
	_delay_us(1);	//minimum delay of 450ns
	LCD_Control_Port &= ~(1<<EN);//Enable Low
}

