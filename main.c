
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cell.h"
#include "Spreadsheet.h"

int main(){
/*
	Cell c;
	int valor1 = 35;
	int valor2 = 36;
	initCell(&c,"A1",&valor1,sizeof(valor1));
	//mostrar(&c);
	setValue(&c,"A1",&valor2,sizeof(valor2));
	//mostrar(&c);
	int * dst ;
	getValue(&c,"A1",&dst);
	// printf("%d\n",dst);
	//mostrar(&c);
	char * valor3 ="Suma";
	setValue(&c,"A1",&valor3,strlen(valor3));
	//mostrarString(&c);

	char * valor4 ="Resta";
	int valor5 = 6;

	Cell c2;
	initCell(&c2,"B1",&valor4,strlen(valor4));
	//mostrarString(&c2);

	Cell c3;

	initCell(&c3,"A2",&valor5,sizeof(valor5));
	//mostrar(&c3);

*/
	int valor5 = 38;
	float valor6 = 65.5;

	int valor7 = 30;
	
	char * palabra = "Hola";

	SpreadSheet s;
	init(&s);
	setNumber(&s,"A1",&valor6,sizeof(valor6));
	setNumber(&s,"B1",&valor5,sizeof(valor5));
	setNumber(&s,"B1",&valor7,sizeof(valor7));
     
}


