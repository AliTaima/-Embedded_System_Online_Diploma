/*
 * fifo.c
 *
 *  Created on: Jan 29, 2023
 *      Author: Ali Mohamed Taima
 */
#include "fifo.h"

fifo_buf_status fifo_init(fifo_Buf_t* fifo, element_type* buf, uint32_t length)
{
	
	if (buf == NULL)
		return fifo_null;

	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->count = 0;
	fifo->length = length;

	return fifo_no_error;
}
fifo_buf_status fifo_enqueue(fifo_Buf_t* fifo, element_type item)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;

	// check fifo is full?
	if (fifo_Is_Full(fifo, &item) == fifo_full)
		return fifo_full;
	*(fifo->head) = item;
	fifo->count++;
	// circular fifo
	if (fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base;
	else
		fifo->head++;
	return fifo_no_error;
}
fifo_buf_status fifo_dequeue(fifo_Buf_t* fifo, element_type* item)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;
	// check is fifo empty
	if (fifo->count == 0)
		return fifo_empty;
	*item = *(fifo->tail);
	fifo->count--;

	// circular fifo
	if (fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return fifo_no_error;

}
fifo_buf_status fifo_Is_Full(fifo_Buf_t* fifo, element_type* item)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return fifo_null;
	if (fifo->count == fifo->length)
		return fifo_full;

	return fifo_no_error;
}

