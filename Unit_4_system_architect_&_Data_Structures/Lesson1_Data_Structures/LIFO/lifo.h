/*
 * lifo.h
 *
 *  Created on: Jan 28, 2023
 *      Author: Ali Mohamed Taima
 */

#ifndef LIFO_H_
#define LIFO_H_

 //include libraries
#include <stdio.h>
#include <stdlib.h>

// type definitions
typedef struct {
	unsigned int length;
	unsigned int cout;
	unsigned int* base;
	unsigned int* head;
}lifo_buf_t;

typedef enum {
	lifo_no_error,
	lifo_full,
	lifo_empty,
	lifo_null
}lifo_status;


// APIs
lifo_status lifo_add_item(lifo_buf_t* lifo_buf, unsigned int item);
lifo_status lifo_get_item(lifo_buf_t* lifo_buf, unsigned int* item);
lifo_status lifo_init(lifo_buf_t* lifo_buf, unsigned int* buf, unsigned int length);

#endif /* LIFO_H_ */

