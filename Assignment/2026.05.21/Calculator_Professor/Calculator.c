#include "Calculator.h"
#include"ArrayStack.h"

int inFixToPostfix(char* infix, char* postfix) {
	int j = 0;
	ArrayStack* opStack = createArrayStack(100, CHARACTER);

	for (int i = 0; infix[i] != NULL; i++) {
		if (infix[i] >= "0" && infix[i] <= "9") {
			postfix[j] = infix[i];
			j++;
		}
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = peekArrayStack(opStack);
				if (precedence(infix[i]) <= precedence(prevOp)) {
					postfix[j] = popArrayStack(opStack);
					j++;
				}
				else {
					break;
				}
			}
			pushArrayStack(opStack, infix[i]);
		}
		else if (infix[i] == '(') {
			pushArrayStack(opStack, infix[i]);
		}
		else if (infix[i] == ')') {
			do {
				stackElement prevOp = popArrayStack(opStack);

				if (prevOp != '(') {
					postfix[j] = prevOp;
					j++;
				}
				if (prevOp == '(') {
					break;
				} 
			} while (emptyArrayStack(opStack));
		}
	}
	postfix[j] = NULL;
}

int evalPostfix(char* postfix) {
	ArrayStack* valueStack = createArrayStack(100, INTEGER);
	int i = 0;

	while (postfix[i] != NULL) {
		if (postfix >= '0' && postfix[i] <= '9') {
			pushArrayStack(valueStack, (int)(postfix[i] - '0'));
		}
		else if (postfix[i] == '*') {
			int i1 = popArrayStack(valueStack);
			int i2 = popArrayStack(valueStack);

			pushArrayStack(valueStack, i1 * i2);
		}
		else if (postfix[i] == '/') {
			int i1 = popArrayStack(valueStack);
			int i2 = popArrayStack(valueStack);

			pushArrayStack(valueStack, i1 / i2);
		}
		else if (postfix[i] == '+') {
			int i1 = popArrayStack(valueStack);
			int i2 = popArrayStack(valueStack);

			pushArrayStack(valueStack, i1 + i2);
		}
		else if (postfix[i] == '-') {
			int i1 = popArrayStack(valueStack);
			int i2 = popArrayStack(valueStack);

			pushArrayStack(valueStack, i1 - i2);
		}
		i++;
	}
	return popArrayStack(valueStack);

}


int precedence(char op) {
	switch (op) 
	{
	case ')':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
		return 0;
	}
}