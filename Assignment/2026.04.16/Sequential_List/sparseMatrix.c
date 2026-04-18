#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sparseMatrix.h"

int dataMovement = 0;

sparseMatrix* createSparseMatrix(int row, int col) {
	if (col == 0) return createArrayList(row);
	return createArrayList(row * col);
}

int addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
	int size = sizeArrayList(sm);

	insertArrayList(sm, size, (elementArrayList) { row, col, value });
}

int printSparseMatrix(sparseMatrix* sm) {
	printf("희소행렬입니다\n");

	printArrayList(sm);
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {
	sparseMatrix* smResult = createArrayList(sm1->size + sm2->size);
	/*
	for (int i = 0; i <= sizeArrayList(sm1); i++) {
		elementArrayList nonZeroOfSM1 = getItemArrayList(sm1, i);
		int j;
		for (j = 0; j <= sizeArrayList(sm2); j++) {
			elementArrayList nonZeroOfSM2 = getItemArrayList(sm2, j);
			if (nonZeroOfSM1.col == nonZeroOfSM2.col && nonZeroOfSM1.row == nonZeroOfSM2.row) {
				insertArrayList(smResult, sizeArrayList(smResult), (elementArrayList) { nonZeroOfSM1.row, nonZeroOfSM1.col, nonZeroOfSM1.value + nonZeroOfSM2.value });
				break;
			}
		}
		if (j == sizeArrayList(sm2)) {
			insertArrayList(smResult, sizeArrayList(smResult), nonZeroOfSM1);
		}
	}
	*/
	int i = 0, j = 0;
	
	while (i < sm1->size && j < sm2->size) {
		elementArrayList nonZeroOfSM1 = getItemArrayList(sm1, i);
		elementArrayList nonZeroOfSM2 = getItemArrayList(sm2, j);
		if (nonZeroOfSM1.col == nonZeroOfSM2.col && nonZeroOfSM1.row == nonZeroOfSM2.row) {
			insertArrayList(smResult, sizeArrayList(smResult), (elementArrayList) { nonZeroOfSM1.row, nonZeroOfSM1.col, nonZeroOfSM1.value + nonZeroOfSM2.value });
			i++;
			j++;
		}
		else if (nonZeroOfSM1.row < nonZeroOfSM2.row || (nonZeroOfSM1.row == nonZeroOfSM2.row && nonZeroOfSM1.col < nonZeroOfSM2.col)) {
			insertArrayList(smResult, sizeArrayList(smResult), (elementArrayList) { nonZeroOfSM1.row, nonZeroOfSM1.col, nonZeroOfSM1.value});
			i++;
		}
		else {
			insertArrayList(smResult, sizeArrayList(smResult), (elementArrayList) { nonZeroOfSM2.row, nonZeroOfSM2.col, nonZeroOfSM2.value });
			j++;
		}
	}
	if (i >= sm1->size) {
		for (; j < sm2->size; j++) {
			elementArrayList nonZeroOfSM2 = getItemArrayList(sm2, j);
			insertArrayList(smResult, sizeArrayList(smResult), (elementArrayList) { nonZeroOfSM2.row, nonZeroOfSM2.col, nonZeroOfSM2.value });
		}
	}
	else if (j >= sm2->size) {
		for (; i < sm1->size; i++) {
			elementArrayList nonZeroOfSM1 = getItemArrayList(sm1, i);
			insertArrayList(smResult, sizeArrayList(smResult), (elementArrayList) { nonZeroOfSM1.row, nonZeroOfSM1.col, nonZeroOfSM1.value });
		}
	}

	return smResult;
} 
sparseMatrix* transposeMatrix(sparseMatrix* sm) {
	sparseMatrix* result = createSparseMatrix(sm->size, 0);
	result->size = sm->size;
	int numCols = (int)sqrt(sm->capacity);
	int* rowTerms = (int*)calloc(numCols, sizeof(int));
	int* startingPos = (int*)calloc(numCols, sizeof(int));

	for (int i = 0; i < sm->size; i++) {
		rowTerms[sm->data[i].col]++;
	}
	startingPos[0] = 0;
	for (int i = 1; i < numCols; i++) {
		startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
	}
	for (int i = 0; i < sm->size; i++) {
		int j = startingPos[sm->data[i].col];

		result->data[j].row = sm->data[i].col;
		result->data[j].col = sm->data[i].row;
		result->data[j].value = sm->data[i].value;
		dataMovement += 3;

		startingPos[sm->data[i].col]++;
	}
	
	free(rowTerms);
	free(startingPos);
	return result;
}