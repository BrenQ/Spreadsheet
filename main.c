#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cell.h"
#include "Spreadsheet.h"

int main() {

	float valor4 = 20.0;
	float valor5 = 38.4;
	float valor6 = 65.5;
	float valor7 = 30.0;
	char * palabra = "Hola";
	char * formula = "=sum(A1:A31)";
	char * functionavg = "=sum(A1:A3)";
        char * functioncountif = "=COUNTIF(A1:A3)";


	SpreadSheet s;
	init(&s);
	setNumber(&s, "A1", &valor6, sizeof(float));
	setNumber(&s, "A2", &valor5, sizeof(float));
	setNumber(&s, "A3", &valor4, sizeof(float));
	setNumber(&s, "A12", &valor5, sizeof(float));
	setNumber(&s, "B1", &valor7, sizeof(int));
        
        setNumber(&s, "C4", &valor7, sizeof(int));
	setLabel(&s, "C1", palabra);
	setSummatory(&s, "C2", formula);	
	setAverage(&s, "C3", functionavg);
	setCountIf(&s,"C5", functioncountif,">=5");

	float dst;
	getSummatory(&s, "C2", &dst);
	
	printf("Sumatoria: %1.2f \n",dst);
	
	float avg;
        getAverage(&s, "C3", &avg);

	
	printf("Promedio: %1.2f \n",avg);
	
	int count;
	
	getCountIf(&s, "C5", ">",&valor5 ,sizeof(float),&count);
	
	printf("Valor:", count);
			
	get(&s, "B1", &dst);

}

