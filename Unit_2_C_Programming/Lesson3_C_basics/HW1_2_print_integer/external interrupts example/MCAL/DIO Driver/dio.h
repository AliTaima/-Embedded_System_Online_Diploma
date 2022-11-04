/*
 * dio.h
 *
 * Created: 9/12/2022 2:35:26 PM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef DIO_H_
#define DIO_H_
// include register header
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"
//set pin macro(make PIN_NO = 1)
#define SET_PIN(X, PIN_NO]) X |= (1<<PIN_NO)
// clear pin macro(make PIN_NO = 0)
#define CLR_PIN(X, PIN_NO]) X &= ~(1<<PIN_NO)
// toggle pin macro(make PIN_NO = 0 then PIN_NO = 1 and so on...)
#define TOGGLE_PIN(X, PIN_NO]) X ^= (1<<PIN_NO)


// all driver macros
// all driver function prototypes

void DIO_init(EN_port_t portNumber, EN_pin_t pinNumber, EN_direction_t direction);	// Initialize dio direction

void DIO_write(EN_port_t portNumber, EN_pin_t pinNumber, EN_value_t value);	// write data to dio

void DIO_toggle(EN_port_t portNumber, EN_pin_t pinNumber);	//toggle dio

void DIO_read(EN_port_t portNumber, EN_pin_t pinNumber, uint8_t *value);	//read dio

#endif /* DIO_H_ */