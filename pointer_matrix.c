#include <stdio.h>
#include <stdlib.h>

void initialize_matrix(int ***ptr, int row, int col)
{
	*ptr = (int**)malloc(row1*sizeof(int*)) //use one * to access to **ptr (matrix)
	//allocate memeory on each row for each element
	for(int i=0; i<row; ++i)
	{
		*(*ptr+i) = (int*)malloc(col*sizeof(int)); //use one more * to access to *ptr (matrix[i])
		   
	       	for (int j=0; j<col; ++j)
		{
            		do
			{
				printf("m1[%d][%d]: ",i,j);

				if(scanf("%d",*(*ptr+i)+j)!=1)
					printf("Invalid input, please enter an integer.\n");

			}while (scanf("%d",*(*ptr+i)+j)!=1)

			//!=1 means the integer was not scanned successufly, probably not an integer
			//when scan a value to pointer, no need & (because & is used to point to an address	      
		}	
	}
}

void display_matrix(int **ptr, int row, int col)
{
	for(int i=0; i<row; ++i)
	{
		for(int j=0; j<col; ++j)
		{
			printf("%d ", *((*ptr+i)+j));
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	//command line arguments input
	//input will be./a.out n n n n(m1row m1col m2row m2col)
	if(argc!=5)
	{
		printf("Invalid Input\n");
		exit(EXIT_FAILURE);
	}

	int row1 = atoi(argv[1]);
	int col1 = atoi(argv[2]);
	int row2 = atoi(argv[3]);
	int col2 = atoi(argv[4]);

	if(col1 != row2)
	{
		printf("Invalid Size\n");
		exit(EXIT_FAILURE);
	}

	//for 2D array we should allocate memeory twice
	//first to matrix(all rows) = rows * size
	//second to each row(in a loop of row) = cols * size
	
	/*without function
	//allocate memory for the whole 
	int **p1 = (int**)malloc(row1*sizeof(int*));//pointer 1 to matrix 1 //matrix
	int **p2 = (int**)malloc(row2*sizeof(int*));//pointer 2 to matrix 2
	
	//allocate memeory on each row for each element
	for(int i=0; i<row1; ++i)
	{
		*p1 = (int*)malloc(col1*sizeof(int)); //matrix[i]
		   
	       	for (int j = 0; j < row1 ++j)
		{
            		do
			{
				printf("m1[%d][%d]: ",i,j);

				if(scanf("%d",p1+j!=1)
						printf("Invalid input, please enter an integer.\n");

			}while (scanf("%d", p1+j)!=1) 

			//!=1 means the integer was not scanned successufly, probably not an integer
			//when scan a value to pointer, no need & (because & is used to point to an address	      
		}
	
		++p1;
		//we are not allowed to use index, so p1 can't go to next place by increment i.
		//so we increment p1 directly
	}*/

	/*using functions*/
	int **p1;
	int **p2;//without initialization
	initialize_matrix(&p1,row1,col1);
	initialize_matrix(&p2,row2,col2);

	/*display matrix*/

	/*multiply matrix*/

	int **p3 = (int**)malloc(row1*sizeof(int*)); //result matrix
	for(int i=0; i<row1; ++i)
	{
		*(p3+i) = (int*)malloc(col2*sizeof(int));

		for(int j=0; j<col2; ++j)
		{
			int sum=0; //here initialize the value on matrix3[i][j]

			for(int k=0; k<col1/*row2=col1*/; ++k)
			{
				sum+= *((*(p1+i))+k) * *((*(p2+k))+j);
				//m3[i][j] += m1[i][k] * m2[k][j] // m1 col loop, m2 row loop
			}

			*((*(p3+i))+j) = sum;
		}

	}

}

