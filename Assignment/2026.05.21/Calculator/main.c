#include "Calculator.h"

int main() {
	char sample[100];
	printf("입력:\n");
	fgets(sample, sizeof(sample), stdin);
	sample[strlen(sample) - 1] = '\0';
	
	char postfix[100];

	inFixToPostfix(sample, postfix);

	printf("\n- Result: %d\n", evalPostfix(postfix));


	return 0;
}