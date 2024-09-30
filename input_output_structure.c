//
//  main.c
//  Array_Pointer
//
//  Created by qinghe on 30/10/2023.
//

#include <stdio.h>
#include <stdlib.h>

// structure & pointer: input and output data
// for not fixed size

struct person
{
    char name[20];      //restric the length of name
    int age;
};

int main(int argc, const char * argv[]) {
    
    struct person *p;  //create variable (pointer)
    int i,n;
    
    printf("please enter the number of person: ");  //define the size of structure
    scanf("%d", &n);
    
    p = (struct person*)malloc(n*sizeof(struct person)); //allocate enough size for pointer p
    
    for(i=0;i<n;++i)                                    //input n 个 names 和 n 个 ages
    {
        printf("Enter name (space) age: ");
        scanf("%s %d", (p+i)->name, &(p+i)->age);
    }
    //char 不需要&来赋值
    //(p)->name 表示 structure中name的第1个元素
    //(p+1)->name 表示 structure中name的第2个元素
    //(p+n-1)->name 表示 structure中name的第n个元素
    
    printf("Information you entered: \n");
    for(i=0;i<n;++i)
    {
        printf("Name: %s, Age: %d \n", (p+i)->name, (p+i)->age);
    }
    
    free(p);
    
    
   return 0;
}
    
//when the size is fixed

/*
 struct person[100];      (no more than 100 persons in structure)
 
 if enter number > 100, return 1, program ends.
 
 if enter number < 100
 for(i=0;i<n;++i)
 {
     printf("Enter name (space) age: ");
     scanf("%s %d", person[i].name, person[i].age);     （与pointer不同的赋值方法）
 }
 
 */



