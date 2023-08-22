#include "linked_list.h"
struct Sstudent* gpFirstStudent = NULL;
void AddStudent(void)
{
	struct Sstudent* pNewStudent;
	struct Sstudent* pLastStudent;
	char temp_text[40];
	// check list is empty?
	if (gpFirstStudent == NULL)
	{
		// create new record
		pNewStudent = (struct Sstudent*)malloc(sizeof(struct Sstudent));
		// Assign it to gpfirst
		gpFirstStudent = pNewStudent;
	}
	else // List contains records
	{
		// Navigate until reach to the last record
		pLastStudent = gpFirstStudent;
		while (pLastStudent->PNextStudent)
			pLastStudent = pLastStudent->PNextStudent;
		pNewStudent = (struct Sstudent*)malloc(sizeof(struct Sstudent));
		pLastStudent->PNextStudent = pNewStudent;
	}
	// fill new record
	printf("\nEnter the ID: ");
	gets(temp_text);
	pNewStudent->student.ID = atoi(temp_text);

	printf("\nEnter the sutend full name: ");
	gets(pNewStudent->student.name);

	printf("\nEnter the student height: ");
	gets(temp_text);
	pNewStudent->student.height = atof(temp_text);

	//set the next pointer (new student) by null
	pNewStudent->PNextStudent = NULL;
}

int delete_student(void)
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
		struct Sstudent* pSelectedStudent = gpFirstStudent;
		struct Sstudent* pPreviousStudent = NULL;
		// Looping on all the records
		while (pSelectedStudent)
		{
			// Comparing each node with selected ID
			if (pSelectedStudent->student.ID == selected_id)
			{
				if (pPreviousStudent) // the 1st is not the required ID
				{
					pPreviousStudent->PNextStudent = pSelectedStudent->PNextStudent;
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
void view_students(void)
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
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
			count++;
		}
	}
}
void DeleteAll(void)
{
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	if (gpFirstStudent == NULL)
		printf("\nEmbty list");
	else
	{
		while (pCurrentStudent)
		{
			struct Sstudent* pTempStudent = pCurrentStudent;
			pCurrentStudent = pCurrentStudent->PNextStudent;
			free(pTempStudent);
		}
		// Make 1st node point to NULL(make it empty)
		gpFirstStudent = NULL;
	}
}
void GetNth(void)
{
	unsigned int index, c = 0;
	char str[5];
	printf("\nEnter the index:");
	gets(str);
	index = atoi(str);
	struct Sstudent* pCurrentStudent = gpFirstStudent;
	if (gpFirstStudent == NULL)
		printf("\nEmbty list");
	else
	{
		while (pCurrentStudent)
		{
			if (index == c)
			{
				printf("\n Record number %d", c);
				printf("\n\t ID: %d", pCurrentStudent->student.ID);
				printf("\n\t Name: %s", pCurrentStudent->student.name);
				printf("\n\t Height: %f", pCurrentStudent->student.height);
				break;
			}
			else
			{
				c++;
				pCurrentStudent = pCurrentStudent->PNextStudent;
			}

		}
		if (index != c)
			printf("---------------------------Not found----------------------------------");

	}

}
void Get_length(void)
{
	unsigned int  c = 0;

	struct Sstudent* pCurrentStudent = gpFirstStudent;
	while (pCurrentStudent)
	{
		c++;
		pCurrentStudent = pCurrentStudent->PNextStudent;
	}
	printf("\nLength of the linded list = %d", c);
}
void reverse(void)
{
	if (gpFirstStudent == NULL)
		printf("\nEmbty list");
	else
	{
		struct Sstudent* temp = gpFirstStudent;
		struct Sstudent* prev = NULL;
		struct Sstudent* current = gpFirstStudent;
		struct Sstudent* nextNode;
		while (current)
		{
			nextNode = current->PNextStudent;
			current->PNextStudent = prev;
			prev = current;
			current = nextNode;
		}
		gpFirstStudent = prev;
		printf("\nReversed succesfully");
	}


}