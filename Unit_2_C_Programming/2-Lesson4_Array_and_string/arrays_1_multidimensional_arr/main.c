/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	float a[2][2], b[2][2];
	int i, j;
	//taking the elements of matrix1
	printf("Enter the elements of 1st matrix\n");
	for(i = 0; i<2; i++)
	{
		for(j = 0; j<2; j++)
		{
			printf("Enter a%d%d: ", i+1, j+1);
			fflush(stdin);fflush(stdout);
			scanf(" %f",&a[i][j]);

		}
	}
	//taking the elements of matrix2
	printf("Enter the elements of 2nd matrix\n");
	for(i = 0; i<2; i++)
	{
		for(j = 0; j<2; j++)
		{
			printf("Enter b%d%d: ", i+1, j+1);
			fflush(stdin);fflush(stdout);
			scanf(" %f",&b[i][j]);

		}
	}
	printf("Sum Of Matrix:\n");
	for(i = 0; i<2; i++)
	{
		for(j = 0; j<2; j++)
		{
			printf("%.1f\t", a[i][j] + b[i][j]);

		}
		printf("\n");
	}


	return 0;
}

