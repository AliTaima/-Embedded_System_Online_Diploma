/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	float num1, num2, result;
	char operator;
	printf("Enter operator either + or - or * or /: ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &operator);
	printf("Enter two operands: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f", &num1, &num2);
	switch(operator)
	{
	case '+':
		result = num1 + num2;
		printf("%.1f %c %.1f = %.1f", num1, operator, num2, result);
		break;
	case '-':
			result = num1 - num2;
			printf("%.1f %c %.1f = %.1f", num1, operator, num2, result);
			break;
	case '*':
			result = num1 * num2;
			printf("%.1f %c %.1f = %.1f", num1, operator, num2, result);
			break;
	case '/':
			if(num2 == 0)
				printf("Error!!! division by zero");
			else
			{
				result = num1 / num2;
				printf("%.1f %c %.1f = %.1f", num1, operator, num2, result);
			}
			break;
	default:
		printf("Error!!! Please enter valid operator");
		break;
	}

	return 0;

}

