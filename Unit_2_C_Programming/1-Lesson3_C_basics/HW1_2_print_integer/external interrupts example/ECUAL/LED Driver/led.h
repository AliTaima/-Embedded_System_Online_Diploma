/*
 * led.h
 *
 * Created: 9/12/2022 6:10:15 PM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef LED_H_
#define LED_H_
/************************************************************************/
/* Led driver in upper layer, so we include DIO driver(from low layer) inside it */
/************************************************************************/
#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt library/interrupts.h"


//functions prototypes
void LED_init(EN_port_t ledPort, EN_pin_t ledPin);
void LED_on(EN_port_t ledPort, EN_pin_t ledPin);
void LED_off(EN_port_t ledPort, EN_pin_t ledPin);
void LED_toggle(EN_port_t ledPort, EN_pin_t ledPin);



#endif /* LED_H_ */