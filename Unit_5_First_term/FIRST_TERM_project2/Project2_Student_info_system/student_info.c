#define _CRT_SECURE_NO_WARNINGS
#include "student_info.h"
element_type temp;
element_type *Ptemp;
element_type* Ptemp2;


element_type* student = NULL;
int i, j, a, choice, temp_roll;
int check_douplicate_roll(fifo_Buf_t* fifo, int roll_num)
{
	Ptemp2 = fifo->tail;
	for (i = 0; i < fifo->count; i++)
	{
		if (Ptemp2->roll_num == roll_num)
		{
			printf("[ERROR] roll numbe is unique for each student, please enter anohter one\n");
			return 0;
		}
		Ptemp2++;
	}
		return 1;

}
void store_course_id( int courses[5])
{
	int f, id;
	
	for (i = 0; i < 5; i++)
	{
		f = 1;// use as a flage to detect douplicate course ids 
		while (f)
		{
			printf("Course %d ID: ", i + 1);
			scanf("%d", &id);
			f = 0;
			for (j = 0; j < 5; j++)
			{

				if (j == i)
					continue;
				if (id == courses[j])
				{
					printf("[ERROR] Please enter unique course id for the same student\n");
					f = 1;
					break;
				}
			}
			courses[i] = id;
		}
	}
	
}
void add_student_manually(fifo_Buf_t* fifo)
{
	do
	{
		printf("Enter the Roll number: ");
		scanf("%d", &(temp.roll_num));
	} while (!check_douplicate_roll(fifo, temp.roll_num));
	
	printf("Enter the first name of student: ");
	scanf("%s", temp.fname);
	printf("Enter the last name of student: ");
	scanf("%s", temp.lname);
	printf("Enter the GPA you obtained: ");
	scanf("%f", &temp.GPA);
	printf("Enter the course ID of each course\n");
	store_course_id(temp.course_id);
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
	/* 
	* This function is used to delete student from the database and I have 3 cases
	* 1- the student at the beginning of the queue so I want to increment the tail only
	* 2- the student at the end of the queue so I wanto to decrement the head only
	* 3- the student at random place between the tail and the head so I work from the tail
	* until I find it then exchange the data between each two students until reach the end
	* and increment the tail
	*/
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
			for (a = 0; a < 5; a++)
			{
				Ptemp->course_id[a] = (Ptemp - 1)->course_id[a];
			}
			Ptemp--;

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
	/*
	* - This function update the data of student you enter before 
	* - You should choose which data you want to change 
	*/
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
			do
			{
				printf("Enter the new roll number: ");
				scanf("%d", &temp_roll);
			} while (!check_douplicate_roll(fifo, temp_roll));
			Ptemp->roll_num = temp_roll;
			break;
		case 4:
			printf("Enter the new GPA you obtained: ");
			scanf("%f", &(Ptemp->GPA));
			break;
		case 5:
			printf("Enter the new ID of each course\n");
			store_course_id(Ptemp->course_id);
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
void add_student_from_file(fifo_Buf_t* fifo)
{
	FILE* fptr;
	int i, j, a;
	fptr = fopen("details.txt", "r");
	char content[1000], temp_str[50];
	if (fptr != NULL)
	{
		while (fgets(content, 1000, fptr))
		{
			j = 0;
			for (i = 0; i < 9; i++)// read 9 different words
			{
				a = 0; // use this to store data at temp_str
				for (j = j; j < 100; j++)
				{
					// separate each word by ',' or end phrase with '\0'
					if (content[j] == ',' || content[j] == '\0')
					{
						// go to next char as if it breaks it will frez 
						// at ',' or '\0'
						j++;
						break;
					}
					if (content[j] == ' ')// skip spaces
						continue;
					temp_str[a] = content[j];// copy content before ',' or '\0'
					a++;
				}
				temp_str[a] = '\0';// add null at the end of string

				switch (i)
				{
				case 0:
					temp.roll_num = atoi(temp_str);
					break;
				case 1:
					strcpy(temp.fname, temp_str);
					break;
				case 2:
					strcpy(temp.lname, temp_str);
					break;
				case 3:
					temp.GPA = atof(temp_str);
					break;
				case 4:
					temp.course_id[0] = atoi(temp_str);
					break;
				case 5:
					temp.course_id[1] = atoi(temp_str);
					break;
				case 6:
					temp.course_id[2] = atoi(temp_str);
					break;
				case 7:
					temp.course_id[3] = atoi(temp_str);
					break;
				case 8:
					temp.course_id[4] = atoi(temp_str);
					break;
				default:
					break;
				}
			}
			fifo_enqueue(fifo, temp);
		}
		printf("------------Students details added successfully-------------\n");
	}
	else
		printf("Fail");
}

