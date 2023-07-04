/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	int size, a;
	printf("Enter the numbers of data: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &size);
	float arr[size], sum = 0.0;
	for(a = 0; a<size; a++)
	{
		printf("%d. Enter number: ", a+1);
		fflush(stdin);fflush(stdout);
		scanf("%f", &arr[a]);
		sum += arr[a];
	}
	printf("Average = %.2f", sum/size);


	return 0;
}


