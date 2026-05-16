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

extern int isEmptyLinkedList(DLinkedList* dl);
extern int sizeLinkedList(DLinkedList* dl);

extern int insertFirstDLinkedList(DLinkedList* dl, PointType item);
extern int insertLastDLinkedList(DLinkedList* dl, PointType item);
extern int insertItemDLinkedList(DLinkedList* dl , PointType* pre, PointType item);
extern PointType deleteFirstDLinkedList(DLinkedList* dl);
extern PointType deleteLastDLinkedList(DLinkedList* dl);
extern PointType deleteItemDLinkedList(DLinkedList* dl, PointType item);
extern int insertAtDLinkedList(DLinkedList* dl, int at, PointType item);
extern PointType deleteAtDLinkedList(DLinkedList* dl, int at);

extern PointType getItemDLinkedList(DLinkedList* dl, int pos);
extern void replaceItemDLinkedList(DLinkedList* dl, int pos, PointType item);
extern PointType nextItemDLinkedList(DLinkedList* dl, PointType* pre);

extern void printDLinkedList(DLinkedList* dl);