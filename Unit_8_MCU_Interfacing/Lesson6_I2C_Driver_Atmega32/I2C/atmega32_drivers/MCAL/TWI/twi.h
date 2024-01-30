/*
 * twi.h
 *
 * Created: 1/25/2024 4:13:03 PM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef TWI_H_
#define TWI_H_
// include register header
#include "../../Utilities/registers.h"
// include the types header
#include "../../Utilities/types.h"
#define F_CPU		1000000U
#define SCL_CLK			400000U
//I ignored the TWPS bits and I make it by my self
#define Prescalar_1		1
#define Prescalar_4		4
#define Prescalar_16	16
#define Prescalar_64	64
//decide the value of TWBR that will make desired SCL_CLK
//To decide the bit rate you need to know the SCL_CLK 
//and decide the pre-scalar that will be suitable with it
#define BIT_RATE(SCL_CLK_, Prescalar)	TWBR = (uint8_t)(((F_CPU/SCL_CLK_)-16)/(2*Prescalar))

//Table 74. Status Codes for Master Transmitter Mode
#define START_STATE					0x08
#define REPEATED_START_STATE		0x10
#define SLA_W_ACK_STATE				0x18
#define SLA_W_NOT_ACK_STATE			0x20
#define SLA_R_ACK_STATE				0x40
#define SLA_R_NOT_ACK_STATE			0x48
#define DATA_WRITE_ACK_STATE		0x28
#define DATA_WRITE_NACK_STATE		0x30
#define DATA_READ_ACK_STATE			0x50
#define DATA_READ_NACK_STATE		0x58

//For state
typedef enum state
{
	EVENT_OK, START_NOT_SENT, REPEATED_START_NOT_SENT, SLA_W_ACK_SENT, SLA_W_NOT_ACK_SENT,
	SLA_R_ACK_SENT, SLA_R_NOT_ACK_SENT,SLA_RW_FAILED, DATA_WRITE_ACK_SENT, DATA_WRITE_NACK_SENT, 
	DATA_WRITE_FAILED, DATA_READ_ACK_SENT, DATA_READ_NACK_SENT, DATA_READ_FAILED
}EN_state_t;
typedef enum RW
{
	READ, WRITE
}EN_RW_t;
typedef enum ACK_STATE
{
	ACK, NOT_ACK
}EN_ACK_STATE_t;
void TWI_Init(void);
EN_state_t TWI_Start(void);
EN_state_t TWI_Repeated_Start(void);
EN_state_t TWI_Address_Select(uint8_t address, EN_RW_t rw);
EN_state_t TWI_Data_Event(uint8_t *data, EN_RW_t rw, EN_ACK_STATE_t ack);
void TWI_Stop(void);

#endif /* TWI_H_ */