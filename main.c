
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cell.h"
#include "Spreadsheet.h"

int main(){
	
	int valor5 = 38;
	float valor6 = 65.5;
	int valor7 = 30;
	char * palabra = "Hola";
	

	SpreadSheet s;
	init(&s);
	setNumber(&s,"A1",&valor6,sizeof(valor6));
	setNumber(&s,"B1",&valor5,sizeof(valor5));
	setNumber(&s,"B1",&valor7,sizeof(valor7));
	setLabel(&s,"C1",palabra);
       
        int  dst;

	get(&s,"B1",&dst);
     
}


