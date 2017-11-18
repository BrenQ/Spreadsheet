
/*
 * Cell.h
 *
 *  Created on: Oct 13, 2017
 *      Author: alumno
 */

#ifndef CELL_H_
#define CELL_H_

typedef struct _cell {
	char * cellAddress;
	void * value;
	char * type;
	unsigned size;
} Cell;

/** Inicializa la celda 
    @param this Celda 
    @param cellAddress Direccion de la celda
    @param v valor a almacenar
    @param size tamaño de la celda
    @param type Tipo del valor

**/
void initCell(Cell* this, const char * cellAddress, const void * v,
		unsigned size, const char * type);

/** Setea valor de la celda y sus propiedades
    @param this Celda 
    @param v valor a almacenar
    @param size tamaño de la celda
    @param type Tipo del valor

**/
void setValue(Cell * this, const void * v, unsigned size, const char * type);

/** Retorna valor de la celda
   @param this Celda 
**/

void * getValue (Cell * this );

/** Retorna direccion de la celda
   @param this Celda 
**/

char * getCellAddress(Cell * this);

/** Retorna tipo de la celda
   @param this Celda 
**/

char * getType(Cell * this);

/** Retorna tamaño de la celda
   @param this Celda 
**/

int   getSize(Cell * this);

/** Reinicializa la celda
   @param this Celda 
**/

void release(Cell * this);

#endif


