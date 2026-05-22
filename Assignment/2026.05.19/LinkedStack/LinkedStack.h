#include <stdio.h>
#include <stdlib.h>

typedef char* stackElement;

typedef struct node {
	stackElement data;
	struct node* next;
} Node;

typedef struct lickedStack {
	Node* head;
	int size;
} LinkedStack;

extern LinkedStack* createLinkedStack();
extern int destroyLinkedStack();
extern int emptyLinkedStack(LinkedStack* s);
extern int fullLinkedStack(LinkedStack* s);
extern int pushLinkedStack(LinkedStack* s, stackElement item);
extern stackElement popLinkedList(LinkedStack* s);
extern stackElement peakLinkedList(LinkedStack* s);
extern void printLinkedList(LinkedStack* s);