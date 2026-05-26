#include "LinkedQueue.h"

int main() {
	LinkedQueue* myQueue = createLinkedQueue();

	enqueueLinkedQueue(myQueue, 1);
	enqueueLinkedQueue(myQueue, 2);
	enqueueLinkedQueue(myQueue, 3);
	enqueueLinkedQueue(myQueue, 4);
	enqueueLinkedQueue(myQueue, 5);

	printLinkedQueue(myQueue);

	dequeueLinkedQueue(myQueue);
	dequeueLinkedQueue(myQueue);

	printLinkedQueue(myQueue);

	destroyLinkedQueue(myQueue);
}