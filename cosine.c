#include <stdio.h>

int power(float base, int pow);
int fact(int n);
int isEven(int x); // n should be even, so that 2n+1 is odd, 2n is even;

int main(void) {
    
    int n,N;
    float sine= 0;
    int base = 2;
    printf("Enter the number of sum elements: ");
    scanf("%d", &N);
    
    /* add only even elements and skip the odd ones */
    for (n=0; n<N; ++n)
    {
       if(isEven(n))
           sine += power(2,2*n)/fact (2*n);
    }
    
    printf("%.2f", sine);
    
    return 0;
}

int power(float base, int pow)
{
    float result = 1;

    for (int i=0; i<pow; ++i)
        result *= base;
    
    return result;
}

int fact(int n)
{
    int result = 1;
    
    /* here loop can't start to multiply i from i=0, because the result will become 0 */
    for(int i=1; i<=n; ++i)
    {
        result *=i;
    }
    
    return result;
}

int isEven(int x)
{
    return (x%2==0)?1:0;
}




