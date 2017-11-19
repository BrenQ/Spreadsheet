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
#define GREATER_OR_EQUAL ">="
#define LESS_OR_EQUAL "<="
#define LESS "<"
#define GREATER ">"
#define EQUAL "="
#define DISTINCT "<>"

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
			current += getSize(current);
		}

		free(s->cells);
	}

	s->cells = 0x0;
}

void setNumber(SpreadSheet* s, const char* cellAddresStr, const void* v,
		const unsigned vSize) {
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

void * searchCelladdres(SpreadSheet * s, const char * cellAddresStr,
		Cell ** dst) {
	Cell * current = s->cells;
	int i = 0;
	while ((current - s->cells) < s->cellsCount) {

		if (strcmp(getCellAddress(current), cellAddresStr) == 0) {
			*dst = current;
			return 0;
		}
		current++;
		i++;
	}

	return 0x0;
}

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

void setIdentity(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressReferenceStr) {
	setFunction(s, cellAddressStr, cellAddressReferenceStr);
}

void setSummatory(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressRangeStr) {

	setFunction(s, cellAddressStr, cellAddressRangeStr);
}

void setAverage(SpreadSheet* s, const char* cellAddressStr,
		const char* cellAddressRangeStr) {
	setFunction(s, cellAddressStr, cellAddressRangeStr);
}

void setCountIf(SpreadSheet* s, const char * cellAddressStr,
		const char * cellAddressRangeStr) {
	setFunction(s, cellAddressStr, cellAddressRangeStr);
}

void get(SpreadSheet* s, const char* cellAddressStr, void* dst) {
	Cell * ptr;
	searchCelladdres(s, cellAddressStr, &ptr);
	memcpy(dst, getValue(ptr), getSize(ptr));

}

void getIdentity(SpreadSheet* s, const char* cellAddressStr, void* dst) {

	Cell * ptr;
	char cellAddress[RANGEVALUE] = "";

	searchCelladdres(s, cellAddressStr, &ptr);

	searchCelladdres(s, getValue(ptr), &ptr);

	memcpy(dst, getValue(ptr), getSize(ptr));
}

void getSummatory(SpreadSheet* s, const char* cellAddressStr, void* dst) {
	Cell * ptr;
	float sumatory = 0;
	char iRangeLet[RANGEVALUE] = "";
	char fRangeLet[RANGEVALUE] = "";
	searchCelladdres(s, cellAddressStr, &ptr);
	obtainRange((char*) getValue(ptr), iRangeLet, fRangeLet);

	Cell * current = s->cells;
	int i = 0;
	while ((current - s->cells) < s->cellsCount) {
		if (strcmp(getType(current), NUMBER) == 0
				&& strverscmp(iRangeLet, getCellAddress(current)) <= 0
				&& strverscmp(getCellAddress(current), fRangeLet) <= 0) {
			sumatory += *(float*) (getValue(current));
		}
		current++;
		i++;

	}

	memcpy(dst, &sumatory, sizeof(float));

}

void obtainRange(char* rangeStr, char* minRange, char* maxRange) {

	char* iRangeLet = minRange;
	char* fRangeLet = maxRange;
	sscanf(rangeStr, EXP_FUNC, iRangeLet, fRangeLet);
	return;
}

void getAverage(SpreadSheet* s, const char* cellAddressStr, void* dst) {

	Cell * ptr;
	float sumatory = 0;
	float average = 0;
	char iRangeLet[RANGEVALUE] = "";
	char fRangeLet[RANGEVALUE] = "";
	searchCelladdres(s, cellAddressStr, &ptr);
	obtainRange((char*) getValue(ptr), iRangeLet, fRangeLet);

	Cell * current = s->cells;
	int count = 0;
	while ((current - s->cells) < s->cellsCount) {
		if (strcmp(getType(current), NUMBER) == 0
				&& strverscmp(iRangeLet, getCellAddress(current)) <= 0
				&& strverscmp(getCellAddress(current), fRangeLet) <= 0) {
			sumatory += *(float*) (getValue(current));
			count++;
		}
		current++;

	}

	average = sumatory / count;
	memcpy(dst, &average, sizeof(float));

}

void getCountIf(SpreadSheet* s, const char * cellAddressStr,
		const char * condition, const void * v, const unsigned vSize, int * dst) {

	Cell * ptr;
	char iRangeLet[RANGEVALUE] = "";
	char fRangeLet[RANGEVALUE] = "";
	int result = 0;
	int count = 0;
	searchCelladdres(s, cellAddressStr, &ptr);
	obtainRange((char*) getValue(ptr), iRangeLet, fRangeLet);

	Cell * current = s->cells;

	while ((current - s->cells) < s->cellsCount) {
		if (strcmp(getType(current), FUNCTION) != 0
				&& strverscmp(iRangeLet, getCellAddress(current)) <= 0
				&& strverscmp(getCellAddress(current), fRangeLet) <= 0) {

			result = memcmp(getValue(current), v, vSize);
			conditionResult(condition, result, &count);
		}
		current++;

	}

	memcpy(dst, &count, sizeof(int));
}

void conditionResult(const char * condition, int result, int * dst) {

	if (strcmp(GREATER_OR_EQUAL, condition) == 0 && result >= 0) {
		(*dst)++;
	} else if (strcmp(LESS_OR_EQUAL, condition) == 0 && result >= 0) {
		(*dst)++;
	} else if (strcmp(LESS, condition) == 0 && result < 0) {
		(*dst)++;
	} else if (strcmp(GREATER, condition) == 0 && result > 0) {
		(*dst)++;
	} else if (strcmp(EQUAL, condition) == 0 && result == 0) {
		(*dst)++;
	} else if (strcmp(DISTINCT, condition) == 0 && result != 0) {
		(*dst)++;
	}
}
