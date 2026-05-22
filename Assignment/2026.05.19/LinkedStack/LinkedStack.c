#include "LinkedStack.h"

LinkedStack* createLinkedStack() {
	LinkedStack* re = (LinkedStack*)malloc(sizeof(LinkedStack));
	re->head = NULL;
	re->size = 0;
	
	return re;
}
int destroyLinkedStack(LinkedStack* s) {
	for (int i = 0; i < s->size; i++) {
		popLinkedList(s);
	}

	if (emptyLinkedStack(s)) {
		return 1;
	}
	else {
		return 0;
	}
}
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
stackElement popLinkedList(LinkedStack* s) {
	if (emptyLinkedStack(s)) {
		printf("Already Empty!\n");
		return (stackElement)NULL;
	}
	Node *temp = s->head;
	stackElement data = s->head->data;
	s->head = temp->next;
	free(temp);
	
	s->size--;
	return data;
}
stackElement peakLinkedList(LinkedStack* s) {
	return s->head->data;
}

void printLinkedList(LinkedStack* s) {
	printf("Stack:\n");
	printf("Size: %d\n", s->size);
	Node* temp = s->head;
	while (temp != NULL) {
		printf("%s\n", temp->data);
		temp = temp->next;
	}
}