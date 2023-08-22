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
	lifo_buf_t uart_lifo, I2C_lifo;

	/*---------Dynamic allocation------------*/

	printf("-------Dynamic allocation------------\n\n");
	unsigned int* buffer2 = (unsigned int*)malloc(5 * sizeof(unsigned int)); //5*4 = 20 bytes
	// handling space
	if (lifo_init(&I2C_lifo, buffer2, 5) == lifo_null)
	{
		printf("There is no enough space!");
	}

	// Adding new item
	for (i = 0; i < 5; i++)
	{
		switch (lifo_add_item(&I2C_lifo, i))
		{
			// checking lifo is valid or not
		case lifo_null:
			printf("The lifo is not valid!");
			break;
			//checking lifo is full or not
		case lifo_full:
			printf("The lifo is full!");
			break;
		default:
			printf("UART_lifo add: %d \n", i);
			break;
		}
	}
	printf("\n\n");
	// Getting item
	for (i = 0; i < 5; i++)
	{
		switch (lifo_get_item(&I2C_lifo, &temp))
		{
			// checking lifo is valid or not
		case lifo_null:
			printf("The lifo is not valid!");
			break;
			//checking lifo is empty or not
		case lifo_empty:
			printf("The lifo is empty!");
			break;
		default:
			printf("UART_lifo add: %d \n", temp);
			break;
		}
	}
	/*---------Static allocation------------*/
	// Adding elements
	printf("-------Static allocation------------\n\n");
	lifo_init(&uart_lifo, buffer1, 5);
	for (i = 0; i < 5; i++)
	{
		if (lifo_add_item(&uart_lifo, i) == lifo_no_error)
			printf("UART_lifo add: %d \n", i);
	}
	printf("\n\n");
	// Getting elements
	for (i = 0; i < 5; i++)
	{
		if (lifo_get_item(&uart_lifo, &temp) == lifo_no_error)
			printf("UART_lifo get: %d \n", temp);

	}



	return 0;
}

