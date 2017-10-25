#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cell.h"
#include "Spreadsheet.h"

int main() {

	int valor4 = 20;
	float valor5 = 38.4;
	float valor6 = 65.5;
	int valor7 = 30;
	char * palabra = "Hola";
	char * formula = "=sum(A1:A31)";

	SpreadSheet s;
	init(&s);
	setNumber(&s, "A1", &valor6, sizeof(float));
	setNumber(&s, "A2", &valor5, sizeof(float));
	setNumber(&s, "A3", &valor5, sizeof(int));
	setNumber(&s, "A12", &valor5, sizeof(int));
	setNumber(&s, "B1", &valor7, sizeof(int));
        
        setNumber(&s, "C4", &valor7, sizeof(int));
	setLabel(&s, "C1", palabra);
	setSummatory(&s, "C2", formula);

	float dst;
	getSummatory(&s, "C2", &dst);
	
	printf("%1.2f",dst);
	get(&s, "B1", &dst);

}

