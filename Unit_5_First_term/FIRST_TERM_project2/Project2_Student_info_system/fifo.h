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
#include <string.h>
#include <stdlib.h>
//#include "student_info.h"
// User configurations
// select the element type (uint8_t, uint16_t, uint32_t)
#define element_type student_inf_t

// create buffer
#define width1 50


typedef struct sinfo {
	char fname[50];
	char lname[50];
	int roll_num;
	float GPA;
	int course_id[10];
}student_inf_t;
// FIFO data types
typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
	element_type* tail;
}fifo_Buf_t;

// fifo status
typedef enum {
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null
}fifo_buf_status;

// FIFO APIs
fifo_buf_status fifo_init(fifo_Buf_t* fifo, element_type* buf, uint32_t length);
fifo_buf_status fifo_enqueue(fifo_Buf_t* fifo, element_type item);
fifo_buf_status fifo_dequeue(fifo_Buf_t* fifo, element_type* item);
fifo_buf_status fifo_Is_Full(fifo_Buf_t* fifo, element_type* item);

#endif /* FIFO_H_ */
