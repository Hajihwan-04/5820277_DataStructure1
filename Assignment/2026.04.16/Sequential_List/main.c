#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sparseMatrix.h"

#define ROW 10
#define COL 10

int main() {

	sparseMatrix* sm1 = createSparseMatrix(ROW, ROW);

	//10x10 임의의 희소행렬 생성
	int smArray[ROW][COL] = { 0 };
	int count = 0, a = 0, b = 0;
	srand((unsigned int)time(NULL));
	while (count < 20) {
		int row = rand() % 10;
		int col = rand() % 10;
		if (smArray[row][col] == 0) {
			smArray[row][col] = rand() % 49 + 1;
			count++;
		}
	}
	int size = 0;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (smArray[i][j] != 0) {
				elementArrayList temp;
				temp.row = i;
				temp.col = j;
				temp.value = smArray[i][j];

				insertArrayList(sm1, size, temp);
				size++;
			}
			printf("(%d %d %2d) ", i, j, smArray[i][j]);
		}
		printf("\n");
	}

	printSparseMatrix(sm1);

	sparseMatrix* tpMatrix = transposeMatrix(sm1);

	printSparseMatrix(tpMatrix);
	size = 0;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (size < tpMatrix->size && tpMatrix->data[size]->row == i && tpMatrix->data[size]->col == j) {
				printf("(%d %d %2d) ", i, j, tpMatrix->data[size]->value);
				size++;
			}
			else {
				printf("(%d %d %2d) ", i, j, 0);
			}
		}
		printf("\n");
	}
	
	printf("데이터 이동 횟수: %d회\n", dataMovement);
	destoryArrayList(sm1);
	destoryArrayList(tpMatrix);
	return 0;

}