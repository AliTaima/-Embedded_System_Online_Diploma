#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//Assuming max legnth = 19
	char str[20], i = 0, * strp;
	strp = str;
	scanf("%s", str);
	while (*strp)
	{
		strp++;
		i++;
	}
	for (i = i; i >= 0; i--)
	{
		printf("%c", *(strp--));
	}

	return 0;
}