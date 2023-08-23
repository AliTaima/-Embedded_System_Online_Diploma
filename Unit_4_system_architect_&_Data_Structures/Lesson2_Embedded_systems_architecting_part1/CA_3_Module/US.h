/*
 * US.h
 *
 *  Created on: Dec 23, 2022
 *      Author: Ali Mohamed Taima
 */

#ifndef US_H_
#define US_H_
#include "state.h"
enum
{
	US_busy
}US_state_id;

//State pointer to function
extern void(*US_state)();
//declare states functions US
STATE_define(US_busy);

// US intit function
void US_init();
// declare ultrasonic random function 
int US_Get_distance_random(int l, int r, int count);



#endif /* US_H_ */
