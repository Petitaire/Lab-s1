#include <stdio.h>
#include <math.h>

float get_atan(float x);
float get_atan_approx(float x, int N);
float get_error(float a, float b);
int check_x(float x);
int check_N(int N);

int main() {
    
  //user input values
    float x;
    int N;
    do
    {
         printf("Enter the value to calculate: ");
            scanf("%f",&x);
    } while (check_x(x)==0);
    
    do
    {
        printf("Enter the number of sum elemetns to calculate atan_approx: ");
             scanf("%d",&N);
    } while (check_N(N)==0);
    

   //calculate atan by 2 methods
   
   float atan_1, atan_2;
   atan_1 = get_atan(x);
   atan_2 = get_atan_approx(x,N);
   
   printf("value of atan(%f) calculated by built-in function is: %f \n", x, atan_1);
    printf("value of atan(%f) calculated by approximation is: %f\n the number of elements used in approximation is: %d\n", x, atan_2, N);
    
    //calculate error
    
    float error;
     error = get_error(atan_1,atan_2);
     printf("the error between two atan values is: %e\n", error);

    return 0;
}

int check_x(float x)
{
    if((x<1)&&(x>-1))
    {
        return 1;
    }
    else
    {
        printf("Invalid input. Please enter x between -1 and 1.\n");
        return 0;
    }
}

int check_N(int N)
{
    if(N>=1)
    {
        return 1;
    }
    else
    {
         printf("Invalid input. Please enter N larger than 1.\n");
        return 0;
    }
}

float get_atan(float x)
{
    return atan(x);
}

float get_atan_approx(float x, int N)
{
    int n;
    float atan=0;
    
    for(n=0; n<N; ++n)
    {
          atan += pow(-1, n) * pow(x, 2*n+1)/(2*n+1);  
    }
    
    return atan;
    
}

float get_error(float a, float b)
{
    float error;
    if (a>b)
    {
        error = a-b;
    }
    else
    {
        error = b-a;
    }
    
    return error;
}