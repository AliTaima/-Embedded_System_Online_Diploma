/*
 * main.c
 *
 *  Created on: Jul 16, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	char str[100] = "ali", temp[100];
	printf("Enter the string: ");
	fflush(stdin);fflush(stdout);
	gets(str);

	int i, j, k;
	// 1st for find null in the string
	// 2nd for copy char from the end of str to temp func
	for(i = 0; ; i++)
	{
		if(str[i] == 0)
		{
			for(j = i-1, k = 0; j>=0; j--, k++)
			{
				temp[j] = str[k];
			}
			break;
		}
	}
	printf("%s", temp);

	return 0;
}

