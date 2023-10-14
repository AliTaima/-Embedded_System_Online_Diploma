/*
 * main.c
 *
 *  Created on: Jan 29, 2023
 *      Author: Ali Mohamed Taima
 */
#define _CRT_SECURE_NO_WARNINGS
#include "student_info.h"

int main()
{
	fifo_Buf_t students_data_base;
	if (!fifo_init(&students_data_base, queue, (uint32_t)width1) == fifo_no_error)
		exit(0);
	int choice, req_roll, req_course;
	char str[50];
	printf("Welcome to the student managements system\n");
	while (1)
	{
		printf("\nChoose the task that you want to perform\n");
		printf("1. Add the student details from text file\n");
		printf("2. Add the student details manually\n");
		printf("3. Find the student details by roll number\n");
		printf("4. Find the student details by first number\n");
		printf("5. Find the student details by course ID\n");
		printf("6. Find the total number of students\n");
		printf("7. Delete the students details by roll number\n");
		printf("8. Update the students details by roll number\n");
		printf("9. Show all information\n");
		printf("10. To Exit\n");
		printf("Enter your choice to perform the task :");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			add_student_from_file(&students_data_base);
			break;
		case 2:
			add_student_manually(&students_data_base);
			break;
		case 3:
			printf("Enter the roll number of the student that you want to show: ");
			scanf("%d", &req_roll);
			find_roll_num(&students_data_base, req_roll);
			break;
		case 4:
			printf("Enter the first name of the student that you want to show: ");
			scanf("%s", str);
			find_first_name(&students_data_base, str);
			break;
		case 5:
			printf("Enter the course id that you want to show: ");
			scanf("%d", &req_course);
			find_course(&students_data_base, req_course);
			break;
		case 6:
			tot_s(&students_data_base);
			break;
		case 7: 
			printf("Enter the roll number which you want to delete: ");
			scanf("%d", &req_roll);
			del_s(&students_data_base, req_roll);
			break;
		case 8:
			printf("Enter the roll number which you want to update: ");
			scanf("%d", &req_roll);
			upate_s(&students_data_base, req_roll);
			break;
		case 9:
			show_s(&students_data_base);
			break;
		case 10:
			exit(0);
		default:
			printf("Wrong choice\n");
			break;
		}
	}
	

	return 0;
}

