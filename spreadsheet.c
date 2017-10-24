
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

 void init(SpreadSheet* s){
	 memset(s,0x0,sizeof(s));
	 s->cellsCount = 0;
 }
 void cleanUp(SpreadSheet* s){

 }

 /**

	@param: s Es la hoja de calculo a la que hace referencia
	@param cellAddressStr Direccion de la celda a setear valor ( A8,C9)
	@Pparam v Es el valor al que se va actualizar f
	@param vsize es el tamaño del valor que vamos a setear
 **/
 void setNumber( SpreadSheet* s, const char* cellAddresStr, const void* v, const unsigned vSize){
	 Cell c ;
	 Cell * dst = 0x0;
	 initCell(&c,cellAddresStr,v,vSize,"number");
	 

	 searchCelladdres(s,cellAddresStr,&dst);
	    
	 if(dst==0x0) {
	    s->cells = (Cell *) realloc(s->cells,(s->cellsCount+1)*sizeof(c));
	    s->cells[s->cellsCount] = *(Cell*) malloc(sizeof(c));
	    s->cells[s->cellsCount] = c;
	    s->cellsCount++;
    
	 }else{

	    setValue(dst,v,vSize,"number");		

	 }	
 	 	
 }

/**
 * Busca el puntero de la celda indicada
 *
 * */
void  * searchCelladdres(SpreadSheet * s, const char * cellAddresStr,Cell ** dst){
     Cell * current = s->cells;
     int i = 0; 
	while(current - s->cells < s->cellsCount ){
 	   
		if(strcmp(current->cellAddress,cellAddresStr)==0){
	 	   *dst = current; 
		   return;
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
 void setLabel( SpreadSheet* s, const char* cellAddresStr, const char* v){
	
    Cell c ;
    Cell * dst = 0x0;
    initCell(&c,cellAddresStr,v,strlen(v),"text");


    searchCelladdres(s,cellAddresStr,&dst);

    if(dst==0x0) {
        s->cells = (Cell *) realloc(s->cells,(s->cellsCount+1)*sizeof(c));
        s->cells[s->cellsCount] = *(Cell*) malloc(sizeof(c));
        s->cells[s->cellsCount] = c;
        s->cellsCount++;

    }else{

        setValue(dst,v,strlen(v),"text");

     }
	
	
 }

 /**
	Selram s Hoja de calculo
 81         @param cellAdressStr Direccion de la celda
 82         @param cellAdressRefrenceStr Referencia a direccion de la celda
 83 
ecciona una celda de la hoja de calculo y
	@param s Hoja de calculo
	@param cellAdressStr Direccion de la celda
	@param cellAdressRefrenceStr Referencia a direccion de la celda

 **/
 void setIdentity(SpreadSheet* s, const char* cellAddressStr, const char* cellAddressReferenceStr){

 }

 /**
	Selecciona un rango de direcciones de Celda

	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda donde se realiza el calculo
	@param cellAddressStr Rango de la direccion de la celda para sumar

 **/
 void setSummatory(SpreadSheet* s, const char* cellAddressStr, const char* cellAddressRangeStr){

 }

  /**
	Selecciona un rango de direcciones de Celda

	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda donde se realiza el calculo
	@param cellAddressStr Rango de la direccion de la celda para realizar el promedio

 **/

 void setAverage(SpreadSheet* s, const char* cellAddressStr, const char* cellAddressRangeStr){

 }

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
 void get( SpreadSheet* s, const char* cellAddresStr, void* dst){

 }

 /**
	Devuelve el valor de la funcion identidad almacenada en una direccion de memoria
	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda
	@param dst Puntero a variable que permite almacenar el valor de retorno

 **/

 void getIdentity( SpreadSheet* s, const char* cellAddresStr, void* dst){

 }

 /**
	Devuelve el valor de la funcion sumatoria almacenada en una direccion de memoria
	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda
	@param dst Puntero a variable que permite almacenar el valor de retorno

 **/

 void getSummatory(SpreadSheet* s, const char* cellAddressStr, void* dst){

 }


 /**
	Devuelve el valor de la funcion promedio almacenada en una direccion de memoria
	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda
	@param dst Puntero a variable que permite almacenar el valor de retorno

 **/


 void getAverage(SpreadSheet* s, const char* cellAddressStr, void* dst){

 }

 /**
	Devuelve el valor de la funcion contar.si almacenada en una direccion de memoria
	@param s Hoja de calculo
	@param cellAddressStr Direccion de la celda
	@param dst Puntero a variable que permite almacenar el valor de retorno

 **/

 //void getCountIf(SpreadSheet* s, ...);


