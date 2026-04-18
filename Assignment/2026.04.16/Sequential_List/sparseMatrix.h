#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

typedef arrayList sparseMatrix;

extern int dataMovement;
extern sparseMatrix* createSparseMatrix(int row, int col);
extern int addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value);
extern int printSparseMatrix(sparseMatrix* sm);
extern sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2);
extern sparseMatrix* transposeMatrix(sparseMatrix* sm);