/*	NOMBRE: Yosh Antony Perez Ixcot 3 en raya
	Carnet: 1490-18-17681
 	Curso: Inteligencia artifical 
 	Secc: A
*/
#include <stdio.h>
#include <iostream>
#include <cstdlib>

//prototipos
void r (char a [3][3]);
void valores  (char a [3][3]);
void tablero (char a [3][3]);
void ingresar (char a [3][3]);
void agente (char a [3][3]);
int ganar (char a [3] [3]);


//Main
int main () {
char a [3][3];
r  (a);
system ("pause");
return 0;
}

//bucle
void r (char a [3][3])
{
	int contador,g;
	
	contador = 0;
	
	valores (a);	
	do {
		system ("cls");
		tablero(a);
		
		if (contador % 2 == 0){
			ingresar (a);
		}else  {
		agente (a);
		}
		
		g = ganar (a);
		contador ++;
		
	} while (contador<=9 && g == 2);
		
	system ("cls");
	tablero(a);
	
	if (g==0){
		printf("HAS PERDIDO :(\n\n");
	} else if (g==1){
		printf("HAS GANADO!!! :) \n\n");
	}
	else {
		printf("EMPATE(\n\n");
	}
}

//valores para el tablero
void valores (char a [3][3]){
    int x,y;
    char contador;

    contador = '1';
    for (x = 0; x<3; x++){
        for (y = 0; y<3; y++){
        a[x][y] = contador++;
    }
    }
}

void tablero (char a [3][3]){
int x,y;
for (x = 0; x<3; x++){
        for (y = 0; y<3; y++){
            if (y<2)
			{
				printf (" %c |",a[x][y]);
				}else {
					printf (" %c",a[x][y]);
				}
    }   
    		if (x<2)
				{
				printf ("\n___________\n");
				}		
    }    
	printf ("\n\n\n");        
}

void ingresar (char a [3][3]){
		
	int x,y,resultado;
	char aux;
	
	do{
		do{
			printf ("Tu turno : ");
			fflush (stdin);
			scanf ("%c",&aux);
		}while (aux < '1' || aux > '9');
		
		resultado = 0;
		
		switch (aux){
			
			case '1':{
				x= 0;
				y= 0;
				if (a[x][y] == 'X' || a[x][y] == 'O'){
					resultado=1;
				printf ("CASILLA LLENA, intentalo otra vez\n\n");	
				}
				break;}
				
				case '2':{
				x= 0;
				y= 1;
				if (a[x][y] == 'X' || a[x][y] == 'O'){
					resultado=1;
				printf ("CASILLA LLENA, intentalo otra vez\n\n");	
				}
				break;}
				
				case '3':{
				x= 0;
				y= 2;
				if (a[x][y] == 'X' || a[x][y] == 'O'){
					resultado=1;
				printf ("CASILLA LLENA, intentalo otra vez\n\n");	
				}
				break;}
				
				case '4':{
				x= 1;
				y= 0;
				if (a[x][y] == 'X' || a[x][y] == 'O'){
					resultado=1;
				printf ("CASILLA LLENA, intentalo otra vez\n\n");	
				}
				break;}
				
				case '5':{
				x= 1;
				y= 1;
				if (a[x][y] == 'X' || a[x][y] == 'O'){
					resultado=1;
				printf ("CASILLA LLENA, intentalo otra vez\n\n");	
				}
				break;}
	
				case '6':{
				x= 1;
				y= 2;
				if (a[x][y] == 'X' || a[x][y] == 'O'){
					resultado=1;
				printf ("CASILLA LLENA, intentalo otra vez\n\n");	
				}
				break;}	
		
				case '7':{
				x= 2;
				y= 0;
				if (a[x][y] == 'X' || a[x][y] == 'O'){
					resultado=1;
				printf ("CASILLA LLENA, intentalo otra vez\n\n");	
				}
				break;}
		
				case '8':{
				x= 2;
				y= 1;
				if (a[x][y] == 'X' || a[x][y] == 'O'){
					resultado=1;
				printf ("CASILLA LLENA, intentalo otra vez\n\n");	
				}
				break;}
		
				case '9':{
				x= 2;
				y= 2;
				if (a[x][y] == 'X' || a[x][y] == 'O'){
					resultado=1;
				printf ("CASILLA LLENA, intentalo otra vez\n\n");	
				}
				break;}
		}
	} while (resultado == 1);
	a[x][y] = 'X';
}

void agente (char a [3][3]){
	int x, y, resultado;

	do {
	
	x = rand() % 3;
	y = rand() % 3;
	resultado = 0;
	
	if (a[x][y]	== 'X' || a[x][y]	== 'O'){
		resultado = 1;
	}
	} while (resultado == 1);
	a[x][y] = 'O';
}

int ganar (char a [3][3]){
	
	if (a [0][0] == 'X' || a [0][0] == 'O' ) {
	
	// 0  0  0
	// -  -  -
	// -  -  -	
	if (a [0][0] == a [0][1] && a [0][0] == a [0][2] ) {
		if (a [0][0] == 'X' ){
			return 1; //gana la persona
		}	else {
			return 0; //gana el agente
		}
		}
	//0
	//0
	//0	
	if (a [0][0] == a [1][0] && a [0][0] == a [2][0] ) {
		if (a [0][0] == 'X' ){
			return 1; //gana la persona
		}	else {
			return 0; //gana el agente
		}
	}	    
	}
	
		
	//0 - -
	//- 0 -
	//- - 0	
	if (a [1][1] == 'X' || a [1][1] == 'O' ) {
	
		if (a [1][1] == a [0][0] && a [1][1] == a [2][2] ) {
		if (a [1][1] == 'X' ){
			return 1; //gana la persona
		}	else {
			return 0; //gana el agente
		}
	}
	//- - -
	//0 0 0
	//- - -	
		if (a [1][1] == a [1][0] && a [1][1] == a [1][2] ) {
			if (a [1][1] == 'X' ){
			return 1; //gana la persona
		}	else {
			return 0; //gana el agente
		}
			
		}
		
		//- - 0
		//- 0 -
		//0 - -
 		
		if (a [1][1] == a [2][0] && a [1][1] == a [0][2] ) {
			if (a [1][1] == 'X' ){
			return 1; //gana la persona
		}	else {
			return 0; //gana el agente
		}	
		}
		
		//- 0 -
		//- 0 -
		//- 0 -
		
		if (a [1][1] == a [0][1] && a [1][1] == a [2][1] ) {
			if (a [1][1] == 'X' ){
			return 1; //gana la persona
		}	else {
			return 0; //gana el agente
		}	
		}		
	}
	
	
	if (a [2][2] == 'X' || a [2][2] == 'O' ) {
	
	//- - -
	//- - -
	//0 0 0
	if (a [2][2] == a [2][0] && a [2][2] == a [2][1] ) {
	if (a [2][2] == 'X' ){
			return 1; //gana la persona
		}	else {
			return 0; //gana el agente
		}
	}	
	
	//- - 0
	//- - 0
	//- - 0
	if (a [2][2] == a [0][2] && a [2][2] == a [1][2] ) {
	if (a [2][2] == 'X' ){
			return 1; //gana la persona
		}	else {
			return 0; //gana el agente
		}
	}
	}	
	return 2;      
}




