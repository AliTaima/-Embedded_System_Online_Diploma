/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	int num, i, fact = 1;
	printf("Enter an integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	if(num < 0)
		printf("Error!!! Factorial of negative number doesn't exist");
	else if(num == 0)
		printf("Factorial = 1");
	else
	{
		for(i = 2; i<=num; i++)
			fact *= i;
		printf("Factorial = %d", fact);
	}

	return 0;
}

