/*
 * main.c
 *
 *  Created on: Jul 16, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"
#include "string.h"
int main()
{
	char c = 'a', str[100];
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(str);

	int i;
	for(i = 0; c != 0; i++)
	{
		c = str[i];
	}

	printf("Length of string: %d", i-1);

	return 0;
}

