#include "DLinkedList.h"

int main() {
	DLinkedList* myList = createDLinkedList();

	insertFirstDLinkedList(myList, (PointType) { 10, 20, 0 });
	insertFirstDLinkedList(myList, (PointType) { 20, 30, 0 });
	insertLastDLinkedList(myList, (PointType) { 30, 40, 0 });
	insertLastDLinkedList(myList, (PointType) { 40, 50, 0 });
	insertItemDLinkedList(myList, myList->head.next, (PointType) { 50, 60, 0 });
	insertItemDLinkedList(myList, &(myList->head), (PointType) { 60, 70, 0 });
	printDLinkedList(myList);

	deleteFirstDLinkedList(myList);
	printDLinkedList(myList);

	deleteLastDLinkedList(myList);
	printDLinkedList(myList);

	deleteItemDLinkedList(myList, (PointType) { 50, 60, 0 });
	printDLinkedList(myList);

	insertAtDLinkedList(myList, 2, (PointType) { 50, 60, 0 });
	printDLinkedList(myList);

	deleteAtDLinkedList(myList, 1);
	printDLinkedList(myList);

	PointType test = getItemDLinkedList(myList, 1);
	printf("%d, %d\n", test.x, test.y);

	replaceItemDLinkedList(myList, 1, (PointType) { 70, 80, 0 });
	printDLinkedList(myList);

	destroyDLinkedList(myList);
}