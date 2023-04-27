/*
 * state.h
 *
 *  Created on: Dec 24, 2022
 *      Author: Ali Mohamed Taima
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"

// Automatic STATE Function generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_


// states connection
void US_Set_distance(int d);
void DC_motor(int s);
#endif /* STATE_H_ */
