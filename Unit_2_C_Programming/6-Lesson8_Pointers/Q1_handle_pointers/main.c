#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	int m = 29;
	printf("Address of m: %p\n", &m);
	printf("Value of m: %d\n", m);

	int* ab = &m;
	printf("\nAddress of ab: %p\n", ab);
	printf("Value of ab: %d\n", *ab);

	m = 34;
	printf("\nAddress of m: %p\n", &m);
	printf("Value of m: %d\n", m);

	*ab = 7;
	printf("\nAddress of ab: %p\n", ab);
	printf("Value of ab: %d\n", *ab);
	return 0;
}