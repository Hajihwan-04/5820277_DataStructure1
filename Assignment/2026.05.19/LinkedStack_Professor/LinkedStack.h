#include <stdio.h>
#include <stdlib.h>

typedef int stackElement;

typedef struct node {
	stackElement data;
	struct node* next;
} Node;

typedef struct lickedStack {
	Node* head;
	int size;
} LinkedStack;

extern LinkedStack* createLinkedStack();
//extern destroyLinkedStack()
extern int emptyLinkedStack(LinkedStack* s);
extern int fullLinkedStack(LinkedStack* s);
extern int pushLinkedStack(LinkedStack* s, stackElement item);
//extern pop
extern void printLinkedList(LinkedStack* s);