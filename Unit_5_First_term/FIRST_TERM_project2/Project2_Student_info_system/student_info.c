#define _CRT_SECURE_NO_WARNINGS
#include "student_info.h"
element_type temp;
element_type *Ptemp;

element_type* student = NULL;
int i, j, choice;
void add_student_manually(fifo_Buf_t* fifo)
{
	
	printf("Enter the Roll number: ");
	scanf("%d", &(temp.roll_num));
	printf("Enter the first name of student: ");
	scanf("%s", temp.fname);
	printf("Enter the last name of student: ");
	scanf("%s", temp.lname);
	printf("Enter the GPA you obtained: ");
	scanf("%f", &temp.GPA);
	printf("Enter the course ID of each course\n");
	for (i = 0; i < 5; i++)
	{
		printf("Course %d ID: ", i + 1);
		scanf("%d", &temp.course_id[i]);
	}
	fifo_enqueue(fifo, temp);
	printf("[INFO] Student Details is added successfully\n");
}

void show_s(fifo_Buf_t* fifo)
{	
	Ptemp = fifo->tail;
	if (fifo->count == 0)
		printf("\n-----fifo is empty----\n");
	else
	{
		printf("\nThe students details\n");
		for (i = 0; i < fifo->count; i++)
		{
			print_s(Ptemp);
			printf("\n-------------------------------\n");
			Ptemp++;
		}
	}

}
void print_s(element_type* student)
{
	printf("\t Student first name: %s\n", student->fname);
	printf("\t Student last name: %s\n", student->lname);
	printf("\t Student roll number: %d\n", student->roll_num);
	printf("\t Student GPA: %.2f\n", student->GPA);
	for (j = 0; j < 5; j++)
	{
		printf("\t The course ID is: %d\n", student->course_id[j]);
	}
}
void tot_s(fifo_Buf_t* fifo)
{

	printf("[INFO] The total number of students is: %d\n", fifo->count);
	printf("[INFO] You can add up to %d students\n", width1);
	printf("[INFO] You can add %d more students\n", width1 - fifo->count);
}
int del_s(fifo_Buf_t* fifo, int req_roll)
{
	Ptemp = fifo->tail;
	if (fifo->count == 0)
	{
		printf("[ERROR] The queue is empty\n");
		return 0;
	}
		
	else if (req_roll == fifo->tail->roll_num)
	{
		//Handling circular queue(if tail reach the end start from the beginning)
		if (fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
			fifo->tail = fifo->base;
		else
			fifo->tail++;
		fifo->count--;
		printf("Roll number %d is removed successfully\n", req_roll);
		return 1;
	}
	else if (req_roll == (fifo->head-1)->roll_num)
	{
		//Handling circular queue(if head equal base so the incremental will be 
		// the end of the queue
		if (fifo->head == fifo->base)
			fifo->head = (fifo->base + (fifo->length * sizeof(element_type)));
		else
			fifo->head--;

		fifo->count--;
		printf("Roll number %d is removed successfully\n", req_roll);
		return 1;
	}
	for (i = 0; i < fifo->count; i++)
	{
		if (Ptemp->roll_num == req_roll)
		{

			break;
		}
		Ptemp++;
	}
	if (i == fifo->count)
	{
		printf("[ERROR] The roll number %d is not found", req_roll);
		return 0;
	}
	else
	{
		for (j = 0; j < i; j++)
		{
			strcpy(Ptemp->fname,  (Ptemp - 1)->fname);
			strcpy(Ptemp->lname, (Ptemp - 1)->lname);
			Ptemp->roll_num = (Ptemp - 1)->roll_num;
			Ptemp->GPA = (Ptemp - 1)->GPA;
			for (j = 0; j < 5; j++)
			{
				Ptemp->course_id[j] = (Ptemp - 1)->course_id[j];
			}


		}
		fifo->tail++;
		fifo->count--;
	}
	printf("Roll number %d is removed successfully\n", req_roll);
	return 1;
}
void find_roll_num(fifo_Buf_t* fifo, int req_roll)
{
	Ptemp = fifo->tail;
	if (fifo->count == 0)
	{
		printf("[ERROR] The queue is empty\n");
		return 0;
	}

	else if (req_roll == fifo->tail->roll_num)
	{
		printf("\nThe student details\n");
		print_s(fifo->tail);
		return 1;
	}
	else if (req_roll == (fifo->head - 1)->roll_num)
	{
		printf("\nThe student details\n");
		print_s(fifo->head - 1);
		return 1;
	}
	for (i = 0; i < fifo->count; i++)
	{
		if (Ptemp->roll_num == req_roll)
		{
			break;
		}
		Ptemp++;
	}
	if (i == fifo->count)
	{
		printf("[ERROR] The roll number %d is not found", req_roll);
		return 0;
	}
	else
	{
		printf("\nThe student details\n");
		print_s(Ptemp);
		return 1;
	}
}
void upate_s(fifo_Buf_t* fifo, int req_roll)
{
	Ptemp = fifo->tail;
	if (fifo->count == 0)
	{
		printf("[ERROR] The queue is empty\n");
		return 0;
	}

	for (i = 0; i < fifo->count; i++)
	{
		if (Ptemp->roll_num == req_roll)
		{
			break;
		}
		Ptemp++;
	}
	if (i == fifo->count)
	{
		printf("[ERROR] The roll number %d is not found", req_roll);
		return 0;
	}
	else
	{
		printf("\nChoose what you want to update\n");
		printf("1. First name\n");
		printf("2. Second name\n");
		printf("3. roll number\n");
		printf("4. GPA\n");
		printf("5. Courses\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the new first name of the student: ");
			scanf("%s", Ptemp->fname);
			break;
		case 2:
			printf("Enter the new last name of student: ");
			scanf("%s", Ptemp->lname);
			break;
		case 3:
			printf("Enter the new roll number: ");
			scanf("%d", &(Ptemp->roll_num));
			break;
		case 4:
			printf("Enter the new GPA you obtained: ");
			scanf("%f", &(Ptemp->GPA));
			break;
		case 5:
			printf("Enter the new ID of each course\n");
			for (i = 0; i < 5; i++)
			{
				printf("Course %d ID: ", i + 1);
				scanf("%d", &(Ptemp->course_id[i]));
			}
			break;
		}
		
		print_s(Ptemp);
		return 1;
	}
}
void find_first_name(fifo_Buf_t* fifo, char str[50])
{
	int test = 0;
	Ptemp = fifo->tail;
	if (fifo->count == 0)
	{
		printf("[ERROR] The queue is empty\n");
		return 0;
	}

	for (i = 0; i < fifo->count; i++)
	{
		if (!strcmp(str, Ptemp->fname))
		{
			printf("\nThe student details\n");
			print_s(Ptemp);
			test = 1;
		}
		Ptemp++;
	}
	if (i == fifo->count && test == 0)
	{
		printf("[ERROR] The first name %s is not found", str);
		return 0;
	}

}
void find_course(fifo_Buf_t* fifo, int req_course)
{
	int test = 0, count = 0;
	Ptemp = fifo->tail;
	if (fifo->count == 0)
	{
		printf("[ERROR] The queue is empty\n");
		return 0;
	}

	for (i = 0; i < fifo->count; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (req_course == Ptemp->course_id[j])
			{
				printf("\nThe student details\n");
				printf("\t Student first name: %s\n", Ptemp->fname);
				printf("\t Student last name: %s\n", Ptemp->lname);
				printf("\t Student roll number: %d\n", Ptemp->roll_num);
				printf("\t Student GPA: %.2f\n", Ptemp->GPA);
				printf("\n-------------------------------\n");
				count++;
			}

		}
		test = 1;
		Ptemp++;
	}
	if (i == fifo->count && test == 0)
	{
		printf("[ERROR] The course ID %d is not found", req_course);
		return 0;
	}
	else
	{
		printf("[INFO] Total number of students enrolled: %d", count);
		printf("\n================================\n");

	}

}

