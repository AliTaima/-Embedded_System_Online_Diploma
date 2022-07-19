/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	int size = 1000, temp_size, i, elem, location;
	int arr[size];
	printf("Enter no of elements: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &temp_size);
	for(i = 0; i<temp_size; i++)
	{
		scanf("%d", &arr[i]);
		fflush(stdin);fflush(stdout);
		printf("%d ", arr[i]);
	}
	temp_size ++;
	printf("\nEnter the element to be inserted: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &elem);
	printf("Enter the element to be inserted: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &location);
	for(i = temp_size - 1; i>0; i--)
	{
		arr[i] = arr[i-1];
		if(i == location -1)
		{
			arr[i] = elem;
		}
	}
	for(i = 0; i<temp_size; i++)
		{
			printf("%d ", arr[i]);
		}


	return 0;
}

