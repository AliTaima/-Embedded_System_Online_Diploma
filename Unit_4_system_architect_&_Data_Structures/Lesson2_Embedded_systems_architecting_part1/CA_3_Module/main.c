/*
 * main.c
 *
 *  Created on: Dec 23, 2022
 *      Author: Ali Mohamed Taima
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	// init all the drivers
	// init IRQ ....
	// init HAL US_Drivier DC_Driver
	// init Block
	US_init();
	DC_init(); 
	// Set States pointers for each Block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);

}

void main()
{
    volatile int d;
	setup();
	while (1)
	{
		// call state for each Block
		US_state();
		CA_state();
		DC_state();

        for(d = 0;d<=1000;d++);
	}
}
