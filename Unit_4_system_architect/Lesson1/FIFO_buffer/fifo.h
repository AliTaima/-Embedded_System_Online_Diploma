/*
 * fifo.h
 *
 *  Created on: Jan 29, 2023
 *      Author: Ali Mohamed Taima
 */

#ifndef FIFO_H_
#define FIFO_H_
// including libraries
#include <stdio.h>
#include <stdint.h>

// User configurations
// select the element type (uint8_t, uint16_t, uint32_t)
#define element_type uint8_t

// create buffer
#define width1 5
element_type uart_buffer[width1];

// FIFO data types
typedef struct{
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

// FIFO status
typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_Buf_Status;

// FIFO APIs
FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo, element_type* buf, uint32_t length);
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t* fifo, element_type item);
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t* fifo, element_type* item);
FIFO_Buf_Status FIFO_Is_Full(FIFO_Buf_t* fifo, element_type* item);
void FIFO_print(FIFO_Buf_t* fifo);

#endif /* FIFO_H_ */
