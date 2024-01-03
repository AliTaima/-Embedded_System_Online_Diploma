/*
 * lcd_keypad_drivers.c
 *
 * Created: 12/23/2023 1:49:45 PM
 * Author : Ali Mohamed Taima
 */ 

#define F_CPU			1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "LCD/lcd.h"
#include "KEYPAD/keypad.h"

int main(void)
{
	char key_char;
	KEYPAD_Init();
	LCD_Init();
	//LCD_Send_A_Character('A');
	//LCD_Send_A_String("Ali Mohamed");
    while (1) 
    {
		key_char = KEYPAD_Get_Char();
		switch(key_char)
		{
			case '?':
				LCD_Send_A_Command(LCD_CLEAR_SCREEN);
				break;
			case 'N':
				break;
			default:
				LCD_Send_A_Character(key_char);
				break;
		}
		//LCD_Send_A_Character(key_char);
	
		
    }
}

