/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */

#include "stdio.h"

int main()
{
	float num1, num2, num3, largest;
	printf("Enter three numbers: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f %f", &num1, &num2, &num3);
	if(num1 > num2)
	{
		if(num1 > num3)
			largest = num1;
	}
	else if(num2 > num3)
		largest = num2;
	else
		largest = num3;
	printf("Largest number = %.2f", largest);
	return 0;

}
