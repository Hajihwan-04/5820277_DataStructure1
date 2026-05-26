#include "ArrayQueue.h"

ArrayQueue* createArrayQueue(int size) {
	ArrayQueue* temp = (ArrayQueue*)malloc(sizeof(ArrayQueue));
	temp->rear = 0;
	temp->front = 0;
	temp->data = (queueElement*)malloc(sizeof(queueElement) * size);
	temp->size = size;
}
int destroyArrayQueue(ArrayQueue* q) {
	free(q->data);
	free(q);

	return 1;
}
int emptyArrayQueue(ArrayQueue* q) {
	return q->front == q->rear;
}
int fullArrayQueue(ArrayQueue* q) {
	return (q->rear + 1) % q->size == q->front;
}
int enqueueArrayQueue(ArrayQueue* q, queueElement item) {
	if (fullArrayQueue(q)) {
		return 0;
	}
	else {
		q->data[q->rear] = item;
		q->rear = (q->rear + 1) % q->size;
		return 1;
	}
}
queueElement dequeueArrayQueue(ArrayQueue* q) {
	if (emptyArrayQueue(q)) {
		return 0;
	}
	else {
		queueElement temp = q->data[q->front];
		q->front = (q->front + 1) % q->size;

		return temp;
	}

}
void printArrayQueue(ArrayQueue* q) {
	printf("Array Queue:\nSize: %d\n", q->size);

	if (emptyArrayQueue(q)) {
		return;
	}

	int rear = q->rear;
	int front = q->front;
	while ((front + 1) % q->size != rear + 1) {
		printf("%d, ", q->data[front]);
		front = (front + 1) % q->size;
	}
	printf("\n");
	
}