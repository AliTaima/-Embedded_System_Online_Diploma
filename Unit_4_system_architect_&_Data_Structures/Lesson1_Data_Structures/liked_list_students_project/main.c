/*
 * main.c
 *
 *  Created on: Apr 27, 2023
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
int main()
{
	printf("Hello Ali");
	return 0;
}
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
	struct Sstudent *PNextStudent;
};

struct Sstudent *gpFirstStudent = NULL;

void AddStudent()
{
	struct Sstudent *pNewStudent;
	struct Sstudent *pLastStudent;
	// check list is empty?
	if (gpFirstStudent == NULL)
	{
		// create new record
		pNewStudent = (struct Sstudent *)malloc(sizeof(struct Sstudent));
		// Assign it to gpfirst
		gpFirstStudent = pNewStudent;
	}
	else // List contains records
	{
		// Navigate until reach to the last record
		pLastStudent = gpFirstStudent;
		while (pLastStudent->PNextStudent)
			pLastStudent = pLastStudent->PNextStudent;
		pNewStudent = (struct Sstudent *)malloc(sizeof(struct Sstudent));
		pLastStudent->PNextStudent = pNewStudent;
	}
	pNewStudent->PNextStudent = NULL;
}
int delete_student()
{
	char temp_text[40];
	unsigned int selected_id;

	// Get the selected id
	printf("\nEnter the student ID to be deleted: ");
	gets(temp_text);
	selected_id = atoi(temp_text);

	// list is not empty?
	if (gpFirstStudent)
	{
		struct Sstudent *pSelectedStudent = gpFirstStudent;
		struct Sstudent *pPreviousStudent = NULL;
		// Looping on all the records
		while (pSelectedStudent)
		{
			// Comparing each node with selected ID
			if (pSelectedStudent->student.ID == selected_id)
			{
				if (pPreviousStudent) // the 1st is not the required ID
				{
					pPreviousStudent = pSelectedStudent->PNextStudent;
				}
				else // 1st student match the required ID
				{
					gpFirstStudent = pSelectedStudent->PNextStudent;
				}
				free(pSelectedStudent);
				return 1;
			}
			pPreviousStudent = pSelectedStudent;
			pSelectedStudent = pSelectedStudent->PNextStudent;
		}
		printf("\nCannot find the student ID");
		return 0;
	}
	printf("\nThe list is empty");
	return 0;
}
void view_students()
{
	struct Sstudent *pCurrentStudent = gpFirstStudent;
	int count = 0;
	if (gpFirstStudent == NULL)
		printf("\nEmbty list");
	else
	{
		while (pCurrentStudent)
		{
			printf("\n Record number %d", count + 1);
			printf("\n\t ID: %d", pCurrentStudent->student.ID);
			printf("\n\t Name: %s", pCurrentStudent->student.name);
			printf("\n\t Height: %f", pCurrentStudent->student.height);
			pCurrentStudent = pCurrentStudent->PNextStudent;
		}
	}
}
void DeleteAll()
{
	struct Sstudent *pCurrentStudent = gpFirstStudent;
	if (gpFirstStudent == NULL)
		printf("\nEmbty list");
	else
	{
		while (pCurrentStudent)
		{
			struct Sstudent *pTempStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->PNextStudent;
			free(pTempStudent);
		}
		// Make 1st node point to NULL(make it empty)
		gpFirstStudent = NULL;
	}
}
