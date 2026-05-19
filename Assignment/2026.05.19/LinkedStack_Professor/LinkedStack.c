#include "LinkedStack.h"

LinkedStack* createLinkedStack() {
	LinkedStack* re = (LinkedStack*)malloc(sizeof(LinkedStack));
	re->head = NULL;
	re->size = 0;
	
	return re;
}
//destroyLinkedStack()
int emptyLinkedStack(LinkedStack* s) {
	return s->size == 0;
}
int fullLinkedStack(LinkedStack* s) {
	return 0;
}
int pushLinkedStack(LinkedStack* s, stackElement item) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = s->head;
	s->head = temp;

	s->size++;
	return 1;
}
//pop
void printLinkedList(LinkedStack* s) {
	printf("Stack:\n");
	printf("Size: %d\n", s->size);
	Node* temp = s->head;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}