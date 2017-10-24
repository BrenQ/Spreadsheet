#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cell.h"
#include "Spreadsheet.h"

int main() {
	int valor5 = 38;
	float valor6 = 65.5;
	int valor7 = 30;
	char * palabra = "Hola";
	char * formula = "=sum(A1:A3)";

	SpreadSheet s;
	init(&s);
	setNumber(&s, "A1", &valor6, sizeof(float));
	setNumber(&s, "B1", &valor5, sizeof(int));
	setNumber(&s, "B1", &valor7, sizeof(int));
	setNumber(&s, "B1", &valor7, sizeof(int));
	setNumber(&s, "B1", &valor7, sizeof(int));
	setLabel(&s, "C1", palabra);
	setSummatory(&s, "C2", formula);

	int dst;
	getSummatory(&s, "C2", &dst);

	get(&s, "B1", &dst);

}

