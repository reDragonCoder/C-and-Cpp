// Author: reDragonCoder & team

//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/*paleta de colores*/
#define ROJO "\x1b[31m"
#define VERDE "\x1b[32m"
#define AMARILLO "\x1b[33m"
#define AZUL "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define BLANCO "\x1b[37m"
#define NARANJA "\033[33m"

/*opcion de caracter*/
#define RESET "\x1b[0m"
#define BOLD "\x1b[1m"
#define DIM "\x1b[2m"

/*funcion gotoxy (coordenadas)*/
void gotoxy(int x, int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}

/*funcion hideCursor (ocultar cursor)*/
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//MAIN
int main() {
	/*declaracion de variables*/
    int height=0, opc_color=0, altura_aux=0, restante=0, restante2=0, restante3=0;
    int i=0, j=0;
	int x=40;
	int y=10;
	int stars=1;
	int starX=0, starY=0; 
	/*pedir altura al usuario*/
    printf("Introduce la altura del arbol (recuerda que la altura debe estar en un rango de 1 a 39): ");
    scanf("%d", &height);
    /*validar altura del arbol de 1 a 39*/
    if(height>0 && height<40){
    	/*imprimir menu de colores para la estrella*/
	    printf("1) Rojo \n");
	    printf("2) Amarillo \n");
	    printf("3) Azul \n");
	    printf("4) Magenta \n");
	    printf("5) Cyan \n");
	    /*pedir color de estrella al usuario*/
	    printf("Introduce el color de tu estrella: ");
	    scanf("%d", &opc_color);
	    /*recordar al usuario el uso de la funcion _kbhit*/
	    printf("Para detener el parpadeo de la estrella oprime cualquier tecla");
	    /*arbol=n+1*/
	    height++;
	    /*ciclo para imprimir el arbol*/
	    for (i = 0; i < height; i++) {
	    	/*imprimir arbol (contenido verde del arbol)*/
	    	/*do you mean leafs?*/
	        gotoxy(x, y);
	        for (j = 0; j < stars; j++) {
	            printf(VERDE "o" RESET);
	        }
	        printf("\n");
	        x--;
	        y++;
	        stars += 2;
	        /*imprimir estrella principal*/
	        if (i == 0) {
	        	/*imprimir estrella principal segun decision pedida al usuario y mensaje navide�o*/
	        	switch(opc_color){
	        		case 1:
	        			starX = x + 1; 
	            		starY = y - 1; 
	            		printf(ROJO "Feliz Navidad!" RESET);
	            		gotoxy(starX, starY);
	            		printf(ROJO BOLD"*" RESET);
	        			break;
	        		case 2:
	        			starX = x + 1; 
	            		starY = y - 1; 
	            		printf(AMARILLO "Feliz Navidad!" RESET);
	            		gotoxy(starX, starY);
	            		printf(AMARILLO BOLD"*" RESET);
	        			break;
	        		case 3:
	        			starX = x + 1; 
	            		starY = y - 1; 
	            		printf(AZUL "Feliz Navidad!" RESET);
	            		gotoxy(starX, starY);
	            		printf(AZUL BOLD"*" RESET);
	        			break;
	        		case 4:
	        			starX = x + 1; 
	            		starY = y - 1; 
	            		printf(MAGENTA "Feliz Navidad!" RESET);
	            		gotoxy(starX, starY);
	            		printf(MAGENTA BOLD"*" RESET);
	        			break;
	        		case 5:
	        			starX = x + 1; 
	            		starY = y - 1; 
	            		printf(CYAN "Feliz Navidad!" RESET);
	            		gotoxy(starX, starY);
	            		printf(CYAN BOLD"*" RESET);
	        			break;
				}
	        }
	    }
		
		/*imprimir tronquito*/
	    gotoxy(39, y);
	    printf(NARANJA "|||\n" RESET);
		
		/*regresar altura a su valor original*/
	    height-=1;
	    
	    /*la estrella parpadea solo si altura es menor a 27*/
	    /*la estrella secundaria y terciaria se calculan solo si altura es mayor a 27*/
	    /*calcular coordenadas de estrella secundaria y terciaria*/
	    if(height>10 && height<=27){
	    	altura_aux=(height/10)*10;
	        restante=height-altura_aux;
	        restante2=height-altura_aux;
	        if(restante>=9){
		        restante2-=1;
			}
			if(altura_aux>=20 && altura_aux<28){
				altura_aux=height/10;
				restante3=height-20;
				altura_aux+=restante3;
				restante2-=altura_aux;
			}
	        starY-=restante-restante2;
	    }
		
		/*la estrella parpadea solo si altura es menor a 27*/
		/*imprimir estrella secundaria y terciaria con el color elegido por el usuario (efecto parpadeo)*/
		if(height<=27){
			switch(opc_color){
		        case 1:
		        	do{
						hideCursor();
		    			for (i = 0; i < 10; i++) {
				        	gotoxy(starX, starY);
				        	_cputs(ROJO DIM"*" RESET);
				        	gotoxy(starX, starY);
				        	_cputs(ROJO BOLD"*" RESET);
						}	
					}while(!_kbhit());
		        	break;
		        case 2:
		        	do{
						hideCursor();
		    			for (i = 0; i < 10; i++) {
				        	gotoxy(starX, starY);
				        	_cputs(AMARILLO DIM"*" RESET);
				        	gotoxy(starX, starY);
				        	_cputs(AMARILLO BOLD"*" RESET);
						}	
					}while(!_kbhit());
		        	break;
		        case 3:
		        	do{
						hideCursor();
		    			for (i = 0; i < 10; i++) {
				        	gotoxy(starX, starY);
				        	_cputs(AZUL DIM"*" RESET);
				        	gotoxy(starX, starY);
				        	_cputs(AZUL BOLD"*" RESET);
						}	
					}while(!_kbhit());
		        	break;
		        case 4:
		        	do{
						hideCursor();
		    			for (i = 0; i < 10; i++) {
				        	gotoxy(starX, starY);
				        	_cputs(MAGENTA DIM"*" RESET);
				        	gotoxy(starX, starY);
				        	_cputs(MAGENTA BOLD"*" RESET);
						}	
					}while(!_kbhit());
		        	break;
		        case 5:
		        	do{
						hideCursor();
		    			for (i = 0; i < 10; i++) {
				        	gotoxy(starX, starY);
				        	_cputs(CYAN DIM"*" RESET);
				        	gotoxy(starX, starY);
				        	_cputs(CYAN BOLD"*" RESET);
						}	
					}while(!_kbhit());
		        	break;
			}
		}
		
		/*regresar al fin de linea del programa*/
		gotoxy(0, y + 2);
		printf("\033[0m"); 
	}
	/*imprimir error si la altura del arbol es mayor a 39*/
	else{
		printf(NARANJA "Por favor introduzca una altura valida!!" RESET);
	}
    return 0;
}



