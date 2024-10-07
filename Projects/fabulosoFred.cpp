// Author: reDragonCoder 

//LIBRERIAS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h> //Libreria para "cls" y numeros aleatorios
#include <time.h> //Libreria para los numeros aleatorios
#include <stdbool.h>
//Colores
#define RED "\x1b[2;31m"
#define BRED "\e[1;31m"
#define GREEN "\x1b[2;32m"
#define BGRN "\e[1;32m"
#define YELLOW "\x1b[2;33m"
#define BYEL "\e[1;33m"
#define BLUE "\x1b[2;34m"
#define BBLU "\e[1;34m"
#define MAGNETA "\x1b[2;35m"
#define BMAG "\e[1;35m"
#define TEAL "\033[2;36m"
#define BTEAL "\e[1;36m"
#define WHT "\e[0;37m"
#define BHWHT "\e[1;97m"
//Reset a colores normal
#define RESET "\x1b[0m"

void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

void menu(); //Funcion para el menu del principio

#define TAM 3 //Tamaño de las matrices (3x3)

//MAIN
int main(){
    system("cls"); //Limpiar pantalla antes de iniciar el programa
    srand(time(NULL)); //Iniciar numeros aleatorios
    int matRed[TAM][TAM], matGrn[TAM][TAM], matYel[TAM][TAM], matBlu[TAM][TAM], matMag[TAM][TAM], matTEAL[TAM][TAM]; //Matrices que se van a necesitar
    int numero_aleatorio = 0; //Guardar el numero aleatorio que sale de rand()
    int lista[30]; //En donde se van a guardar los numeros aleatorios
    int nivel = 1; //Numero de niveles y patrones que va a tener el juego
    int valor = 0; //Numero con el que se va evaluar al pedir el patron 
    int contador_niveles = 1; //Para saber en que nivel estamos
    int puntos=0; //Para saber el puntaje del usuario
    bool bandera_red = false, bandera_green = false, bandera_yellow = false, bandera_blue = false, bandera_mag = false, bandera_teal = false; //Banderas para los colores
    bool bandera_perder = false;
    int i = 0; //Para el ciclo do-while
    int record = 0; //Para ver el puntaje mas alto
    int exit = 0; //Para salir

    menu(); //Se llama a la funcion

    for (int i = 0; i < TAM; i++){ //Ciclo para llenar las matrices con '0'
        for (int j = 0; j < TAM; j++) {
            matRed[i][j] = 0; 
            matGrn[i][j] = 0;
            matYel[i][j] = 0;
            matBlu[i][j] = 0;
            matMag[i][j] = 0;
            matTEAL[i][j] = 0;
        }
    }

    do { //Ciclo para los niveles
        
        printf(BHWHT "Nivel actual: %d", contador_niveles++);
        Sleep(2000);
        system("cls"); //Limpiar pantalla despues de pasar nivel
        for (int j = 0; j < 30; j++){ //limpiar la lista cuando cambie de nivel
            lista[j] = 0;
        } 

        for (int i = 0;  i < nivel; i++){ //Llenado de la lista
            numero_aleatorio = rand() % 7; //Se crea numeros desde 1 a 6 (Corresponde a los colores, matrices)
            if (numero_aleatorio != 0){ //Se llena solo si no es '0'
                lista[i] = numero_aleatorio;
            }
            else{ //Si es '0' se mantiene en la misma posicion de lista
                i--;
            }
        }

        //Ciclo numeros en las matrices
        for (int i = 0; i < nivel; i++){
        switch (lista[i]){
            case 1:
                matRed[1][1] = 1;
                bandera_red = true; //Se activa la bandera de esa matriz
                break;
            case 2:
                matGrn[1][1] = 2;
                bandera_green = true; //Se activa la bandera de esa matriz
                break;
            case 3:
                matYel[1][1] = 3;
                bandera_yellow = true; //Se activa la bandera de esa matriz
                break;
            case 4:
                matBlu[1][1] = 4;
                bandera_blue = true; //Se activa la bandera de esa matriz
                break;
            case 5:
                matMag[1][1] = 5;
                bandera_mag = true; //Se activa la bandera de esa matriz
                break;
            case 6:
                matTEAL[1][1] = 6;
                bandera_teal = true; //Se activa la bandera de esa matriz
                break;
            default:
                break;
        }

        //Mostrar la primera linea de matrices
        for (int r = 0; r < TAM; r++){
            for (int c = 0; c < TAM; c++){ //Matriz "Red"
                if (bandera_red == true){ //En caso de que la bandera este activa
                    printf(BRED "%d ", matRed[r][c]); //Se imprime las posiciones de la matriz con el color correspondiente
                    if(r==TAM-1 && c==TAM-1){
                        Sleep(.5);
                        Beep(450,750);
                    }
                }
                else{
                    printf(RED "%d ", matRed[r][c]); //Si la bandera no esta activa entonces se imprime normal
                }
                printf(RESET); //Se vuelve al color normal del programa
            }
            printf("\t");
            for (int c = 0; c < TAM; c++){ //Matriz "Green"
                if (bandera_green == true){ //En caso de que la bandera este activa
                    printf(BGRN "%d ", matGrn[r][c]); //Se imprime las posiciones de la matriz con el color correspondiente
                    if(r==TAM-1 && c==TAM-1){
                        Sleep(.5);
                        Beep(500,750);
                    }
                }
                else{
                    printf(GREEN "%d ", matGrn[r][c]); //Si la bandera no esta activa entonces se imprime normal
                }
                printf(RESET); //Se vuelve al color normal del programa
            }
            printf("\t");
            for (int c = 0; c < TAM; c++){ //Matriz "Yellow"
                if (bandera_yellow == true){ //En caso de que la bandera este activa
                    printf(BYEL "%d ", matYel[r][c]); //Se imprime las posiciones de la matriz con el color correspondiente
                    if(r==TAM-1 && c==TAM-1){
                        Sleep(.5);
                        Beep(550,750);
                    }
                }
                else{
                    printf(YELLOW "%d ", matYel[r][c]); //Si la bandera no esta activa entonces se imprime normal
                }
                printf(RESET); //Se vuelve al color normal del programa
            }
            printf("\n"); //Salto de linea entre cada renglon que se imprima
        }
        printf("\n"); //Salto de linea entre las dos lineas de matrices

        //Mostrar la segunda linea de matrices
        for (int r = 0; r < TAM; r++){
            for (int c = 0; c < TAM; c++){ //Matriz "Blue"
                if (bandera_blue == true){ //En caso de que la bandera este activa
                    printf(BBLU "%d ", matBlu[r][c]); //Se imprime las posiciones de la matriz con el color correspondiente
                    if(r==TAM-1 && c==TAM-1){
                        Sleep(.5);
                        Beep(600,750);
                    }
                }
                else{
                    printf(BLUE "%d ", matBlu[r][c]); //Si la bandera no esta activa entonces se imprime normal
                }
                printf(RESET); //Se vuelve al color normal del programa
            }
            printf("\t");
            for (int c = 0; c < TAM; c++){ //Matriz "Mag"
                if (bandera_mag == true){ //En caso de que la bandera este activa
                    printf(BMAG "%d ", matMag[r][c]); //Se imprime las posiciones de la matriz con el color correspondiente
                    if(r==TAM-1 && c==TAM-1){
                        Sleep(.5);
                        Beep(650,750);
                    }
                }
                else{
                    printf(MAGNETA "%d ", matMag[r][c]); //Si la bandera no esta activa entonces se imprime normal
                }
                printf(RESET); //Se vuelve al color normal del programa
            }
            printf("\t");
            for (int c = 0; c < TAM; c++){ //Matriz "TEAL"
                if (bandera_teal == true){ //En caso de que la bandera este activa
                    printf(BTEAL "%d ", matTEAL[r][c]); //Se imprime las posiciones de la matriz con el color correspondiente
                    if(r==TAM-1 && c==TAM-1){
                        Sleep(.5);
                        Beep(700,750);
                    }
                }
                else{
                    printf(TEAL "%d ", matTEAL[r][c]); //Si la bandera no esta activa entonces se imprime normal
                }
                printf(RESET); //Se vuelve al color normal del programa
            }
            printf("\n"); //Salto de linea entre cada renglon que se imprima
        }

        Sleep(2500); //Tiempo entre cada muestra
        system("cls"); //Se borra la pantalla tras mostrar las 6 matrices

        for (int i = 0; i < TAM; i++) { //Llenar matrices con '0' despues de cada corrida
            for (int j = 0; j < TAM; j++) {
                matRed[i][j] = 0; 
                matGrn[i][j] = 0;
                matYel[i][j] = 0;
                matBlu[i][j] = 0;
                matMag[i][j] = 0;
                matTEAL[i][j] = 0;
            }
        }
        //Resetear las banderas
        bandera_red = false;
        bandera_green = false;
        bandera_yellow = false;
        bandera_blue = false;
        bandera_mag = false;
        bandera_teal = false;
        } 

        for (int j = 0; j < nivel; j++){ //Evaluar lista con entrada de teclado
            printf(BHWHT "Dame los numeros \n"); //Se pide el valor
            scanf("%d", &valor);
            if (valor == lista[j]){ //Se evalua
                puntos+=10;
                if (puntos > record){
                    record = puntos;
                }
                switch(valor){
                    case 1:
                        Beep(450,750);
                        break;
                    case 2:
                        Beep(500,750);
                        break;
                    case 3:
                        Beep(550,750);
                        break;
                    case 4:
                        Beep(600,750);
                        break;
                    case 5:
                        Beep(650,750);
                        break;
                    case 6:
                        Beep(700,750);
                        break;
                }
                system("cls");
                continue;
            }
            else{
                printf(BRED "Fallaste, intenta de nuevo!\n"); //Mensaje por si fallaste
                Beep(300,1000); 
                Beep(200,800); 
                printf(BRED "Llegaste al nivel %d\n", --contador_niveles);
                printf(BHWHT "Tu puntuacion fue de: %d \n", puntos);
                printf(BTEAL "Tu puntaje mas grande fue: %d\n", record);
                bandera_perder = true;
                system("Pause\n");
            }
        }

        if (bandera_perder == false){
            nivel++; //Se repite el ciclo una vez mas 
            printf(BGRN "Felicidades, has pasado el nivel!\n");
            printf(BHWHT "Tu puntuacion actual es: %d \n", puntos);
            printf("Quieres continuar\n");
            printf("1) Si\n");
            printf("2) No\n");
            fflush(stdin);
            scanf("%d", &exit);
            if (exit == 2){
                printf(BRED "Llegaste al nivel %d\n", --contador_niveles);
                printf(BTEAL "Tu puntaje mas grande fue: %d\n", record);
                return 0;
            }
            system("cls");
        }
        else if (bandera_perder == true){
            printf("Quieres continuar\n");
            printf("1) Si\n");
            printf("2) No\n");
            fflush(stdin);
            scanf("%d", &exit);
            if (exit == 2){
                printf(BRED "Llegaste al nivel %d\n", --contador_niveles);
                printf(BTEAL "Tu puntaje mas grande fue: %d\n", record);
                return 0;
            }
            valor = 0;
            nivel = 1;
            contador_niveles = 1;
            puntos = 0;
            system("cls");
        }
        bandera_perder = false;
    } while (i < nivel);

    return 0; 
}

void menu(){ //Menu
    ShowConsoleCursor(false);
    for(int i=0; i<1; i++){
        system("cls");
        printf(BHWHT "BIENVENIDO A 'EL FABULOSO FRED'");
        Beep(500,750);
        Sleep(5);
            
        system("cls");
        printf(WHT "BIENVENIDO A 'EL FABULOSO FRED'");
        Beep(450,750);
        Sleep(5); 
                
        system("cls");
        printf(BHWHT "BIENVENIDO A 'EL FABULOSO FRED'");
        Beep(500,750);
        Sleep(5);
                    
        system("cls");
        printf(WHT "BIENVENIDO A 'EL FABULOSO FRED'");
        Beep(450,750);
        Sleep(5);

        system("cls");
        printf(BHWHT "BIENVENIDO A 'EL FABULOSO FRED'");
        Beep(500,750);
        Sleep(5);
    }
    printf("\n");
    printf(WHT "\t Made by:\n");
    printf(BMAG "\t reDragonCoder\n" RESET);

    system("pause");
    system("cls");
}