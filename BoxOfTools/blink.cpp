// Author: reDragonCoder 

//LIBRARIES
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <windows.h>

//FUNCTION
void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

//MAIN
int main(){
    ShowConsoleCursor(false);
    bool state=true;
    int counter=0;

    do{
        if(counter=5){
            system("cls");
            system("color 01");
            printf("text");
            Sleep(500);
            if(counter=10){
                system("cls");
                system("color 04");
                printf("text");
                Sleep(500); 
                if(counter=15){
                    system("cls");
                    system("color 06");
                    printf("text");
                    Sleep(500);
                    if(counter=20){
                        system("cls");
                        system("color 05");
                        printf("text");
                        counter=0;
                        Sleep(500);
                    }
                }
            }
        }
    counter++;
    }while(state=true);
    return 0;
}
