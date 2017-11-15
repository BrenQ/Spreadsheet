/*
 * Spreadsheet.c

 *
 *  Created on: Oct 13, 2017
 *      Author: alumno
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Spreadsheet.h"
#include "cell.h"
#define EXP_FUNC "%[^':']:%[^')']"

#define NUMBER "number"
#define FUNCTION "function"
#define TEXT "text"
#define RANGEVALUE 6  // Maxima cantidad de variaciones de rangos de celdas ZX5000

void init(SpreadSheet* s) {
	memset(s, 0x0, sizeof(SpreadSheet));
	s->cellsCount = 0;
}

void cleanUp(SpreadSheet* s) {
	if (s->cells) {
		Cell* current = s->cells;

		while ((current - s->cells) < s->cellsCount) {

			release(current);
			current += current->size;
		}

		free(s->cells);
	}

	s->cells = 0x0;
}

/**

 @param: s Es la hoja de calculo a la que hace referencia
 @param cellAddressStr Direccion de la celda a setear valor ( A8,C9)
 @Pparam v Es el valor al que se va actualizar f
 @param vsize es el tamaño del valor que vamos a setear
 **/
void setNumber(SpreadSheet* s, const char* cellAddresStr, const void* v, const unsigned vSize) {
	Cell * dst = 0x0;

	searchCelladdres(s, cellAddresStr, &dst);

	if (dst == 0x0) {
		Cell c;
		initCell(&c, cellAddresStr, v, vSize, NUMBER);
		s->cells = (Cell *) realloc(s->cells,
				(s->cellsCount + 1) * sizeof(Cell));
		s->cells[s->cellsCount] = *(Cell*) malloc(sizeof(Cell));
		s->cells[s->cellsCount] = c;
		s->cellsCount++;

	} else {

		setValue(dst, v, vSize, NUMBER);

	}

}

/**
 * Busca el puntero de la celda indicada
 *
 * */
void * searchCelladdres(SpreadSheet * s, const char * cellAddresStr, Cell ** dst) {
	Cell * current = s->cells;
	int i = 0;
	while ((current - s->cells) < s->cellsCount) {

		if (strcmp(current->cellAddress, cellAddresStr) == 0) {
			*dst = current;
			return 0;
		}
		current++;
		i++;
	}

	return 0x0;
}

/**
 Label es la etiqueta de la columna
 @param s Hoja de calculo
 @param cellAddressStr es la direccion de la celda A4
 @param v es el valor de la columna

 **/
void setLabel(SpreadSheet* s, const char* cellAddresStr, const char* v) {

	Cell * dst = 0x0;

	searchCelladdres(s, cellAddresStr, &dst);

	if (dst == 0x0) {
		Cell c;
		initCell(&c, cellAddresStr, v, strlen(v), TEXT);
		s->cells = (Cell *) realloc(s->cells,
				(s->cellsCount + 1) * sizeof(Cell));
		s->cells[s->cellsCount] = *(Cell*) malloc(sizeof(Cell));
		s->cells[s->cellsCount] = c;
		s->cellsCount++;

	} else {

		setValue(dst, v, strlen(v), "text");

	}

}

/**
 Almacena una funcion en la hoja de calculo
 @param s Hoja de calculo
 @param cellAdressStr Direccion de la celda
 @param cellAdressFunction Funcion almacenada en la celda
 **/

void setFunction(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressFunction) {

	Cell * dst = 0x0;

	searchCelladdres(s, cellAddressStr, &dst);

	if (dst == 0x0) {
		Cell c;
		initCell(&c, cellAddressStr, cellAddressFunction,
				strlen(cellAddressFunction) + 1, FUNCTION);
		s->cells = (Cell *) realloc(s->cells,
				(s->cellsCount + 1) * sizeof(Cell));
		s->cells[s->cellsCount] = *(Cell*) malloc(sizeof(Cell));
		s->cells[s->cellsCount] = c;
		s->cellsCount++;

	} else {
		setValue(dst, cellAddressFunction, strlen(cellAddressFunction),
				FUNCTION);
	}

}

/**
 Selecciona una celda de la hoja de calculo y
 @param s Hoja de calculo
 @param cellAdressStr Direccion de la celda
 @param cellAdressRefrenceStr Referencia a direccion de la celda

 **/
void setIdentity(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressReferenceStr) {
	setFunction(s, cellAddressStr, cellAddressReferenceStr);
}

/**
 Almacena la funcion de suma

 @param s Hoja de calculo
 @param cellAddressStr Direccion de la celda donde se realiza el calculo
 @param cellAddressStr Rango de la direccion de la celda para sumar

 **/
void setSummatory(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressRangeStr) {

	setFunction(s, cellAddressStr, cellAddressRangeStr);
}

/**
 Selecciona un rango de direcciones de Celda

 @param s Hoja de calculo
 @param cellAddressStr Direccion de la celda donde se realiza el calculo
 @param cellAddressStr Rango de la direccion de la celda para realizar el promedio

 **/

void setAverage(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressRangeStr) {
	setFunction(s, cellAddressStr, cellAddressRangeStr);
}

/**
 Almacena la funcion en la celda 

 @param s Hoja de calculo
 @param cellAddressStr Direccion de la celda
 @param cellAddressStr Rango de la direccion de la celda para contar.si

 **/

void setCountIf(SpreadSheet* s, const char * cellAddressStr,
		const char * cellAddressRangeStr) {
	setFunction(s, cellAddressStr, cellAddressRangeStr);
}

/**

 Devuelve el valor de una direccion de celda

 @param s Hoja de calculo
 @param cellAddressStr Direccion de la celda
 @param dst Retorno donde almacenar el valor de una celda

 **/
void get(SpreadSheet* s, const char* cellAddressStr, void* dst) {
	Cell * ptr;
	searchCelladdres(s, cellAddressStr, &ptr);
	memcpy(dst, ptr->value, ptr->size);

}

/**
 Devuelve el valor de la funcion identidad almacenada en una direccion de memoria
 @param s Hoja de calculo
 @param cellAddressStr Direccion de la celda
 @param dst Puntero a variable que permite almacenar el valor de retorno

 **/

void getIdentity(SpreadSheet* s, const char* cellAddressStr, void* dst) {

	Cell * ptr;

	searchCelladdres(s, cellAddressStr, &ptr);

	searchCelladdres(s, ptr->value, &ptr);

	memcpy(dst, ptr->value, ptr->size);
}

/**
 Devuelve el valor de la funcion sumatoria almacenada en una direccion de memoria
 @param s Hoja de calculo
 @param cellAddressStr Direccion de la celda
 @param dst Puntero a variable que permite almacenar el valor de retorno

 **/

void getSummatory(SpreadSheet* s, const char* cellAddressStr, void* dst) {
	Cell * ptr;
	double sumatory = 0.0;
	char iRangeLet[RANGEVALUE] = "";
	char fRangeLet[RANGEVALUE] = "";
	searchCelladdres(s, cellAddressStr, &ptr);
	obtainRange((char*) ptr->value, iRangeLet, fRangeLet);

	Cell * current = s->cells;
	int i = 0;
	while ((current - s->cells) < s->cellsCount) {
		if (strverscmp(iRangeLet, current->cellAddress) <= 0
				&& strverscmp(current->cellAddress, fRangeLet) <= 0) {
			if (current->size == sizeof(int)){
				int aux = *((int*) (current->value));
				sumatory += (double) aux;
			} else if (current->size == sizeof(double)){
				sumatory += *(double*) (current->value);
			}
		}
		current++;
		i++;

	}
	memcpy(dst, &sumatory, sizeof(double));

}

// Realiza un split de los rangos de las celdas 

void obtainRange(char* rangeStr, char* minRange, char* maxRange) {

	char* iRangeLet = minRange;
	char* fRangeLet = maxRange;
	sscanf(rangeStr, EXP_FUNC, iRangeLet, fRangeLet);
	return;
}

/**
 Devuelve el valor de la funcion promedio almacenada en una direccion de memoria
 @param s Hoja de calculo
 @param cellAddressStr Direccion de la celda
 @param dst Puntero a variable que permite almacenar el valor de retorno

 **/

void getAverage(SpreadSheet* s, const char* cellAddressStr, void* dst) {

	Cell * ptr;
	double sumatory = 0.0;
	double average = 0.0;
	char iRangeLet[RANGEVALUE] = "";
	char fRangeLet[RANGEVALUE] = "";
	searchCelladdres(s, cellAddressStr, &ptr);
	obtainRange((char*) ptr->value, iRangeLet, fRangeLet);

	Cell * current = s->cells;
	double count = 0.0;
	while ((current - s->cells) < s->cellsCount) {
		if (strverscmp(iRangeLet, current->cellAddress) <= 0
				&& strverscmp(current->cellAddress, fRangeLet) <= 0){
			if (current->size == sizeof(int)){
				int aux = *((int*) (current->value));
				sumatory += (double) aux;
			} else if (current->size == sizeof(double)){
				sumatory += *(double*) (current->value);
			}
			count++;
		}
		current++;
	}

	average = sumatory / count;
	memcpy(dst, &average, sizeof(double));

}

/**
 Devuelve el valor de la funcion contar.si almacenada en una direccion de memoria
 @param s Hoja de calculo
 @param cellAddressStr Direccion de la celda
 @param dst Puntero a variable que permite almacenar el valor de retorno

 **/

void getCountIf(SpreadSheet* s, const char * cellAddressStr,
		const char * condition, const void * v, const unsigned vSize, int * dst) {

	Cell * ptr;
	char iRangeLet[RANGEVALUE] = "";
	char fRangeLet[RANGEVALUE] = "";
	int result = 0;
	int count = 0;
	searchCelladdres(s, cellAddressStr, &ptr);
	obtainRange((char*) ptr->value, iRangeLet, fRangeLet);

	Cell * current = s->cells;

	while ((current - s->cells) < s->cellsCount) {
		if (strcmp(current->type, FUNCTION) != 0
				&& strverscmp(iRangeLet, current->cellAddress) <= 0
				&& strverscmp(current->cellAddress, fRangeLet) <= 0) {

			result = memcmp(current->value, v, vSize);

			conditionResult(condition, result, &count);
		}
		current++;

	}

	memcpy(dst, &count, sizeof(int));
}

void conditionResult(const char * condition, int result, int * dst) {

	if (strcmp(">=", condition) == 0 && result >= 0) {
		(*dst)++;
	} else if (strcmp("<=", condition) == 0 && result >= 0) {
		(*dst)++;
	} else if (strcmp("<", condition) == 0 && result < 0) {
		(*dst)++;
	} else if (strcmp(">", condition) == 0 && result > 0) {
		(*dst)++;
	} else if (strcmp("=", condition) == 0 && result == 0) {
		(*dst)++;
	} else if (strcmp("<>", condition) == 0 && result != 0) {
		(*dst)++;
	}

}
