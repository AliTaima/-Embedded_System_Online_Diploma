/*
 * CA.c
 *
 *  Created on: Dec 23, 2022
 *      Author: Ali Mohamed Taima
 */
#include "CA.h"
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;


void US_Set_distance(int d)
{
    CA_distance = d;
    // we should the state that will move to
    (CA_distance <= CA_threshold)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
    printf("US -----------distance = %d-------------> CA\n", CA_distance);
}

// State pointer to function
void(*CA_state)();
STATE_define(CA_waiting)
{
	//state_Name
	CA_state_id = CA_waiting;
    printf("CA_Waiting State: distance = %d Speed = %d \n", CA_distance, CA_speed);

	//State_Action
    CA_speed = 0;
    //DC_Motor(CA_speed)

    DC_motor(CA_speed);

	
}
STATE_define(CA_driving)
{
    //state_Name
    CA_state_id = CA_driving;
    printf("CA_Driving State: distance = %d Speed = %d \n", CA_distance, CA_speed);

    //State_Action
    CA_speed = 30;
    //DC_Motor(CA_speed)
    DC_motor(CA_speed);



}


