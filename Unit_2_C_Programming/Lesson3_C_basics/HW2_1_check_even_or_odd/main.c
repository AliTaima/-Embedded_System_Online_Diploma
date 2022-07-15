/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	int num;
	printf("Enter an integer you want to check: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	if(num%2 == 0)
		printf("%d is even", num);
	else
		printf("%d is odd", num);

	return 0;

}

