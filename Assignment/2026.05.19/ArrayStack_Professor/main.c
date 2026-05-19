#include <stdio.h>
#include <stdlib.h>

#include "ArrayStack.h"

int main() {
	ArrayStack* myStack = createArrayStack(10);

	pushArrayStack(myStack, 10);
	pushArrayStack(myStack, 20);
	pushArrayStack(myStack, 30);

	printArrayStack(myStack);

	popArrayStack(myStack);
	popArrayStack(myStack);

	printArrayStack(myStack);
}