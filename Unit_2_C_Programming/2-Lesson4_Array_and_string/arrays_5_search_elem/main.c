/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	int size, elem, i;
	printf("Enter no of elements: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &size);
	int arr[size];
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	fflush(stdin);fflush(stdout);

	printf("Enter the element to be searched: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &elem);
	for(i = 0; i < size; i++)
	{
		if(arr[i] == elem)
		{
			printf("Number found at location = %d", i+1);
			break;
		}

	}
	if(i == size)
		printf("Number not found :(");


	return 0;
}

