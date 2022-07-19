/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	char c;
	printf("Enter a character: ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &c);
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		printf("%c is an alphabet.", c);
	else
		printf("%c is not an alphabet.", c);

	return 0;

}

