//
//  main.c
//  loop
//
//  Created by qinghe on 20/10/2023.
//
#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int day;
    int day_of_week,total_days;
    
    printf("0 Sun, 1 Mon, 2 Tue, 3 Wed, 4 Thu, 5 Fri, 6 Sat\n"
           "please choose a day of week, and enter the number: ");
    scanf("%d", &day_of_week);
    
    printf("How many days does the month have: ");
    scanf("%d", &total_days);
    
 
    
    printf("Su Mo Tu We Th Fr Sa\n");
    
    for(day=1; day<= day_of_week; ++day)
        {
            printf("   ");
        }
    
    for(day=1; day<=total_days; ++day)
    {
        if (day<10)
        {
            printf(" %d ", day);
        }
        
        else
        {
            printf("%d ", day);
        }
        
        if ((day + day_of_week) % 7 == 0 || day == total_days)
        {
            printf("\n");
        }
     }
            
    return 0;
}
    

