/*
 * spi.h
 *
 * Created: 1/23/2024 4:30:09 PM
 *  Author: Ali Mohamed Taima
 */ 


#ifndef SPI_H_
#define SPI_H_

// include register header
#include "../../Utilities/registers.h"
// include the types header
#include "../../Utilities/types.h"

#define SPI_Port		PORTB
#define SPI_Dir			DDRB
//pins numbers
#define MOSI				5
#define MISO				6
#define CLK					7
#define SS					4

void SPI_Master_Init(void);
void SPI_Master_Send(uint8_t data);
uint8_t SPI_Master_Rec(void);
void SPI_Slave_Init(void);
uint8_t SPI_Slave_Rec(void);

#endif /* SPI_H_ */