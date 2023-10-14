#ifndef STUDENT_INFO_H_
#define STUDENT_INFO_H_
#include "fifo.h"
element_type queue[width1];
/* 



void up_s();
*/
void add_student_manually(fifo_Buf_t* fifo);
void show_s(fifo_Buf_t* fifo);
void tot_s(fifo_Buf_t* fifo);
int del_s(fifo_Buf_t* fifo, int req_roll);
void find_roll_num(fifo_Buf_t* fifo, int req_roll);
void upate_s(fifo_Buf_t* fifo, int req_roll);
void find_first_name(fifo_Buf_t* fifo, char str[50]);
void find_course(fifo_Buf_t* fifo, int req_course);
void print_s(element_type* student);
void add_student_from_file(fifo_Buf_t* fifo);
void store_course_id(int courses[5]);
int check_douplicate_roll(fifo_Buf_t* fifo, int roll_num);

#endif // !STUDENT_INFO_H_


