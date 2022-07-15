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
	printf("ASCII value of G = %d", c);
	return 0;

}

