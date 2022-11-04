/*
 * button.h
 *
 * Created: 9/12/2022 8:37:27 PM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt library/interrupts.h"


//functions prototypes
//initialize
void Button_init(EN_port_t buttonPort, EN_pin_t buttonPin);

// get button status
void Button_get_state(EN_port_t buttonPort, EN_pin_t buttonPin, uint8_t *value);


#endif /* BUTTON_H_ */