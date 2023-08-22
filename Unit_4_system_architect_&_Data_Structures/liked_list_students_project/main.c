
#define _CRT_SECURE_NO_WARNINGS
/*
 * main.c
 *
 *  Created on: Apr 27, 2023
 *      Author: Ali Mohamed Taima
 */
#include "linked_list.h"

extern gpFirstStudent;


int main()
{
	char temp_text[40];
	while (1)
	{
		printf("\n===============================================");
		printf("\n Choose one of the following options \n");
		printf("\n 1: Add Student");
		printf("\n 2: Delete Student");
		printf("\n 3: View Students");
		printf("\n 4: Delete All");
 		printf("\n 5: Get item with its index");
		printf("\n 6: Get the length");
		printf("\n 7: reverse the list");
		printf("\n 0: Close the program");
		printf("\n");
		printf("\n Enter choice Number: ");
		gets(temp_text);
		printf("\n===============================================");
		switch (atoi(temp_text))
		{
		case 1:
			AddStudent();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			GetNth();
			break;
		case 6:
			Get_length();
			break;
		case 7:
			reverse();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("\nWrong choice");
			break;

		}
	}
	return 0;
}
