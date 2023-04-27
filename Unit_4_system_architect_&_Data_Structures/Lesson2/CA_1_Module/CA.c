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

// State pointer to function
void(*CA_state)();
STATE_define(CA_waiting)
{
	//state_Name
	CA_state_id = CA_waiting;
	//State_Action
	CA_speed = 0;
    //DC_Motor(CA_speed)

	//Event_Check
    //US_Get_distance(CA_distance)
    CA_distance = US_Get_distance_random(45, 55, 1);
	(CA_distance <= CA_threshold)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
	printf("CA_Wainting State: distance = %d Speed = %d \n", CA_distance, CA_speed);
}
STATE_define(CA_driving)
{
    //state_Name
    CA_state_id = CA_driving;
    //State_Action
    //DC_Motor(CA_speed)

    CA_speed = 30;
    //Event_Check
    //US_Get_distance(CA_distance)
    CA_distance = US_Get_distance_random(45, 55, 1);

    (CA_distance <= CA_threshold)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
    printf("CA_Driving State: distance = %d Speed = %d \n", CA_distance, CA_speed);
}

int US_Get_distance_random(int l, int r, int count)
{

    // this wil generate rnadom number in range 1 to r
    int i;
    for(i = 0; i < count; i++)
    {
        int rand_num = (rand() % (r - 1 + 1)) + 1;
        return rand_num;
    }
    
}
