#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"

int main() {
	arrayList* myArrayList;
	myArrayList = createArrayList(2);

	if (sizeArrayList(myArrayList) == 0) {
		printf("Create ok\n\n");
	}

	//Insert test
	insertArrayList(myArrayList, 0, 10); //최초 삽입
	insertArrayList(myArrayList, 1, 20);
	insertArrayList(myArrayList, 2, 30);
	insertArrayList(myArrayList, 3, -30);
	insertArrayList(myArrayList, 3, 0);
	printArrayList(myArrayList);
	printf("\n");
	insertArrayList(myArrayList, 0, 5);

	printf("Insert test\n");
	printArrayList(myArrayList);
	printf("\n");

	//Replace test
	replaceItemArrayList(myArrayList, 4, 35);

	printf("Replace test\n");
	printArrayList(myArrayList);
	printf("\n");

	//Delete test
	deleteArrayList(myArrayList, 0);
	deleteArrayList(myArrayList, 1);
	deleteArrayList(myArrayList, 2);

	printf("Delete test\n");
	printArrayList(myArrayList);
	printf("\n");

	//Clear test
	initArrayList(myArrayList);

	printf("Clear test\n");
	printArrayList(myArrayList);

}