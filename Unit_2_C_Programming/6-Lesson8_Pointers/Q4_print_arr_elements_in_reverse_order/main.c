#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//Assuming max legnth = 15
	int arr[20], i, n;
	printf("Enter the number of elements to store in the array (max 15): ");
	scanf("%d", &n);
	printf("Enter %d number of elements in the array:\n", n);
	for (i = 0; i < n; i++)
	{
		printf("Element_%d: ", i + 1);
		scanf("%d", arr + i);

	}
	int* p = arr[n-1]
	printf("\n----------------------Reversed elemetns-----------------------------\n\n");
	for (i = n-1; i >= 0 ; i--)
	{
		printf("Element_%d: ", i + 1);
		printf("%d\n", p--);

	}
	
	return 0;
}