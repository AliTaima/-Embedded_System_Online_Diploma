/*
 * CA.h
 *
 *  Created on: Dec 23, 2022
 *      Author: Ali Mohamed Taima
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
enum
{
	CA_waiting, CA_driving
}CA_state_id;

//State pointer to function
extern void(*CA_state)();
//declare states functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

// declare ultrasonic random function 
int US_Get_distance_random(int l, int r, int count);



#endif /* CA_H_ */
