#include "Calculator.h"
#include"ArrayStack.h"

int inFixToPostfix(char* infix, char* postfix) {
	int j = 0;
	char op[100], value[100];
	int opCount = 0, valueCount = 0;
	ArrayStack* opStack = createArrayStack(100, CHARACTER);

	printf("Transform:\n");
	for (int i = 0; infix[i] != NULL; i++) {
		if (infix[i] >= '0' && infix[i] <= '9') {
			postfix[j] = infix[i];
			j++;
			value[valueCount++] = infix[i];
		}
		stackElement item;
		item.operator = infix[i];
		if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = peekArrayStack(opStack);
				if (precedence(infix[i]) <= precedence(prevOp.operator)) {
					postfix[j] = popArrayStack(opStack).operator;
					j++;
					opCount--;
				}
				else {
					break;
				}
			}
			pushArrayStack(opStack, item);
			op[opCount++] = infix[i];
		}
		else if (infix[i] == '(') {
			pushArrayStack(opStack, item);
			op[opCount++] = infix[i];
		}
		else if (infix[i] == ')') {
			do {
				stackElement prevOp = popArrayStack(opStack);
				opCount--;
				if (prevOp.operator != '(') {
					postfix[j] = prevOp.operator;
					j++;
				}
				if (prevOp.operator == '(') {
					break;
				} 
			} while (!emptyArrayStack(opStack));
			
		}
		if (infix[i + 1] != NULL) {
			printf("- Postfix: ");
			for (int k1 = 0; k1 < j; k1++) {
				printf("%c ", postfix[k1]);
			}
			printf(" | Stack: ");
			for (int k2 = 0; k2 < opStack->top + 1; k2++) {
				printf("%c ", op[k2]);
			}
			printf("\n");
		}
		else {
			printf("- Postfix: ");
			for (int k1 = 0; k1 < j; k1++) {
				printf("%c ", postfix[k1]);
			}
			for (int k2 = opStack->top; k2 > -1; k2--) {
				printf("%c ", op[k2]);
			}
			printf(" | Stack: ");
			printf("\n");
			printf("\n");
		}
		
	}
	for (int i = opStack->top; i > -1; i--) {
		stackElement item = popArrayStack(opStack);
		postfix[j] = item.operator;
		j++;
	}

	postfix[j] = NULL;
}

int evalPostfix(char* postfix) {
	ArrayStack* valueStack = createArrayStack(100, INTEGER);
	int i = 0;
	int stack[100];
	int stackCount = 0;
	printf("Eval:\n");
	printf("- Postfix: ");
	for (int k1 = 0; ; k1++) {
		if ((postfix[k1] >= '0' && postfix[k1] <= '9') || (postfix[k1] == '+' || postfix[k1] == '-' || postfix[k1] == '*' || postfix[k1] == '/')) {
			printf("%c ", postfix[k1]);
		}
		else {
			break;
		}
	}
	printf("\n");

	while (postfix[i] != NULL) {
		printf("- Current: ");
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			stackElement item;
			item.value = (int)(postfix[i] - '0');
			
			stack[stackCount++] = item.value;
			pushArrayStack(valueStack, item);
			printf("%d ", item.value);
		}
		else if (postfix[i] == '*') {
			stackElement i1 = popArrayStack(valueStack);
			stackElement i2 = popArrayStack(valueStack);
			stackElement i3;
			i3.value = i1.value * i2.value;

			stackCount -= 2;
			stack[stackCount++] = i3.value;

			printf("%c ", postfix[i]);
			pushArrayStack(valueStack, i3);
		}
		else if (postfix[i] == '/') {
			stackElement i1 = popArrayStack(valueStack);
			stackElement i2 = popArrayStack(valueStack);
			stackElement i3;
			i3.value = i1.value / i2.value;

			stackCount -= 2;
			stack[stackCount++] = i3.value;

			printf("%c ", postfix[i]);
			pushArrayStack(valueStack, i3);
		}
		else if (postfix[i] == '+') {
			stackElement i1 = popArrayStack(valueStack);
			stackElement i2 = popArrayStack(valueStack);
			stackElement i3;
			i3.value = i1.value + i2.value;
			stackCount -= 2;
			stack[stackCount++] = i3.value;
			printf("%c ", postfix[i]);
			pushArrayStack(valueStack, i3);
		}
		else if (postfix[i] == '-') {
			stackElement i1 = popArrayStack(valueStack);
			stackElement i2 = popArrayStack(valueStack);
			stackElement i3;
			i3.value = i1.value - i2.value;
			stackCount -= 2;
			stack[stackCount++] = i3.value;
			printf("%c ", postfix[i]);
			pushArrayStack(valueStack, i3);
		}
		printf(" | Stack: ");
		for (int k2 = 0; k2 < stackCount; k2++) {
			printf("%d ", stack[k2]);
		}
		
		printf("\n");
		i++;
	}
	return popArrayStack(valueStack).value;

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