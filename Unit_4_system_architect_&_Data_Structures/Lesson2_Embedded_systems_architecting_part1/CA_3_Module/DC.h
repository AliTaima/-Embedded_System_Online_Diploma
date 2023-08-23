/*
 * DC.h
 *
 *  Created on: Dec 23, 2022
 *      Author: Ali Mohamed Taima
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"
enum
{
	DC_idle, DC_busy
}DC_state_id;

//State pointer to function
extern void(*DC_state)();
//declare states functions DC
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();



#endif /* DC_H_ */
