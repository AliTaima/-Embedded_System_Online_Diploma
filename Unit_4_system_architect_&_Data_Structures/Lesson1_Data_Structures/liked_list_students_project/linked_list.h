#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// effective data
struct Sdata
{
	int ID;
	char name[40];
	float height;
};
// Linked list node
struct Sstudent
{
	struct Sdata student;
	struct Sstudent* PNextStudent;
};

void AddStudent(void);
int delete_student(void);
void view_students(void);
void DeleteAll(void);
int delete_student(void);
void view_students(void);
void DeleteAll(void);
void GetNth(void);
void Get_length(void);
void reverse(void);
#endif
