#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc!=2 || atoi(argv[1])<1)
	{
		printf("Error. Please enter one positive integer.");
		exit(EXIT_FAILURE);
	}

	int size = atoi(argv[1]);
	int last_num=0;
	int i,j,k,col;
	int triangle[size][size];

	for(i=1; i<=size; ++i)
	{
		last_num += i;
	}

	
	/*create the triangle*/

	for(i=0; i<size; ++i)
	{
		col = 0;

		for(j=i; j>0; --j)
		{

			triangle[i][col] = 0;
			col++;
		}

		for(k=0; k<size-i; ++k)
		{
			triangle[i][col] = last_num;
			col++;
			last_num--;
		}
	}

	/*print the triangle*/

	for(i=0; i<size; ++i)
	{
		for(j=0; j<size; ++j)
		{
			printf("%-4d", triangle[i][j]);
		}

		printf("\n");
	}

/*create triangle without using array:	
 	for(i=0; i<size; ++i)
	{
		for(j=i; j>0; --j)
		{
			printf("0 ");
		}

		for(k=0; k<size-i; ++k)
		{
			printf("%d ", last_num);
			last_num-=1;
		}
		
		printf("\n");	
	}
*/

	return 0;
}
