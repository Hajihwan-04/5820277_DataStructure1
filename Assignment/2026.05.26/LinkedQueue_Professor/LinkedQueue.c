#include "LinkedQueue.h"

LinkedQueue* createLinkedQueue() {
	LinkedQueue* temp = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	temp->front = NULL;
	temp->rear = NULL;

	return temp;
}
int destroyLinkedQueue(LinkedQueue* q) {
	while (!emptyLinkedQueue(q)) {
		dequeueLinkedQueue(q);
	}
	free(q);
}
int emptyLinkedQueue(LinkedQueue* q) {
	return q->front == NULL;
}
int fullLinkedQueue(LinkedQueue* q) {
	return 0;
}
int enqueueLinkedQueue(LinkedQueue* q, queueElement item) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = NULL;

	if (!emptyLinkedQueue(q)) {
		q->rear->next = temp;
		q->rear = temp;
	}
	else {
		q->front = temp;
		q->rear = temp;
	}
	
}
queueElement dequeueLinkedQueue(LinkedQueue* q) {
	if (!emptyLinkedQueue(q)) {
		queueElement temp = q->front->data;
		Node* nPtr = q->front;
		q->front = q->front->next;
		free(nPtr);
		return temp;
	}
	else {
		return 0;
	}
}
void printLinkedQueue(LinkedQueue* q) {
	printf("LinkedQueue\n");

	Node* front = q->front;

	while (front != NULL) {
		printf("%d ", front->data);
		front = front->next;
	}
	printf("\n");
}