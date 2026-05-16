#include "DLinkedList.h"

DLinkedList* createDLinkedList() {
	DLinkedList* temp;
	temp = (DLinkedList*)malloc(sizeof(DLinkedList));
	temp->head.prev = &(temp->head);
	temp->head.next = &(temp->head);
	temp->size = 0;

	return temp;
}
void destroyDLinkedList(DLinkedList* dl) {
	while (dl->size != 0) {
		deleteFirstDLinkedList(dl);
	}
	free(dl);
}

int insertFirstDLinkedList(DLinkedList* dl, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = &(dl->head);
	nPtr->next = dl->head.next;
	dl->head.next = nPtr;
	nPtr->next->prev = nPtr;

	dl->size++;
}
int insertLastDLinkedList(DLinkedList* dl, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	nPtr->prev = dl->head.prev;
	nPtr->next = &(dl->head);
	nPtr->prev->next = nPtr;

	dl->size++;
}

extern PointType deleteFirstDLinkedList(DLinkedList* dl) {
	PointType* temp = dl->head.next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	dl->size--;
	free(temp);
}

void printDLinkedList(DLinkedList* dl) {
	printf("Print DLinkedList:\n");
	printf("Size: %d\n", dl->size);
	PointType* start = dl->head.next;

	for (int i = 0; i < dl->size; i++) {
		printf("[%d] x: %d, y: %d, next: %x\n", i, start->x, start->y, start->next);
	}
	start = start->next;
}