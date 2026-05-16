#include <stdio.h>
#include <stdlib.h>

typedef struct pointType {
	int x;
	int y;
	struct pointType* prev;
	struct pointType* next;
} PointType;

typedef struct dLinkedList {
	PointType head;
	int size;
} DLinkedList;

extern DLinkedList* createDLinkedList();
extern void destroyDLinkedList(DLinkedList* dl);

extern int insertFirstDLinkedList(DLinkedList* dl, PointType item);
extern int insertLastDLinkedList(DLinkedList* dl, PointType item);

extern PointType deleteFirstDLinkedList(DLinkedList* dl);

extern void printDLinkedList(DLinkedList* dl);