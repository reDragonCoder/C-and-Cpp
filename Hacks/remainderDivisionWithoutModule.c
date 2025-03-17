// The remainder of a division wothout using the % operator (only int numbers)
/*Explanation: the program finds the quotient (num / divisor), multiplies it
  byt the divisor, and substracts from num.*/

#include <stdio.h>

int main(){
    int num=0, divisor=0, remainder=0;

    printf("Enter your number: ");
    scanf("%d", &num);

    printf("Enter your divisor: ");
    scanf("%d", &divisor);

    remainder=num-(num/divisor)*divisor;
    printf("The remainder of the division is: %d", remainder);

    return 0;
}