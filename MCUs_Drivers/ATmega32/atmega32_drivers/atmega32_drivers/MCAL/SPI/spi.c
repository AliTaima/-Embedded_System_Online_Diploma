/*
 * spi.c
 *
 * Created: 1/23/2024 4:29:54 PM
 *  Author: Ali Mohamed Taima
 */ 
#include "spi.h"


void SPI_Master_Init(void)
{
	//set MOSI, CLK, SS as outputs 
	SPI_Dir |= (1<<MOSI) | (1<<CLK) | (1<<SS);
	//Set MISO as input
	SPI_Dir &= ~(1<<MISO);
	//write high on SS
	SPI_Port |= (1<<SS);
	//Enable SPI, Select Master mode, Divide fosc/16
	SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0);
	//make sure the reset values to make fosc/16
	//SPI2X | SPR1| SPR0 | SCK Frequency
	//0		|  0  |	1	 | fosc/16
	SPSR &= ~(1<<SPI2X);
	
}

void SPI_Master_Send(uint8_t data)
{
	uint8_t flush_buf;
	//write low on SS to enable sending
	SPI_Port &= ~(1<<SS);
	//write data to SPDR register
	SPDR = data;
	while(!READ_PIN(SPSR, SPIF));
	//the SPIF bit is cleared by first reading the SPI Status Register with SPIF
	//set, then accessing the SPI Data Register (SPDR)
	flush_buf = SPDR;
	//write high on SS
	SPI_Port |= (1<<SS);
}
uint8_t SPI_Master_Rec(void)
{
	while(!READ_PIN(SPSR, SPIF));
	return SPDR;
}
void SPI_Slave_Init(void)
{
	//set MISO as ouput
	SPI_Dir |= (1<<MISO);
	//set MOSI, CLK, SS as inputs
	SPI_Dir &= ~(1<<MOSI) & ~(1<<CLK) & ~(1<<SS);
	//Enable SPI and divide fosc/16
	SPCR |= (1<<SPE) | (1<<SPR0);
	//Slave mode
	SPCR &= ~(1<<MSTR);
}
uint8_t SPI_Slave_Rec(void)
{
	while(!READ_PIN(SPSR, SPIF));
	return SPDR;
}