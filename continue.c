//
//  main.c
//  loop
//
//  Created by qinghe on 20/10/2023.
//
#include <math.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    //to take 10 non negative numbers entered by user and calculate the sum
    
    int i=1;
    float num, sum=0;
    
    while (i<=10) // 不使用for,因为循环次数不一定等于10次，而是循环直到输入10个non negative为止
    {
        printf("enter a number: ");
        scanf("%f",&num);
        
        if (num<0){
            printf("error\n");
            continue;
            //如果输入的是negative，该数字continue到下一个阶段（跳出loop，不进行下一步sum）
            //loop返回到条件部分(i<10)
        }
        
        sum += num; //i=0时，
        ++i; //完成相加后，计数i增加一位
    }

   
    printf("the sum is: %f", sum);
    
  return 0;
}
    

