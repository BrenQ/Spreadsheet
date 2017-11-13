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

void initCell(Cell* this, const char * cellAddress, const void * v,
		unsigned size, char * type);
void setValue(Cell * this, const void * v, unsigned size, char * type);
void getValue(Cell * this, const char * cellAddress, void * dst);
void release(Cell * this);

#endif

