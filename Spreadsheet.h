
#ifndef SPREADSHEET_H_
#define SPREADSHEET_H_

#include "cell.h"

typedef struct _SpreadSheet{
	Cell * cells;
	unsigned cellsCount;
}SpreadSheet;

 void init(SpreadSheet* s);
 void cleanUp(SpreadSheet* s);

 /**

	@param: s Es la hoja de calculo a la que hace referencia
	@param cellAddressStr Direccion de la celda a setear valor ( A8,C9)
	@Pparam v Es el valor al que se va actualizar f
	@param vsize es el tamaño del valor que vamos a setear
 **/
 void setNumber( SpreadSheet* s, const char* cellAddresStr, const void* v, const unsigned vSize);

 /**
	Label es la etiqueta de la columna
	@param s Hoja de calculo
	@param cellAddressStr es la direccion de la celda A4
	@param v es el valor de la columna

 **/
 void setLabel( SpreadSheet* s, const char* cellAddresStr, const char* v);

 /**
	Selecciona una celda de la hoja de calculo y
	@param s Hoja de calculo
	@param cellAdressStr Direccion de la celda
	@param cellAdressRefrenceStr Referencia a direccion de la celda

 **/

void * searchCelladdres(SpreadSheet * s, const char * cellAddresStr,Cell ** dst);
 void setIdentity(SpreadSheet* s, const char* cellAddressStr, const char* cellAddressReferenceStr);

 /**
	Selecciona un rango de direcciones de Celda

	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda donde se realiza el calculo
	@param cellAddressStr Rango de la direccion de la celda para sumar

 **/
 void setSummatory(SpreadSheet* s, const char* cellAddressStr, const char* cellAddressRangeStr);

  /**
	Selecciona un rango de direcciones de Celda

	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda donde se realiza el calculo
	@param cellAddressStr Rango de la direccion de la celda para realizar el promedio

 **/

 void setAverage(SpreadSheet* s, const char* cellAddressStr, const char* cellAddressRangeStr);

   /**
	Selecciona un rango de direcciones de Celda

	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda
	@param cellAddressStr Rango de la direccion de la celda para contar.si

 **/

// void setCountIf(SpreadSheet* s, ...);


   /**
	Devuelve el valor de una direccion de celda

	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda
	@param dst Retorno donde almacenar el valor de una celda

 **/
 void get( SpreadSheet* s, const char* cellAddresStr, void* dst);

 /**
	Devuelve el valor de la funcion identidad almacenada en una direccion de memoria
	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda
	@param dst Puntero a variable que permite almacenar el valor de retorno

 **/

 void getIdentity( SpreadSheet* s, const char* cellAddresStr, void* dst);

 /**
	Devuelve el valor de la funcion sumatoria almacenada en una direccion de memoria
	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda
	@param dst Puntero a variable que permite almacenar el valor de retorno

 **/

 void getSummatory(SpreadSheet* s, const char* cellAddressStr, void* dst);


 /**
	Devuelve el valor de la funcion promedio almacenada en una direccion de memoria
	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda
	@param dst Puntero a variable que permite almacenar el valor de retorno

 **/


 void getAverage(SpreadSheet* s, const char* cellAddressStr, void* dst);

 /**
	Devuelve el valor de la funcion contar.si almacenada en una direccion de memoria
	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda
	@param dst Puntero a variable que permite almacenar el valor de retorno

 **/

 //void getCountIf(SpreadSheet* s, ...);

#endif

