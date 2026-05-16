#include "LinkedList.h"

LinkedList* createLinkedList() {
	struct linkedList* r;
	r = (struct linkedList*)malloc(sizeof(struct linkedList));

	r->head = (struct pointType*)NULL;
	r->size = 0;

	return r;
}

int destroyLinkedList(struct linkedList* li) {
	struct pointType* nptr, * mptr;
	for (nptr = li->head; nptr != NULL; nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}
	free(li);

	return 1;
}

int isEmptyLinkedList(LinkedList* li) {
	return (li->size == 0);
}

int sizeLinkedList(LinkedList* li) {
	return li->size;
}

LinkedList* insertFirstLinkedList(LinkedList* li, PointType item) {
	PointType* ptr = (PointType*)malloc(sizeof(PointType));
	*ptr = item;

	ptr->next = li->head;
	li->head = ptr;

	li->size++;

	return li;
}

int printLinkedList(LinkedList* li) {
	PointType* current = li->head;
	printf("LinkedList:\n");
	//printf("LinkedList size: %d\n", li->size);

	for (int i = 0; i < li->size; i++) {
		printf("[%d] x:%d, y%d, next:%x\n", i, current->x, current->y, current->next);

		current = current->next;
	}
	printf("\n");
}

LinkedList* insertLastLinkedList(LinkedList* li, PointType item) {
	PointType* ptr = li->head;
	PointType* nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	if (!(li->head != NULL)) {
		nPtr->next = NULL;
		li->head = nPtr;
		li->size++;
		return li;
	}
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	nPtr->next = NULL;

	ptr->next = nPtr;

	li->size++;

	return li;
}

LinkedList* deleteAtLinkedList(LinkedList* li, int at) {
	if (at >= 0 && at < li->size) {
		PointType* nPtr = li->head;

		for (int i = 0; i < at - 1; i++) {
			nPtr = nPtr->next;
		}
		if (at == 0) {
			PointType* fPtr = li->head;
			li->head = fPtr->next;
			free(fPtr);
		}
		else {
			PointType* fPtr = nPtr->next;
			nPtr->next = fPtr->next;
			free(fPtr);
		}
		li->size--;
	}
}

LinkedList* insertItemLinkedList(LinkedList* li, PointType* pre, PointType item) {
	PointType *nPtr = (PointType*)malloc(sizeof(PointType));
	*nPtr = item;

	if (pre != NULL) {
		nPtr->next = pre->next;
		pre->next = nPtr;
	}
	else {
		nPtr->next = li->head;
		li->head = nPtr;
	}
	li->size++;
}

PointType deleteFirstLinkedList(LinkedList* li) {
	if (li->size != 0) {
		PointType* tPtr = li->head;
		li->head = tPtr->next;

		PointType temp = *tPtr;
		free(tPtr);

		li->size--;
		return temp;
	}
	else {
		return (PointType) {0 ,0, 0};
	}
}

PointType deleteLastLinkedList(LinkedList* li) {
	PointType* pre;
	PointType* iPtr;
	pre = li->head;

	if (pre == NULL) {
		return (PointType) { 0, 0, 0 };
	}

	iPtr = pre->next;

	if (iPtr == NULL) {
		li->head = NULL;

		PointType temp;
		temp = *pre;

		free(pre);
		li->size--;

		return temp;
	}

	while (iPtr->next != NULL) {
		pre = iPtr;
		iPtr = iPtr->next;
	}

	PointType temp;
	temp = *iPtr;

	pre->next = NULL;
	free(iPtr);
	li->size--;

	return temp;
}

PointType deleteItemLinkedList(LinkedList* li, PointType item) {
	PointType* nPtr = li->head;
	PointType temp;
	if (li->head != NULL && nPtr->x == item.x && nPtr->y == item.y) {
		temp = *nPtr;
		li->head = nPtr->next;
		free(nPtr);
		li->size--;
		return temp;
	}
	while(nPtr->next != NULL){
		if (nPtr->next->x == item.x && nPtr->next->y == item.y) {
			PointType* prev = nPtr->next;
			temp = *prev;
			nPtr->next = prev->next;
			free(prev);
			li->size--;
			return temp;
		}
		else {
			nPtr = nPtr->next;
		}
	}
	printf("Nothing Match.\n");
	return (PointType) { 0, 0, 0 };
}

LinkedList* insertAtLinkedList(LinkedList* li, int at, PointType item) {
	PointType* iPtr;
	iPtr = (PointType*)malloc(sizeof(PointType));
	*iPtr = item;

	PointType* pos;
	pos = li->head;
	if (at == 0) {
		iPtr->next = li->head;
		li->head = iPtr;
		li->size++;
		return li;
	}
	for (int i = 0; i < at - 1; i++) {
		pos = pos->next;
	}
	iPtr->next = pos->next;
	pos->next = iPtr;
	li->size++;
	
	return li;
}

PointType getItemLinkedList(LinkedList* li, int pos) {
	PointType result;
	PointType* current = li->head;
	for (int i = 0; i < pos; i++) {
		current = current->next;
	}
	result = *current;

	return result;
}

void replaceItemLinkedList(LinkedList* li, int pos, PointType item) {
	PointType* nPtr;
	nPtr = li->head;
	for (int i = 0; i < pos; i++) {
		nPtr = nPtr->next;
	}
	nPtr->x = item.x;
	nPtr->y = item.y;
}

PointType nextItemLinkedList(LinkedList* li, PointType* pre) {
	return *(pre->next);
}