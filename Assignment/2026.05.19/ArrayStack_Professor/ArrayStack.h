#include <stdio.h>
#include <stdlib.h>

typedef int stackElement;

typedef struct arrayStack {
	stackElement* data;
	int top;
	int size;
} ArrayStack;

extern ArrayStack* createArrayStack(int size);
// extern int destroyArrayStack(ArrayStack* s);
// initStack
extern int pushArrayStack(ArrayStack* s, stackElement item);
extern stackElement popArrayStack(ArrayStack* s);
// peekStack
extern int printArrayStack(ArrayStack* s);
extern int emptyArrayStack(ArrayStack* s);
extern int fullArrayStack(ArrayStack* s);