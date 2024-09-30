#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void transpose_matrix(int row, int col, int matrix[row][col], int matrix_new[col][row]); /*when setting the argument, remember to swap row col in new matrix*/

int main(int argc, char *argv[])
{
	srand((unsigned int)time(NULL));
	
	int row, col;
	int i,j;
	printf("Enter the number of row: ");
	scanf("%d", &row);
	printf("Enter the number of col: ");
	scanf("%d", &col);

	int matrix[row][col], matrix_new[col][row];

	for(i=0; i<row; ++i)
	{
		for(j=0; j<col; ++j)
		{
			matrix[i][j] = rand()%10;
		}
	}

	printf("The matrix generated is: \n");
	for(i=0; i<row; ++i)
	{
		for(j=0; j<col; ++j)
		{
			printf("%-4d",matrix[i][j]);		
		}
		printf("\n");
	}


	transpose_matrix(row,col,matrix,matrix_new);

	printf("The matrix tranposed is: \n");
	for(i=0; i<col; ++i)
	{
		for(j=0; j<row; ++j)
		{
			printf("%-4d",matrix_new[i][j]);		
		}
		printf("\n");
	}
	/*when printing transposed matrix, remember that in new matrix
	row = original col, col = original row*/

	return 0;
}

void transpose_matrix(int row, int col, int matrix[row][col], int matrix_new[col][row])
{
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			matrix_new[j][i] = matrix[i][j];
		}
	}
}

