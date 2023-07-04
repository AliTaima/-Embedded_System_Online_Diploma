/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	char alph;
	printf("Enter an alphabet: ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &alph);
	switch(alph)
	{
	case 'a':
	case 'A':
		printf("%c is a vowel.", alph);
		break;
	case 'e':
	case 'E':
			printf("%c is a vowel.", alph);
			break;
	case 'i':
	case 'I':
			printf("%c is a vowel.", alph);
			break;
	case 'o':
	case 'O':
			printf("%c is a vowel.", alph);
			break;
	case 'u':
	case 'U':
			printf("%c is a vowel.", alph);
			break;
	default:
			printf("%c is a constant.", alph);
			break;
	}
	return 0;

}

