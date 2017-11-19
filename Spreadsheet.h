#ifndef SPREADSHEET_H_
#define SPREADSHEET_H_

#include "cell.h"

/**
 * Estructura de una hoja de calculo.
 *
 * @param cells Lista de celdas.
 * @param cellsCount Cantidad de celdas.
 */
typedef struct _SpreadSheet {
	Cell * cells;
	unsigned cellsCount;
} SpreadSheet;

/** 
 * Inicializa la hoja de calculo.
 *
 * @param: s Es la hoja de calculo a la que hace referencia.
 **/
void init(SpreadSheet* s);

/** 
 * Libera la memoria utilizada por la hoja de calculo.
 *
 * @param: s Es la hoja de calculo a la que hace referencia, no puede ser nulo.
 **/
void cleanUp(SpreadSheet* s);

/**
 * Introduce un numero en una celda.
 *
 * @param: s Es la hoja de calculo a la que hace referencia.
 * @param cellAddressStr Direccion de la celda a setear valor.
 * @param v Es el valor al que se va actualizar.
 * @param vsize es el tamaño del valor que vamos a setear.
 **/
void setNumber(SpreadSheet* s, const char* cellAddresStr, const void* v,
		const unsigned vSize);

/**
 * Introduce una etiqueta en una celda. Label es la etiqueta de la columna.
 *
 * @param s Hoja de calculo.
 * @param cellAddressStr es la direccion de la celda.
 * @param v es el valor de la columna.
 **/
void setLabel(SpreadSheet* s, const char* cellAddresStr, const char* v);

/**
 * Selecciona una celda de la hoja de calculo y la devuelve su puntero.
 *
 * @param s Hoja de calculo.
 * @param cellAdressStr Direccion de la celda.
 * @param cellAdressRefrenceStr Referencia a direccion de la celda.
 **/
void * searchCelladdres(SpreadSheet * s, const char * cellAddresStr,
		Cell ** dst);

/** 	
 * Almacena una funcion en la celda especifica.
 *
 * @param s Hoja de calculo.
 * @param cellAddressStr Es la direccion de la celda.
 * @param cellAddressFunction Funcion almacenada en la celda.
 **/
void setFunction(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressFunction);

/**
 * Almacena la funcion de identidad.
 *
 * @param s Hoja de calculo.
 * @param cellAdressStr Direccion de la celda.
 * @param cellAdressRefrenceStr Referencia a direccion de la celda.
 **/
void setIdentity(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressReferenceStr);

/**
 * Almacena la funcion de suma.
 *
 * @param s Hoja de calculo.
 * @param cellAddressStr Direccion de la celda donde se realiza el calculo.
 * @param cellAddressStr Rango de la direccion de la celda para sumar.
 **/
void setSummatory(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressRangeStr);

/**
 * Almacena la funcion de promedio.
 *
 * @param s Hoja de calculo.
 * @param cellAddressStr Direccion de la celda donde se realiza el calculo.
 * @param cellAddressStr Rango de la direccion de la celda para realizar el promedio.
 **/
void setAverage(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressRangeStr);

/**
 * Almacena la funcion de conteo de celdas si cumplen determinadas condiciones.
 *
 * @param s Hoja de calculo.
 * @param cellAddressStr Direccion de la celda.
 * @param cellAddressRangeStr Rango de la direccion de la celda para contar celdas.
 **/
void setCountIf(SpreadSheet* s, const char * cellAddressStr,
		const char * cellAddressRangeStr);

/**
 * Devuelve el puntero al valor de una direccion de celda.
 *
 * @param s Hoja de calculo.
 * @param cellAddressStr Direccion de la celda.
 * @param dst Retorno donde almacenar el valor de una celda.
 **/
void get(SpreadSheet* s, const char* cellAddresStr, void* dst);

/**
 * Devuelve el valor de la funcion identidad almacenada en una direccion de memoria.
 *
 * @param s Hoja de calculo.
 * @param cellAddressStr Direccion de la celda.
 * @param dst Puntero a variable que permite almacenar el valor de retorno.
 **/
void getIdentity(SpreadSheet* s, const char* cellAddresStr, void* dst);

/**
 * Devuelve el valor de la funcion sumatoria almacenada en una direccion de memoria.
 *
 * @param s Hoja de calculo.
 * @param cellAddressStr Direccion de la celda.
 * @param dst Puntero a variable que permite almacenar el valor de retorno.
 **/
void getSummatory(SpreadSheet* s, const char* cellAddressStr, void* dst);

/**
 * Devuelve el valor de la funcion promedio almacenada en una direccion de memoria.
 *
 * @param s Hoja de calculo.
 * @param cellAddressStr Direccion de la celda.
 * @param dst Puntero a variable que permite almacenar el valor de retorno.
 **/
void getAverage(SpreadSheet* s, const char* cellAddressStr, void* dst);

/**
 * Devuelve el valor de la funcion contar.si almacenada en una direccion de memoria.
 *
 * @param s Hoja de calculo.
 * @param cellAddressStr Direccion de la celda.
 * @param condition Tipo de condicion de la funcion.
 * @param v Valor de la condicion con la que se compara.
 * @param vSize Tamaño del valor.
 * @param int * dst Puntero donde se almacena la cantidad de elementos que cumplen la condicion.
 **/
void getCountIf(SpreadSheet* s, const char * cellAddressStr,
		const char * condition, const void * v, const unsigned vSize, int * dst);

/**
 * Devuelve el valor de la funcion promedio almacenada en una direccion de memoria.
 *
 * @param rangeStr Rango de .
 * @param minRange Direccion de la celda.
 * @param maxRange Puntero a variable que permite almacenar el valor de retorno.
 **/
void obtainRange(char* rangeStr, char* minRange, char* maxRange);

/**
 * Aumenta el valor del contador si cumple la condicion.
 *
 * @param condition Tipo de condicion de la funcion.
 * @param result Valor comparado -1, 0 o 1.
 * @param dst Contador de las condiciones.
 **/
void conditionResult(const char * condition, int result, int * dst);

#endif

