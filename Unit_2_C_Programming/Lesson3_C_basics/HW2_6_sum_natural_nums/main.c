/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	int num, i, sum = 0;
	printf("Enter a character: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	for(i = 1; i<=num; i++)
		sum += i;
	printf("Sum = %d", sum);
	return 0;
}

