/*
 * DC.c
 *
 *  Created on: Dec 23, 2022
 *      Author: Ali Mohamed Taima
 */
#include "DC.h"
int DC_speed = 0;

void DC_init()
{
    // init PWM
    printf("DC_init \n"); 
}
void DC_motor(int s)
{
    DC_speed = s;
    DC_state = STATE(DC_busy);
    printf("CA -----------speeed = %d-------------> DC\n", DC_speed);

}
// State pointer to function
void(*DC_state)();
STATE_define(DC_idle)
{
	//state_Name
	DC_state_id = DC_idle;
	//State_Action
    // call PWM to make speed = DC_speed

    //DC_Motor(DC_speed)

	
	printf("DC_idle State: Speed = %d \n", DC_speed);
}
STATE_define(DC_busy)
{
    //state_Name
    DC_state_id = DC_busy;
    //State_Action
    //DC_Motor(DC_speed)
    // call PWM to make speed = DC_speed

    //DC_Motor(DC_speed)
    DC_state = STATE(DC_idle);
     
    printf("DC_busy State: Speed = %d \n", DC_speed);
    
}


