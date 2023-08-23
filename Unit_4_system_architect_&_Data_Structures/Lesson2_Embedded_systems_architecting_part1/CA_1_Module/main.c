/*
 * main.c
 *
 *  Created on: Dec 23, 2022
 *      Author: Ali Mohamed Taima
 */

#include "CA.h"

void setup()
{
	// init all the drivers
	// init IRQ ....
	// init HAL US_Drivier DC_Driver
	// init Block
	// Set States pointers for each Block
	CA_state = STATE(CA_waiting);
}

void main()
{
    volatile int d;
	setup();
	while (1)
	{
		// call state for each Block
		CA_state();
        for(d = 0;d<=1000;d++);
	}
}
