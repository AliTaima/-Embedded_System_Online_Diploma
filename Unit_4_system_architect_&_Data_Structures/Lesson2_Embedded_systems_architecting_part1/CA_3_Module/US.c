/*
 * US.c
 *
 *  Created on: Dec 23, 2022
 *      Author: Ali Mohamed Taima
 */
#include "US.h"
int US_distance = 0;

void US_init()
{
    // init ultrasonic drivers
    printf("US_init \n");
}

// State pointer to function
void(*US_state)();
STATE_define(US_busy)
{
	//state_Name
	US_state_id = US_busy;
	//State_Action
    US_distance = US_Get_distance_random(45, 55, 1);
	
	printf("US_Wainting State: distance = %d \n", US_distance, US_distance);
    US_Set_distance(US_distance);
    US_state = STATE(US_busy);
}


int US_Get_distance_random(int l, int r, int count)
{

    // this will generate rnadom number in range 1 to r
    int i;
    for(i = 0; i < count; i++)
    {
        int rand_num = (rand() % (r - 1 + 1)) + 1;
        return rand_num;
    }
    
}
