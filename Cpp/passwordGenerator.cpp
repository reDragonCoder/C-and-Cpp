//Author: reDragonCoder

//LIBRARIES
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

//MAIN
int main(){
    //RANDOM GENERATOR
    srand(time(NULL));

    //VARIABLES
    int length;
    char  *password=NULL, capital_letters, lowercase_letters, numbers, special_characters, option, character, anotherOne_SavedSettings='y', anotherOne_NotSavedSettings='y';
    
    cout<<endl<<"Welcome to your password generator!"<<endl;
    do{
        cout<<endl;
        cout<<"Please enter the desired length: ";
        cin>>length;
        if(length<=0){
            cout<<endl<<"ERROR: Not valid length";
            exit(1);
        }
        cout<<endl<<"--- PASSWORD OPTIONS ---"<<endl;
        cout<<"Do you want A-Z letters? (y/n): ";
        fflush(stdin);
        cin>>capital_letters;
        cout<<"Do you want a-z letters? (y/n): ";
        fflush(stdin);
        cin>>lowercase_letters;
        cout<<"Do you want 0-9 numbers? (y/n): ";
        fflush(stdin);
        cin>>numbers;
        cout<<"Finally, do you want special characters? (y/n): ";
        fflush(stdin);
        cin>>special_characters;
        
        do{
            password=(char*)malloc(length*sizeof(char));    
            if(capital_letters=='n' && lowercase_letters=='n' && numbers=='n' && special_characters=='n'){
                cout<<endl<<"ERROR: Not options selected, please try again";
                Sleep(1);
                break;
            }else{
                for(int i=0; i<length; i++){
                    option=rand()%4;
                    switch (option) {
                        case 0: //A-Z
                            if(capital_letters=='y'){
                                character=rand()%26+'A';
                                *(password+i)=character;
                            }else{
                                i--; // Retry this iteration
                            }
                            break;
                        case 1: //a-z
                            if(lowercase_letters=='y'){
                                character=rand()%26+'a';
                                *(password+i)=character;
                            }else{
                                i--; 
                            }
                            break;
                        case 2: //0-9
                            if(numbers=='y'){
                                character=rand()%10+'0';
                                *(password+i)=character;
                            }else{
                                i--; 
                            }
                            break;
                        case 3: //special character
                            if(special_characters=='y'){
                                character=rand()%10+33; 
                                *(password+i)=character;
                            }else{
                                i--; 
                            }
                            break;
                    }
                }
                cout<<endl<<"Your password is: "<<endl;
                for(int i=0; i<length; i++){
                    cout<<*(password+i);
                }
                free(password);
                cout<<endl;
                cout<<endl<<"Do you want to create another password with the SAME configuration? (y/n): ";
                fflush(stdin);
                cin>>anotherOne_SavedSettings;
            }
        }while(anotherOne_SavedSettings=='y');

        cout<<endl<<"Do you want to create another password with ANOTHER configuration? (y/n): ";
        fflush(stdin);
        cin>>anotherOne_NotSavedSettings;

        if(anotherOne_SavedSettings=='n' && anotherOne_NotSavedSettings=='n'){
            cout<<endl<<"Goodbye User!";
            Sleep(1);
        }

    }while(anotherOne_NotSavedSettings=='y');

    return 0;
}

