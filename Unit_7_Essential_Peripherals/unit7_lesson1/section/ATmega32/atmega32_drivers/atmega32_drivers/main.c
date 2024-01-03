/*
 * atmega32_drivers.c
 *
 * Created: 11/29/2023 11:48:35 AM
 * Author : Ali Mohamed Taima
 */ 

#include "Application/application.h"


int main(void)
{
	DDRC = 0xff;
	//SET_PIN(PORTC, 2);
	int i, j;
    /* Replace with your application code */
    while (1) 
    {
		for(i = 0; i<10; i++)
		{
			PORTC = 0b0100|(i<<4);
			
			_delay_ms(3000);
		}
			
   
	} 
}

