#include "DLinkedList.h"

int main() {
	DLinkedList* myList = createDLinkedList();

	insertFirstDLinkedList(myList, (PointType) { 10, 20, 0 });
	insertFirstDLinkedList(myList, (PointType) { 20, 30, 0 });
	insertLastDLinkedList(myList, (PointType) { 30, 40, 0 });
	insertLastDLinkedList(myList, (PointType) { 40, 50, 0 });
	printDLinkedList(myList);
	destroyDLinkedList(myList);
}