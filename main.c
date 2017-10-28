#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cell.h"
#include "Spreadsheet.h"

int main() {
	
	char * titulo1 = "Productos";
	char * titulo2 = "Precio";
	char * titulo3= "Cantidad";

	float precio1 = 20.0;
	float precio2 = 38.4;
	float precio3 = 65.5;
	float precio4 = 30.0;
	
	int cantidad1 = 3;
        int cantidad2 = 2;
        int cantidad3 = 1;
        int cantidad4 = 3;

	
	char * producto1 = "Sal";
	char * producto2 = "Gaseosa";
	char * producto3 = "Fideos";
	char * producto4 = "Galletitas";

	
	char * sumatoria = "B2:B5";
	char * promedio = "B2:B5";
        char * countif = "C2:C5";


	SpreadSheet s;
	init(&s);
	// Almaceno los precios de los productos

	setNumber(&s, "B2", &precio1, sizeof(float));
	setNumber(&s, "B3", &precio2, sizeof(float));
	setNumber(&s, "B4", &precio3, sizeof(float));
	setNumber(&s, "B5", &precio4, sizeof(float));
	
	// Se indican las cantidades de productos comprados

	setNumber(&s, "C2", &cantidad1, sizeof(int));        
        setNumber(&s, "C3", &cantidad2, sizeof(int));
	setNumber(&s, "C4", &cantidad3, sizeof(int));
        setNumber(&s, "C5", &cantidad4, sizeof(int));
	
	// Completo los labels y textos
		
	setLabel(&s, "A1", titulo1);
	setLabel(&s, "B1", titulo2);
	setLabel(&s, "C1", titulo3);
	
	setLabel(&s, "A2", producto1);
        setLabel(&s, "A3", producto2);
        setLabel(&s, "A4", producto3);
	setLabel(&s, "A5", producto4);
	
	// Seteo las funciones en las celdas

	setSummatory(&s, "B6", sumatoria);	
	setAverage(&s, "B7", promedio);
	setCountIf(&s,"C6", countif);
	setIdentity(&s,"D6","C2");
	
	// Testeo de funciones
	
	float dst;
	getSummatory(&s, "B6", &dst);
	
	float avg;

        getAverage(&s, "B7", &avg);

	int count;
	
	getCountIf(&s, "C6", "=",&cantidad4 ,sizeof(int),&count);
	
	int id;
	
	getIdentity(&s,"D6",&id);
	
	int value ;
	get(&s,"C3",&value);
	
	cleanUp(&s);
}

