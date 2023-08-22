/*
 * lifo.c
 *
 *  Created on: Jan 28, 2023
 *      Author: Ali Mohamed Taima
 */
# include "lifo.h"
 // APIs
lifo_status lifo_add_item(lifo_buf_t* lifo_buf, unsigned int item)
{
	// checking lifo is valid?
	if (!lifo_buf->base || !lifo_buf->head) // if base or head are not exist (NULL) 
		return lifo_null;
	// check lifo is full?
	if (lifo_buf->cout == lifo_buf->length)
		return lifo_full;

	// Adding value
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->cout++;

	return lifo_no_error;

}
lifo_status lifo_get_item(lifo_buf_t* lifo_buf, unsigned int* item)
{
	// checking lifo is valid?
	if (!lifo_buf->base || !lifo_buf->head)
		return lifo_null;
	// checking lifo IS empty?
	if (lifo_buf->cout == 0)
		return lifo_empty;

	// Getting element
	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->cout--;

	return lifo_no_error;

}
lifo_status lifo_init(lifo_buf_t* lifo_buf, unsigned int* buf, unsigned int length)
{
	// checking if there is enough space or not (in case of dynamic allocation)
	if (buf == NULL)
		return lifo_null;

	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->cout = 0;

	// to make sure that process finished successfully
	return lifo_no_error;
}

