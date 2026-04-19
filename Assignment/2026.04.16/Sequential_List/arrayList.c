#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "arrayList.h"

arrayList* createArrayList(int size) {
	arrayList* al;

	al = (arrayList*)malloc(sizeof(arrayList));
	if (al == NULL) {
		printf("ERROR!! 메모리 부족\n");
		return NULL;
	}
	al->data = (elementArrayList**)malloc(sizeof(elementArrayList*) * size);
	if (al->data == NULL) {
		printf("ERROR!! 메모리 부족\n");
		free(al);
		return NULL;
	}
	al->size = 0;
	al->capacity = size;

	return al;
}
void destoryArrayList(arrayList* al) {
	for (int i = 0; i < al->size; i++) {
		free(al->data[i]);
	}
	free(al->data);
	free(al);
}

int isEmptyArrayList(arrayList* al) {
	if (al->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int isFullArrayList(arrayList* al) {
	if (al->size == al->capacity) {
		return 1;
	}
	else {
		return 0;
	}
}
int sizeArrayList(arrayList* al) {
	return al->size;
}

int insertArrayList(arrayList* al, int pos, elementArrayList item) {
	if (pos < 0 || pos > al->size) {
		return 0;
	}
	
	if (isFullArrayList(al)) {
		printf(" |메모리 추가|\n");
		elementArrayList** temp = (elementArrayList**)realloc(al->data, sizeof(elementArrayList*) * (al->capacity + 1));
		if (temp == NULL) {
			printf("ERROR!! 메모리 부족\n");
			return 0;
		}
		al->capacity += 1;
		al->data = temp;
	}
	for (int i = al->size - 1; i >= pos; i--) {
		al->data[i + 1] = al->data[i];
	}

	elementArrayList* realData = (elementArrayList*)malloc(sizeof(elementArrayList));
	realData->row = item.row;
	realData->col = item.col;
	realData->value = item.value;

	al->data[pos] = realData;
	al->size++;
	return 1;
}

elementArrayList deleteArrayList(arrayList* al, int pos) {
	if (pos < 0 || pos > al->size - 1) {
	}
	elementArrayList item = *(al->data[pos]);
	free(al->data[pos]);
	for (int i = pos; i < al->size - 1; i++) {
		al->data[i] = al->data[i + 1];
	}

	al->size--;
	return item;
}
void initArrayList(arrayList* al) {
	for (int i = al->size - 1; i >= 0; i--) {
		deleteArrayList(al, i);
	}
}

elementArrayList getItemArrayList(arrayList* al, int pos) {
	return *(al->data[pos]);
}
int replaceItemArrayList(arrayList* al, int pos, elementArrayList item) {
	if (pos < 0 || pos > al->size - 1) {
		return 0;
	}

	*(al->data[pos]) = item;

	return 1;
}

void printArrayList(arrayList* al) {
	printf("희소 행렬 순차 리스트\n");

	for (int i = 0; i < al->size; i++) {
		if (i % ((int)sqrt(al->capacity)) == 0 && i != 0) printf("\n");
		printf("(%d %d %2d) ", al->data[i]->row, al->data[i]->col, al->data[i]->value);
		
	}
	printf("\n\n");
}