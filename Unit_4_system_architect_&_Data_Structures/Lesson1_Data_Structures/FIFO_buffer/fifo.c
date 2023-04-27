/*
 * fifo.c
 *
 *  Created on: Jan 29, 2023
 *      Author: Ali Mohamed Taima
 */
#include "fifo.h"

FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo, element_type* buf, uint32_t length)
{
	if(buf == NULL)
		return FIFO_null;

	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->count = 0;
	fifo->length = length;

	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t* fifo, element_type item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;

	// check FIFO is full?
	if(FIFO_Is_Full(fifo, &item) == FIFO_full)
		return FIFO_full;
	*(fifo->head) = item;
	fifo->count++;
	// circular FIFO
	if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base;
	else
		fifo->head++;
	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t* fifo, element_type* item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	// check is FIFO empty
	if(fifo->count == 0)
		return FIFO_empty;
	*item = *(fifo->tail);
	fifo->count--;

	// circular FIFO
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_no_error;

}
FIFO_Buf_Status FIFO_Is_Full(FIFO_Buf_t* fifo, element_type* item)
{
	if(!fifo->base || !fifo->head || !fifo->tail)
			return FIFO_null;
	if(fifo->count == fifo->length)
		return FIFO_full;

	return FIFO_no_error;
}
void FIFO_print(FIFO_Buf_t* fifo)
{
	element_type* temp;
	temp = fifo->tail;
	unsigned int i;
	if(fifo->count == 0)
		printf("\n-----FIFO is empty----\n");
	else
	{
		printf("\n=============FIFO print=============\n");
		for(i = 0; i<fifo->count; i++)
			{
				printf("\t %x\n", *temp);
				temp++;
			}
		printf("====================================\n\n");
	}

}

