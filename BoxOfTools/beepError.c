// Author: reDragonCoder 

//LIBRARIES
#include <stdio.h>
#include <windows.h>

//MAIN
int main(){
   int n;
   printf("Enter 1 to do a beep \n");
   scanf("%d", &n);

   do{
      Beep(300,1000); 
      Sleep(.5);

      Beep(200,800); //change values to change sounds
      Sleep(.5);

   }while(n==8);
   return 0;
}