/*
 * application.h
 *
 * Created: 9/12/2022 7:09:19 PM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"

// define led1 port and pin
#define LED_1_PORT PORT_A
#define LED_1_PIN PIN0
// define led1 port and pin
#define LED_2_PORT PORT_A
#define LED_2_PIN PIN3
// define led1 port and pin
#define LED_3_PORT PORT_A
#define LED_3_PIN PIN7
// define button1 port  and pin
#define EXT_INT_BUTTON_PORT PORT_D
#define EXT_INT_BUTTON_PIN PIN2




void App_init(void);
void App_start(void);

#endif /* APPLICATION_H_ */