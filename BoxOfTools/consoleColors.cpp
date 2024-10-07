// Author: reDragonCoder 

//LIBRARIES
#include <iostream>
#include <windows.h>
#include <conio.h> 

//NAMESPACE
using namespace std;

//FUNCTIONS PROTOTYPES
void hideCursor();
void gotoxy(int,int);

//MAIN
int main(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int k=1; k <255; k++) { 
        SetConsoleTextAttribute(hConsole, k); 
        cout<<k<<"I want to be nice today!"<<endl; 
    }
}

//FUNCTIONS IMPLEMENTATIONS
void gotoxy(int x,int y){
    HANDLE hCon;
    hCon=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hCon,dwPos);
}

void hideCursor(){
    HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize=100;
    cci.bVisible=FALSE;	
    SetConsoleCursorInfo(hcon,&cci);
}