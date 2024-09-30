#include <stdio.h>

/*A pair of newly born rabbits (one male, one female) is put in a field. (month 1, newborn = 1)
 Rabbits are able to mate at the age of one month (month 2, adult=1)
 so that at the END of the second month (= month 3) each pair produces one new pairs of rabbits
 (month 3, reproductive adult = 1, adult = 0, newborn = 1
 they never die.

The question represents a fibonacci sequence:
 
 month 0 = 0
 
 month 1 = 1(new born)
 
 month 2 = 1 (1 adult that can't reproduce yet)
 
 month 3 = 1+1=2(1 reproductive adult + 0 adult + 1 newborn )
 
 month 4 = 1+1+1 = 3 (1 reproductive adult + 1 adult + 1 newborn)
 
 month 5 = (1+1)+1+(1+1) = 5 (2 reproductive adult + 1 adult + 2 newborn)
 
 month 6 = (1+1+1)+(1+1)+(1+1+1) = (2+1)+2+(2+1) = 8 (3 reproductive adult + 2 adult + 3 newborn)
 
 month 7 = (1+1+1+1+1)+(1+1+1)+(1+1+1+1+1) = (3+2)+3+(3+2)= 13
 (5 reproductive adult + 3 adult + 5 newborn)
 
each month, reproductive adult = x, adult(newborn from last month)= y, newborn =x
next month, reproductive adult =(x+y), adult = x, newborn = (x+y)  */
 
int rabbitPairs(int month);

int main(void) {
    
    int month = 7;
    int result;
    result = rabbitPairs(month);
    printf("%d\n", result);
    
    return 0;
}

int rabbitPairs(int month)
{
    if (month==0)
        return 0;
    else if (month==1)
        return 1;
    else if (month==2)
        return 1;
    else
    return rabbitPairs(month-1)+rabbitPairs(month-2); /*Fibonacci sequence*/
}

/*also can return rabbitPairs(month-3)+2*rabbitPairs(month-2);*/
