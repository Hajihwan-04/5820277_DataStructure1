#include "ArrayQueue.h"

int main() {
	ArrayQueue* myQueue = createArrayQueue(10);

	enqueueArrayQueue(myQueue, 1);
	enqueueArrayQueue(myQueue, 2);
	enqueueArrayQueue(myQueue, 3);
	enqueueArrayQueue(myQueue, 4);
	enqueueArrayQueue(myQueue, 5);

	printArrayQueue(myQueue);

	dequeueArrayQueue(myQueue);
	dequeueArrayQueue(myQueue);
	dequeueArrayQueue(myQueue);

	printArrayQueue(myQueue);


	destroyArrayQueue(myQueue);
}