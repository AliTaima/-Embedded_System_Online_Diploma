/*
 * DIO.h
 *
 * Created: 9/14/2022 10:45:18 AM
 *  Author: Ali Mohamed Taima
 */

#ifndef DIO_H_
#define DIO_H_

// include register header
#include "../../Utilities/registers.h"
// include the types header
#include "../../Utilities/types.h"
// include interrupt header
#include "../INTERRUPT/interrupts.h"

/************************************************************************/
/*							Typedefs						            */
/************************************************************************/
// Direction define
typedef enum EN_direction_t
{
	IN,
	OUT
} EN_direction_t;
// Value define
typedef enum EN_value_t
{
	LOW,
	HIGH
} EN_value_t;
// PINs define
typedef enum EN_pin_t
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
} EN_pin_t;
// PORT define
typedef enum EN_port_t
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
} EN_port_t;



// all driver function prototypes

void DIO_init(EN_port_t portNumber, EN_pin_t pinNumber, EN_direction_t direction); // Initialize dio direction

void DIO_write(EN_port_t portNumber, EN_pin_t pinNumber, EN_value_t value); // write data to dio

void DIO_toggle(EN_port_t portNumber, EN_pin_t pinNumber); // toggle dio

void DIO_read(EN_port_t portNumber, EN_pin_t pinNumber, uint8_t *value); // read dio

#endif /* DIO_H_ */