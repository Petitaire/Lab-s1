#include <stdio.h>

int check_prime(int x);

int main(void) {
    
    int count=0;

    for(int num=2; num<=100; ++num)
    {
        
        if(check_prime(num))
        {
            printf("%-5d ", num);
            ++count;
            
            if(count%5==0)
            {
                printf("\n");
            }
        }
    }
    
    return 0;
}

int check_prime(int x)
{
    if (x==2)
        return 1;
    for(int i=2; i<=x/2; ++i)
    {
        if (x%i==0)
            return 0;
    }
    return 1;
}

