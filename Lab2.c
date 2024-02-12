#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int recursive(int base, int N);
int iterative(int base, int N);
int is_even (int N);

int main (int argc, char *argv[]) {
    
	int N;
	int base = 2;
        int result1, result2;


//use command line arguments

    if (argc<2)
    {
        printf("Input Error.\n");
    	exit(EXIT_FAILURE);
    }
    else
    {
         N = atoi(argv[1]);
         printf("The integer input is: %d\n", N);
    }

//calculate power in recursive way

          result1 = recursive(base, N);
          printf("(Recursive)the %d power of %d is %d. \n", N, base, result1);

//calculate power in iterative way
	  result2 = iterative(base, N);
          printf("(Iterative)the %d power of %d is %d. \n", N, base, result2);
	
    return 0;
}

//recursive function 

int is_even (int N)
{
	if(N%2==0)
		return 1;
	else 
		return 0;
}

int recursive(int base, int N)
{
	if(N == 0)
		return 1;

	else if(is_even(N))
		return pow(base,N/2)*pow(base,N/2);

	else
		return base*pow(base,(N-1)/2)*pow(base,(N-1)/2);
}

int iterative(int base, int N)
{
    int result = 1;

    if(N == 0)
        return 1;

    else if(is_even(N))
    {
        for(int i=0; i<N/2; ++i)
        {
            result *= base;
        }
        return result*result;
    }

    else
    {
        for(int i=0; i<(N-1)/2; ++i)
        {
            result *= base;
        }

        return base*result*result;
    }

}
