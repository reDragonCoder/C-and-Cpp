// Program to count the number of digits
/* Explanation: the formula digits=log10(n)+1 count the digits in a positive
   integer n since log10(n) gives its exponent in base 10. The integer part,
   floor(log10(n)), is one less than the digit count, so adding 1 gives the
   total.*/

#include <stdio.h>
#include <math.h>

int main(){
    long long int count = 0;
    long long int num = 0;

    printf("Enter your number: ");
    scanf("%lld", &num);

    // if its negative, it uses the absolute value
    if(num < 0){
        num = -num; 
    }

    if(num == 0){
        count = 1;
    } else {
        count = floor(log10(num)) + 1;
    }
    
    printf("The number of digits in your number is: %lld\n", count);
    return 0;
}
