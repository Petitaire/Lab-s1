#include <stdio.h>

/* 1^k + 2^k + 3^k +... n^k (求1-n的k次方）*/
int power(int base, int pow);

int main(void) {
    
    int n,k;
    int result = 0;
    
    printf("please enter two integers: ");
    scanf("%d %d", &n, &k);
    
    for(int i=1;i<=n;++i)
    {
        result += power(i,k);
    }
 
    printf("%d\n",result);
    
    return 0;
}

int power(int base, int pow)
{
    int result = 1;

    for(int i=0; i<pow; ++i)
    {
        result *= base;
    }

    return result;
}

