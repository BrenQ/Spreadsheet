#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cell.h"


void initCell(Cell* this, const char * cellAddress,const void * v , unsigned size, char * type){
	if(cellAddress == 0x0){
		return;
	}

	this->cellAddress = malloc(strlen(cellAddress));
	strcpy(this->cellAddress, cellAddress);
	this->value = malloc(size);
	memcpy(this->value, v, size);
	this->size = size;
	this->type = malloc(strlen(type));
	strcpy(this->type,type);
}


void setValue(Cell* this, const void * v, unsigned size, char * type){
	this->value = realloc(this->value, size);
	memcpy(this->value, v, size);
	this->size = size;
	strcpy(this->type, type);

}

void getValue(Cell * this, const char * cellAddress, void * dst){
	memcpy(dst, this->value, this->size);
}

void release(Cell* this){

    if(this->cellAddress){
       free(this->cellAddress);
    }
     if(this->value){
      free(this->value);
    }

    this->cellAddress=0x0;
    this->value=0x0;
}





