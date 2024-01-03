/*
 * Section_Atmega32_ext_interrupt.c
 *
 * Created: 11/29/2023 12:00:24 PM
 * Author : Ali Mohamed Taima
 */ 

#include "Application/application.h"

int main(void)
{
	//make pin(5, 6, 7) as output in PORTD
	DDRD |= (0b111 << 5);
	//INT0 occurs when "any logical change"
	MCUCR |= (0b01 << 0); 
	// INT1 occurs when "rising edge"
	MCUCR |= (0b11 << 2);
	// INT2 occurs when "Falling edge"
	CLR_PIN(MCUCSR, 6);
	//Enable all external interrupts
	GICR |= (0b111<<5);
	//Enable global interrupt
	sei();
    /* Replace with your application code */
    while (1) 
    {
		CLR_PIN(PORTD, 5);
		CLR_PIN(PORTD, 6);
		CLR_PIN(PORTD, 7);
		
    }
}

ISR(EXT_INT_0)
{
	SET_PIN(PORTD, 5);
	delay_5s();
	
}
ISR(EXT_INT_1)
{
	SET_PIN(PORTD, 6);
	delay_5s();
}
ISR(EXT_INT_2)
{
	SET_PIN(PORTD, 7);
	delay_5s();
	
}