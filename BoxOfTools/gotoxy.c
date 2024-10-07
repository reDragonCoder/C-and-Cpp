// Author: reDragonCoder 

//LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//FUNCTION PROTOTYPE
void gotoxy(int,int);

//MAIN
int main(){
    gotoxy(30,4);
    printf("*");
    return 0;
}

//FUNCTION IMPLEMENTATION
void gotoxy(int x, int y){
    HANDLE manipulator;
    COORD coordinates;
    manipulator = GetStdHandle(STD_OUTPUT_HANDLE);
    coordinates.X=x;
    coordinates.Y=y;
    SetConsoleCursorPosition(manipulator,coordinates);
}