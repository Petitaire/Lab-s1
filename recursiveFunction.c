//
//  main.c
//  loop
//
//  Created by qinghe on 20/10/2023.
//
#include <stdio.h>
#include <stdlib.h>

int power_recursion(int base, int N);
int power_multiplication(int base, int N);
int power_recursion2(int base, int N);

int main (int argc, char *argv[]) {
    
    //take an input for a command line parameter
    if (argc<2)
    {
        printf("error.\n");
    }
    else
    {
        int N = atoi(argv[1]);
        printf("The input integer is: %d", N);
        int base = 2;
        int result;
        
        //task 2
        result = power_recursion(base, N);
        printf("the %d power of %d is %d. \n", N, base, result);
        
        //task 3
        result = power_multiplication (base, N);
        printf("the %d power of %d is %d. \n", N, base, result);
        
        return 0;
    }
}

//function

// a more efficient recursive method
// if we separate even and odd N, there'll be less recursive call
int power_recursion(int base, int N) 
{
    if (N == 0)
    {
        return 1;
    }
    else if (N%2 == 0)
    {
        return power_recursion(base, N/2) * power_recursion(base, N/2);
    }
    else return base * power_recursion(base, (N-1)/2) * power_recursion(base, (N-1)/2);
}

// a simple recursive function
int power_recursion2(int base, int N)
{
    if (N==0)
    {
        return 1;
    }
    else
    {
        return base * power_recursion2(base, N-1);
    }
}

// without recursive: using loop >> multiplication of base
int power_multiplication(int base, int N)
{
    int i, result = 0;
    
    if (N == 0)
    {
        return 1;
    }
    
    else
    {
        for (i=1; i<=N; ++i)
        {
            result *= base;
        }
        
        return result;
    }
}
