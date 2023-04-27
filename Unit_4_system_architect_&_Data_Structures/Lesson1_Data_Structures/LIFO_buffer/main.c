/*
 * main.c
 *
 *  Created on: Jan 28, 2023
 *      Author: Ali Mohamed Taima
 */
#include "lifo.h"

unsigned int buffer1[5];

int main()
{
	int i;
	unsigned int temp = 0;
	LIFO_Buf_t uart_lifo, I2C_lifo;

	/*---------Dynamic allocation------------*/

	printf("-------Dynamic allocation------------\n\n");
	unsigned int* buffer2 = (unsigned int*) malloc(5 * sizeof(unsigned int));
	// handling space
	if(LIFO_init(&I2C_lifo, buffer2, 5) == LIFO_Null)
	{
		printf("There is no enough space!");
	}

	// Adding new item
	for(i = 0; i<5; i++)
	{
		switch(LIFO_Add_item(&I2C_lifo, i))
		{
		// checking LIFO is valid or not
		case LIFO_Null:
			printf("The LIFO is not valid!");
			break;
			//checking LIFO is full or not
		case LIFO_full:
			printf("The LIFO is full!");
			break;
		default:
			printf("UART_LIFO add: %d \n", i);
			break;
		}
	}
	printf("\n\n");
	// Getting item
	for(i = 0; i<5; i++)
	{
		switch(LIFO_get_item(&I2C_lifo, &temp))
		{
		// checking LIFO is valid or not
		case LIFO_Null:
			printf("The LIFO is not valid!");
			break;
			//checking LIFO is empty or not
		case LIFO_empty:
			printf("The LIFO is empty!");
			break;
		default:
			printf("UART_LIFO add: %d \n", temp);
			break;
		}
	}
	/*---------Static allocation------------*/
	// Adding elements
	printf("-------Static allocation------------\n\n");
	LIFO_init(&uart_lifo, buffer1, 5);
	for(i = 0; i<5; i++)
	{
		if(LIFO_Add_item(&uart_lifo, i) == LIFO_no_error)
			printf("UART_LIFO add: %d \n", i);
	}
	printf("\n\n");
	// Getting elements
	for(i = 0; i<5; i++)
	{
		if(LIFO_get_item(&uart_lifo, &temp) == LIFO_no_error)
			printf("UART_LIFO get: %d \n", temp);

	}



	return 0;
}

