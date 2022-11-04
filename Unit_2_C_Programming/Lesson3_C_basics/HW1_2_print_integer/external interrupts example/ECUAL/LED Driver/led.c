/*
 * led.c
 *
 * Created: 9/12/2022 6:10:25 PM
 *  Author: Ali Mohamed Taima
 */ 
#include "led.h"
void LED_init(EN_port_t ledPort, EN_pin_t ledPin)
{
	//led is output
	DIO_init(ledPort, ledPin, OUT);
}
void LED_on(EN_port_t ledPort, EN_pin_t ledPin)
{
	DIO_write(ledPort, ledPin, HIGH);
}
void LED_off(EN_port_t ledPort, EN_pin_t ledPin)
{
	DIO_write(ledPort, ledPin, LOW);
}
void LED_toggle(EN_port_t ledPort, EN_pin_t ledPin)
{
	DIO_toggle(ledPort, ledPin);
}