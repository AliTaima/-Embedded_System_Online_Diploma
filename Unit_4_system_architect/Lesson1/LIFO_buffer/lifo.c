/*
 * lifo.c
 *
 *  Created on: Jan 28, 2023
 *      Author: Ali Mohamed Taima
 */
# include "lifo.h"
// APIs
LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buf, unsigned int item)
{
	// checking LIFO is valid?
	if(!lifo_buf->base || !lifo_buf->head)
		return LIFO_Null;
	// check LIFO is full?
	if(lifo_buf->cout == lifo_buf->length)
		return LIFO_full;

	// Adding value
	*(lifo_buf->head) = item;
	lifo_buf->head++;
	lifo_buf->cout++;

	return LIFO_no_error;

}
LIFO_status LIFO_get_item(LIFO_Buf_t* lifo_buf, unsigned int* item)
{
	// checking LIFO is valid?
	if(!lifo_buf->base || !lifo_buf->head)
			return LIFO_Null;
	// checking LIFO IS empty?
	if(lifo_buf->cout == 0)
			return LIFO_empty;

	// Getting element
	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->cout--;

	return LIFO_no_error;

}
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf, unsigned int* buf, unsigned int length)
{
	// checking if there is enough space or not (in case of dynamic allocation)
	if(buf == NULL)
		return LIFO_Null;

	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->cout = 0;

	// to make sure that process finished successfully
	return LIFO_no_error;
}

