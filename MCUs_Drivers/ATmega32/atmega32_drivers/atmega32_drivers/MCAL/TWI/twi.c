/*
 * twi.c
 *
 * Created: 1/25/2024 4:12:50 PM
 *  Author: Ali Mohamed Taima
 */ 
#include "twi.h"
uint8_t status;
void TWI_Init(void)
{
	TWSR = 0x00; //Clear status register
	BIT_RATE(SCL_CLK, Prescalar_1); //set the bit rate
}
EN_state_t TWI_Start(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	status = TWSR & 0xF8;
	if (status != START_STATE)
	{
		return START_NOT_SENT;
	}
	else
	{
		return EVENT_OK;
	}
}
EN_state_t TWI_Repeated_Start(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
	status = TWSR & 0xF8;
	if (status != REPEATED_START_STATE)
	{
		return REPEATED_START_NOT_SENT;
	}
	else
	{
		return EVENT_OK;
	}
	
}
EN_state_t TWI_Address_Select(uint8_t address, EN_RW_t rw)
{
	if (rw == READ)
	{
		TWDR = address + 1;
	}
	else if (rw == WRITE)
	{
		TWDR = address + 0;
	}
	TWCR = (1<<TWINT) | (1<<TWEN) ; //I should write on TWDR before clear flag 
	while(!(TWCR & (1<<TWINT)));
	status = TWSR & 0xF8;
	if(status == SLA_W_ACK_STATE)
	{
		return SLA_W_ACK_SENT;
	}
	else if(status == SLA_W_NOT_ACK_STATE)
	{
		return SLA_W_NOT_ACK_SENT;
	}
	else if(status == SLA_R_ACK_STATE)
	{
		return SLA_R_ACK_SENT;
	}
	else if(status == SLA_R_NOT_ACK_STATE)
	{
		return SLA_R_NOT_ACK_SENT;
	}
	else
		return SLA_RW_FAILED;
	
}
EN_state_t TWI_Data_Event(uint8_t *data, EN_RW_t rw, EN_ACK_STATE_t ack)
{
	if(rw == WRITE)
	{
		TWDR = *data;
		TWCR = (1<<TWINT) | (1<<TWEN);
		while(!(TWCR & (1<<TWINT)));
		status = TWSR & 0xF8;
		if (status == DATA_WRITE_ACK_STATE)
		{
			return DATA_WRITE_ACK_SENT;
		} 
		else if(status == DATA_WRITE_ACK_STATE)
		{
			return DATA_WRITE_NACK_SENT;
		}
		else
			return DATA_WRITE_FAILED;
	}
	else if(rw == READ)
	{
		if(ack == ACK)
		{
			TWCR = (1<<TWEN) | (1<<TWINT) | (1<<TWEA);/* Enable TWI, generation of ack*/
		}
		else if(ack == ACK)
		{
			TWCR = (1<<TWEN) | (1<<TWINT);/* Enable TWI, no ack*/
		}
		while(!(TWCR & (1<<TWINT))); //Wait until TWI finish its current job
		*data = TWDR;	//Read Data
		status = TWSR & 0xF8;
		if (status == DATA_READ_ACK_STATE)
		{
			return DATA_READ_ACK_SENT;
		}
		else if(status == DATA_READ_ACK_STATE)
		{
			return DATA_READ_NACK_SENT;
		}
		else
			return DATA_READ_FAILED;
		
	}
	
}
void TWI_Stop(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN); //Enable TWI, Generate stop
	while(!(TWCR & (1<<TWINT))); //Wait until stop condition execution
		
}

