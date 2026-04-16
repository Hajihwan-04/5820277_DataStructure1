#include <stdio.h>
#include <stdlib.h>

#include "arrayListRealloc.h"

int main() {

	arrayList* myArrayList;
	myArrayList = createArrayList(1);

	insertArrayList(myArrayList, 0, 10);
	insertArrayList(myArrayList, 1, 20);
	insertArrayList(myArrayList, 2, 30);
	insertArrayList(myArrayList, 0, 5);

	printArrayList(myArrayList);

	deleteArrayList(myArrayList, 0);
	deleteArrayList(myArrayList, 1);
	deleteArrayList(myArrayList, 2);

	printArrayList(myArrayList);

	destoryArrayList(myArrayList);
	return 0;
}