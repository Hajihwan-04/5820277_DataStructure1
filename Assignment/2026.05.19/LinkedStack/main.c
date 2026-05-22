#include <stdio.h>
#include <stdlib.h>

#include "LinkedStack.h"

stackElement getBrowser() {
	stackElement browser = (char*)malloc(sizeof(char) * 100);
	scanf_s("%s", browser, 100);

	return browser;
}

int main() {
	LinkedStack* myStack = createLinkedStack();
	int input;
	printf("1. URL 추가: URL을 입력받아 스택에 URL을 추가\n");
	printf("2. URL 제거 : URL을 입력받아 스택에서 URL을 제거\n");
	printf("3. 스택 확인 : 현재 스택에 저장된 URL의 마지막 값을 출력\n");
	int end = 0;
	while (end != 1) {
		printf("입력: ");
		scanf_s("%d", &input);
		switch (input) {
		case 1:
			printf("URL 입력 : ");
			stackElement browser = getBrowser();
			pushLinkedStack(myStack, browser);
			break;
		case 2:
			printf("이탈: %s\n", popLinkedList(myStack));
			if (emptyLinkedStack(myStack)) {
				break;
			}
			printf("현재 창: %s\n", peakLinkedList(myStack));
			free(myStack->head->data);
			break;
		case 3:
			printf("현재 창: %s\n", peakLinkedList(myStack));
			break;
		default:
			printf("잘못입력하였습니다.\n");
		}
		

		if (emptyLinkedStack(myStack)) {
			printf("브라우저가 종료되었습니다.");
			end = 1;
		}
	}

	destroyLinkedStack(myStack);
}