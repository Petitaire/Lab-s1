#include <stdio.h>

void initialize(int **p);
void display(int *p);
void multiplication(int *p1, int **p2);


void initialize(int **p)
{
    for(int i=0; i<4;++i)
    {
        for(int j=0; j<4; ++j)
        {
            printf("Please enter an integer value for [%d][%d]: ", i+1, j+1);
            scanf("%d", (*(p+i)+j));
        }
    }
}

void display(int *p)
{
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            printf("%-4d", (*(p+i)+j));
        }

        printf("\n");
    }
}

void multiplication(int *p1, int **p2)
{
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<4; ++j)
        {
            int sum = 0;
            for (int k=0; k<4; ++k)
                     {
                         sum += *(p1+i*4+k) * *(p1+k*4+j);
                     }
            *(p2+i*4+j) = &sum;
        }
    }
}


int main(void)
{
    int power;
    int matrix[4][4];
    int result[4][4];

    int *p1;
        p1 = &matrix[0][0];
    int *p2;
    p2 = &result[0][0];
    
    printf("Please enter the power(positive integer): ");
    scanf("%d", &power);

    /*initialize matrix*/
    printf("Please enter values for matrix\n");
    initialize(&p1);

    display(p1);

    multiplication(p1,&p2);

    printf("The result is:");
    display(p2);

    return 0;
}
