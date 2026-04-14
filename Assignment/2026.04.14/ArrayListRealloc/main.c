#include <stdio.h>
#include <stdlib.h>

#include "arrayListRealloc.h"

int main() {
	int N;
	printf("순차리스트 크기 입력 : ");
	scanf_s("%d", &N);

	arrayList* myArrayList;
	myArrayList = createArrayList(N);

	if (sizeArrayList(myArrayList) == 0) {
		printf("Create ok\n");
	}
	int data;
	for (int i = 0; i <= N + 5; i++) {
		printf("입력 값(정수) : ");
		scanf_s("%d", &data);
		insertArrayList(myArrayList, sizeArrayList(myArrayList), data);

		printArrayList(myArrayList);
		
	}

	destoryArrayList(myArrayList);
	return 0;
}