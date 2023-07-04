/*
 * button.c
 *
 * Created: 9/12/2022 8:37:15 PM
 *  Author: Ali Mohamed Taima
 */ 
#include "button.h"

//initialize
void Button_init(EN_port_t buttonPort, EN_pin_t buttonPin) // Button is an input device
{
	DIO_init(buttonPort, buttonPin, IN);
}

// get button status
void Button_get_state(EN_port_t buttonPort, EN_pin_t buttonPin, uint8_t *value)
{
	DIO_read(buttonPort, buttonPin, value);
}
