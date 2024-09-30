//
//  main.c
//  loop
//
//  Created by qinghe on 20/10/2023.
//
#include <math.h>
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    char letter;
    int i,j;
    
    for (letter= 'a'; letter <= 'g'; ++letter){
        
        //第一行letter = ‘a’，j只循环一次
        //第二行letter = ‘b’, j循环两次， ++j后 j ='b'
        for (j= 'a'; j<= letter; ++j){
            printf("%c ", j);
        }
        
        //第一行循环7次，letter = ‘a', (letter - 'a') = 0
        //第二行循环6次，letter = 'b', (letter - 'a') = 1
        for (i=1; i<= 7 - (letter - 'a'); ++i){
            printf("%d ",i);
        }
        
        printf("\n");
        
    }
  return 0;
}
    

