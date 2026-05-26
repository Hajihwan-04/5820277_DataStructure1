#include <stdio.h>
#include <stdlib.h>

typedef int queueElement;

typedef struct arrayaQueue {
	int rear;
	int front;

	queueElement* data;
	int size;
} ArrayQueue;

extern ArrayQueue* createArrayQueue(int size);
extern int destroyArrayQueue(ArrayQueue* q);
extern int emptyArrayQueue(ArrayQueue* q);
extern int fullArrayQueue(ArrayQueue* q);
extern int enqueueArrayQueue(ArrayQueue* q, queueElement item);
extern queueElement dequeueArrayQueue(ArrayQueue* q);
extern void printArrayQueue(ArrayQueue* q);