/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	float num1, num2;
	printf("Enter two numbers: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f", &num1, &num2);
	printf("Product: %f", num1 * num2);
	return 0;

}

