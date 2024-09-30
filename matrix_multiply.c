#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void multiply_matrix(int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2]);
void print_matrix(int row, int col, int matrix[row][col]);
void generate_matrix(int row, int col, int matrix[row][col]);

int main(int argc, char *argv[])
{
	if(argc<5 || atoi(argv[2])!= atoi(argv[3]))
	{
		printf("Error.\nPlease enter 4 arguments(row1,col1,row2,col2).\nMake sure that col1=row2.");
		exit(EXIT_FAILURE);
	}

	int row1 = atoi(argv[1]);
	int col1 = atoi(argv[2]);
	int row2 = atoi(argv[3]);
	int col2 = atoi(argv[4]);

	srand((int)time(NULL));
			
	int matrix1[row1][col1];
	int matrix2[row2][col2];

	generate_matrix(row1,col1,matrix1);
	generate_matrix(row2,col2,matrix2);
	printf("matrix 1 is: \n");
	print_matrix(row1,col1,matrix1);
	printf("matrix 2 is: \n");
	print_matrix(row2,col2,matrix2);

	multiply_matrix(row1,col1,row2,col2,matrix1,matrix2);

	return 0;
}

void generate_matrix(int row, int col, int matrix[row][col])
{
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			matrix[i][j]= rand()%10; //range 0-9
		}
	}
}


void print_matrix(int row, int col, int matrix[row][col])
{
	for(int i=0; i<row; ++i)
	
	{
		for(int j=0; j<col; ++j)
		{
			printf("%-4d", matrix[i][j]);
		}

		printf("\n");
	}

}

void multiply_matrix(int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2])
{

	int result[4][4];
	for(int i=0; i<row1; ++i)
	{
		for(int j=0; j<col2; ++j)
		{
			result[i][j] = 0; 
			//initialize each element

			for(int k=0; k<col1; ++k)
			{
				result[i][j]+= matrix1[i][k]*matrix2[k][j];
			}

		}	
	}

	printf("the matrix after multiplication is: \n");
	print_matrix(row1,col2,result);
}
