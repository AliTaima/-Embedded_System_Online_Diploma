/*
 * main.c
 *
 *  Created on: Jan 29, 2023
 *      Author: Ali Mohamed Taima
 */
#include "fifo.h"

int main()
{
	fifo_Buf_t fifo_UART;
	
	element_type i, temp;
	if (fifo_init(&fifo_UART, uart_buffer, (uint32_t)width1) == fifo_no_error)
		printf("fifo init ------------------ Done \n");
	// Enqueue elements
	for (i = 0; i < 7; i++)
	{

		if (fifo_enqueue(&fifo_UART, i) == fifo_no_error)
			printf("FIFO enqueue (%x) ------------------ Done\n", i);
		else
		{
			printf("FIFO enqueue (%x) ------------------ Failed (FIFO is full) \n", i);
		}
	}
	// printing the FIFO elements
	fifo_print(&fifo_UART);
	// dequeue 2 elements
	if (fifo_dequeue(&fifo_UART, &temp) == fifo_no_error)
		printf("FIFO dequeue (%x) -------------------- Done\n", temp);
	else
		printf("FIFO dequeue -------------------- Failed\n");
	if (fifo_dequeue(&fifo_UART, &temp) == fifo_no_error)
		printf("FIFO dequeue (%x) -------------------- Done\n", temp);
	else
		printf("FIFO dequeue -------------------- Failed\n");

	fifo_print(&fifo_UART);
	//free(FIFO_UART);



	return 0;
}

