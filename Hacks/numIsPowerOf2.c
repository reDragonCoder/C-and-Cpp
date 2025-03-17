// Program to check if a number is a power of 2 in a single line
/* Explanation: the expression (n && !(n & (n-1))) checks if n is a power of 2.
   Then, n && ensures n is not zero. The bitwise n & (n-1) clears the rightmost
   set bit, which is 0 only for powers of 2 (since they have a single set bit).
   The ! negates it to return true if n is a power of 2. The method works in 
   constant time*/ 

#include <stdio.h>

int main(){
    int n=0;

    printf("Enter your number: ");
    scanf("%d", &n);

    if((n && !(n & (n-1)))){
        printf("The number you entered is a power of 2");
    }else{
        printf("The number you entered is NOT a power of 2");
    }

    return 0;
}