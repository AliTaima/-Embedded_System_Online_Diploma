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
	char str[100];
	// taking the stirng from user
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(str);
	// taking character that will calc. the freq. for it
	char c, temp = 'a';
	int i = 0, count = 0;
	printf("Enter a character to find frequency: ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &c);

	while(temp != 0)
	{
		temp = str[i];
		if(temp == c)
			count ++;
		i++;
	}
	printf("Frequency of %c = %d", c, count);


	return 0;
}

