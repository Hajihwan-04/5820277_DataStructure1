#include <stdio.h>
#include <stdlib.h>

struct pointType {
	int x;
	int y;
	struct pointType* next;
};

struct linkedList {
	struct pointType* head;
	int size;
};

struct linkedList* createLinkedList();
int destroyLinkedList(struct linkedList* li);

int main() {
	struct pointType n;
	struct pointType m;

	struct linkedList* myList1;
	myList1 = createLinkedList();

	struct pointType* nptr;
	nptr = (struct pointType*)malloc(sizeof(struct pointType));
	nptr->x = 10;
	nptr->y = 20;
	nptr->next = (struct pointType*)NULL;
	
	myList1->head = nptr;

	printf("myList1: head: %x, size: %d\n", myList1->head, myList1->size);

	printf("first node: x: %d, y: %d, next: %x\n", myList1->head->x, myList1->head->y, myList1->head->next);

	nptr = (struct pointType*)malloc(sizeof(struct pointType));
	nptr->x = 20;
	nptr->y = 30;
	nptr->next = myList1->head;
	myList1->head = nptr;

	printf("first node: x: %d, y: %d, next: %x\n", myList1->head->x, myList1->head->y, myList1->head->next);


	for (nptr = myList1->head; nptr != NULL; nptr = nptr->next) {
		printf("node: x: %d, y: %d, next: %x\n", nptr->x, nptr->y, nptr->next);
	}

	destroyLinkedList(myList1);
	/*
	n.x = 10;
	n.y = 20;
	n.next = (struct pointType*)NULL;

	m.x = 20;
	m.y = 30;
	m.next = &n;

	struct pointType* head;
	head = &m;
	printf("x: %d, y: %d, next: %x\n", n.x, n.y, n.next);
	printf("x: %d, y: %d, next: %x\n", m.x, m.y, m.next);
	printf("x: %d, y: %d, next: %x\n", m.next->x, m.next->y, m.next->next); 
	printf("x: %d, y: %d, next: %x\n", head->x, head->y, head->next);
	printf("x: %d, y: %d, next: %x\n", head->next->x, head->next->y, head->next->next);

	head = head->next;
	printf("x: %d, y: %d, next: %x\n", head->x, head->y, head->next);
	*/

}

struct linkedList* createLinkedList() {
	struct linkedList* r;
	r = (struct linkedList*)malloc(sizeof(struct linkedList));

	r->head = (struct pointType*)NULL;
	r->size = 0;

	return r;
}

int destroyLinkedList(struct linkedList* li) {
	struct pointType* nptr, *mptr;
	for (nptr = li->head; nptr != NULL; nptr = mptr) {
		mptr = nptr->next;
		free(nptr);
	}
	free(li);

	return 1;
}