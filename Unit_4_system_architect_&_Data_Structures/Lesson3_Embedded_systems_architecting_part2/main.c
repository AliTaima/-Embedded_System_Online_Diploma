#include "stdio.h"
#include "stdlib.h"

int main()
{
	int* p = NULL;
	p = (int*)malloc(4);

	free(p);
	return 1;
}