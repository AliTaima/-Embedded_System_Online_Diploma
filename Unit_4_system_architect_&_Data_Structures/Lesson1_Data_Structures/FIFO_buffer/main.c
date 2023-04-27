/*
 * main.c
 *
 *  Created on: Jan 29, 2023
 *      Author: Ali Mohamed Taima
 */
#include "fifo.h"

int main()
{
	FIFO_Buf_t* FIFO_UART;
	element_type i, temp;
	if(FIFO_init(FIFO_UART, uart_buffer, (uint32_t)width1) == FIFO_no_error)
		printf("FIFO init ------------------ Done \n");
	// Enqueue elements
	for(i = 0; i<7; i++)
	{

		if(FIFO_enqueue(FIFO_UART, i) == FIFO_no_error)
			printf("FIFO enqueue (%x) ------------------ Done\n", i);
		else
		{
			printf("FIFO enqueue (%x) ------------------ Failed (FIFO is full) \n", i);
		}
	}
	// printing the FIFO elements
	FIFO_print(FIFO_UART);
	// dequeue 2 elements
	if(FIFO_dequeue(FIFO_UART, &temp) == FIFO_no_error)
		printf("FIFO dequeue (%x) -------------------- Done\n", temp);
	else
		printf("FIFO dequeue -------------------- Failed\n");
	if(FIFO_dequeue(FIFO_UART, &temp) == FIFO_no_error)
		printf("FIFO dequeue (%x) -------------------- Done\n", temp);
	else
		printf("FIFO dequeue -------------------- Failed\n");

	FIFO_print(FIFO_UART);


	return 0;
}

