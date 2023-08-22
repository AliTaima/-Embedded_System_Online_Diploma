#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	char ch = 'A';
	char* alpha;
	alpha = &ch;
	int i;
	for (i = 0; i < 26; i++)
	{
		printf("%c\n",(*alpha)+i);
	}
	
	return 0;
}