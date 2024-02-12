#include<stdio.h>

int main(){
  //task 1: print my name
    printf("My name is QZ.\n");

  //task 2: print a character and its ASCII value
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    printf("%c %d\n",c, c); 
  
  //task 3: calculate sum of two integers
    int a, b, sum;
    float quotient;
    printf("Enter two integer: ");
    scanf("%d %d", &a, &b);
    sum = a + b;
    printf("The sum of %d and %d is %d\n", a, b, sum);
  
  //task4: calculate the quotient of two float numbers, print the numbers as float and integer
    float num1, num2, result;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    printf("The numbers you entered are [floats]: %.2f %.2f\n", num1, num2);
    printf("The numbers you entered are [integers]: %d %d\n", (int)num1, (int)num2);
    result = num1 / num2;
    printf("%.2f divides %.2f is %.2f\n", num1, num2, result);

return 0;
}
