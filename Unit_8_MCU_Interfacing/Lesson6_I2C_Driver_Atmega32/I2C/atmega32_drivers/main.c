/*
 * atmega32_drivers.c
 *
 * Created: 11/29/2023 11:48:35 AM
 * Author : Ali Mohamed Taima
 */ 

#include "Application/application.h"
#define F_CPU		1000000U

//
int main(void)
{
	TWI_Init();
	uint8_t data;
	//Master Receive
	if(TWI_Start() == EVENT_OK)
	{
		if(TWI_Address_Select(0x10, READ) == SLA_R_ACK_SENT)
		{
			if(TWI_Data_Event(&data, READ, NOT_ACK) == DATA_READ_NACK_SENT)
			{
				TWI_Stop();
			}
		}
	}
	//Master Transmit
	if(TWI_Start() == EVENT_OK)
	{
		if(TWI_Address_Select(0x10, WRITE) == SLA_W_ACK_SENT)
		{
			if(TWI_Data_Event(&data, WRITE, ACK) == DATA_WRITE_NACK_SENT)
			{
				TWI_Stop();
			}
		}
	}
	while (1)
	{
		
	}
}

