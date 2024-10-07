// Author: reDragonCoder 

//LIBRARIES
#include <stdio.h>
#include <windows.h>

//FUNCTION PROTOTYPE
void hideCursor();

//MAIN
int main(){
    hideCursor();
    return 0;
}

//FUNCTION IMPLEMENTATION
void hideCursor(){ 
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize =100;
    cci.bVisible= FALSE; 
    SetConsoleCursorInfo(hcon,&cci);
}