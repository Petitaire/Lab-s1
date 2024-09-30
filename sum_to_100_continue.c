//
//  main.c
//  loop
//
//  Created by qinghe on 20/10/2023.
//
#include <stdio.h>

int main(void) {
    int result = 0, num, i = 1;
    int validResult = 0;

    while (result < 100) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if ((i % 2 == 1 && num % 2 != 1) || (i % 2 == 0 && num % 2 != 0)) {
            printf("Invalid input. ");
            continue;
        }

        validResult = result;
        result += num;
        ++i;
    }

    printf("The sum exceeds 100. The maximum sum is: %d\n", validResult);

    return 0;
}




