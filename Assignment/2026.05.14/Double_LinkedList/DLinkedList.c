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

int isEmptyLinkedList(DLinkedList* dl) {
	return (dl->size == 0);
}
int sizeLinkedList(DLinkedList* dl) {
	return dl->size;
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
	nPtr->next->prev = nPtr;

	dl->size++;
}

int insertItemDLinkedList(DLinkedList* dl, PointType* pre, PointType item) {
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	pre->next->prev = nPtr;
	nPtr->next = pre->next;
	pre->next = nPtr;
	nPtr->prev = pre;

	dl->size++;
}

PointType deleteFirstDLinkedList(DLinkedList* dl) {
	PointType* temp = dl->head.next;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	dl->size--;
	free(temp);
}

PointType deleteLastDLinkedList(DLinkedList* dl) {
	PointType* temp = dl->head.prev;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	dl->size--;
	free(temp);
}

PointType deleteItemDLinkedList(DLinkedList* dl, PointType item) {
	PointType* temp = dl->head.next;
	for (int i = 0; i < dl->size; i++) {
		if (temp->x == item.x && temp->y == item.y) {
			break;
		}
		else {
			temp = temp->next;
		}
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	dl->size--;
	free(temp);
}

int insertAtDLinkedList(DLinkedList* dl, int at, PointType item) {
	PointType* iPtr = (PointType*)malloc(sizeof(PointType));
	*iPtr = item;
	PointType* current;
	current = dl->head.next;
	for (int i = 0; i < at; i++) {
		current = current->next;
	}
	iPtr->next = current->next;
	iPtr->prev = current;
	current->next->prev = iPtr;
	current->next = iPtr;

	dl->size++;
}

PointType deleteAtDLinkedList(DLinkedList* dl, int at) {
	PointType* temp = dl->head.next;
	for (int i = 0; i < at; i++) {
		temp = temp->next;
	}
	PointType remove = *temp;

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	dl->size--;
	free(temp);
	return remove;
}

PointType getItemDLinkedList(DLinkedList* dl, int pos) {
	PointType* temp = dl->head.next;
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	return *temp;
}

void replaceItemDLinkedList(DLinkedList* dl, int pos, PointType item) {
	PointType* temp = dl->head.next;
	for (int i = 0; i < pos; i++) {
		temp = temp->next;
	}
	temp->x = item.x;
	temp->y = item.y;
}

PointType nextItemDLinkedList(DLinkedList* dl, PointType* pre) {
	return *(pre->next);
}

void printDLinkedList(DLinkedList* dl) {
	printf("Print DLinkedList:\n");
	//printf("Size: %d\n", dl->size);
	if (dl->size == 0) {
		return;
	}

	PointType* start = dl->head.next;

	for (int i = 0; i < dl->size; i++) {
		printf("[%d] x: %d, y: %d, next: %x, prev: %x\n", i, start->x, start->y, start->next, start->prev);
		start = start->next;
	}
	printf("\n");
}