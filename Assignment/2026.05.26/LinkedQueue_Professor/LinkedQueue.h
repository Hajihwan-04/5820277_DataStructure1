#include <stdio.h>
#include <stdlib.h>

typedef int queueElement;

typedef struct node {
	queueElement data;
	struct node* next;
} Node;

typedef struct linkedQueue {
	Node* front;
	Node* rear;
} LinkedQueue;

extern LinkedQueue* createLinkedQueue();
extern int destroyLinkedQueue(LinkedQueue* q);
extern int emptyLinkedQueue(LinkedQueue* q);
extern int fullLinkedQueue(LinkedQueue* q);
extern int enqueueLinkedQueue(LinkedQueue* q, queueElement item);
extern queueElement dequeueLinkedQueue(LinkedQueue* q);
extern void printLinkedQueue(LinkedQueue* q);