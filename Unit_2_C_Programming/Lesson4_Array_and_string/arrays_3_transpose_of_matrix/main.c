/*
 * main.c
 *
 *  Created on: Jul 15, 2022
 *      Author: Ali Mohamed Taima
 */
#include "stdio.h"

int main()
{
	int row, col;
	printf("Enter rows and columns of matrix: ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d", &row, &col);
	int i , j, a[row][col], b[col][row];

	printf("Enter the elements of matrix\n");
	for(i = 0; i<row; i++)
	{
		for(j = 0; j<col; j++)
		{
			printf("Enter a%d%d: ", i+1, j+1);
			fflush(stdin);fflush(stdout);
			scanf(" %d",&a[i][j]);

		}
	}
	printf("Entered Matrix:\n");
	for(i = 0; i<row; i++)
	{
		for(j = 0; j<col; j++)
		{
			printf("%d\t", a[i][j]);
			b[j][i] = a[i][j];

		}
		printf("\n");
	}
	printf("Transpose of Matrix:\n");
	for(i = 0; i<col; i++)
	{
		for(j = 0; j<row; j++)
		{
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}

	return 0;
}

