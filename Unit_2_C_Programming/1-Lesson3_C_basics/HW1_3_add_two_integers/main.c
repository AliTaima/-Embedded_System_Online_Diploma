/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	int num1, num2;
	printf("Enter two integers: ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d", &num1, &num2);
	printf("Sum: %d", num1 + num2);
	return 0;

}

