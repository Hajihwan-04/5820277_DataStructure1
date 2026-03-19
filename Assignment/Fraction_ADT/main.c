#include <stdio.h>

#include "my_fraction.h"

int main() {
	Fraction f1, f2, result;
	char op;
	printf("분수 계산기\n");
	while (1) {
		printf("ex)[분수] [연산자] [분수]\n분수는 [분자/분모]\n");
		if (scanf_s("%d/%d %c %d/%d", &f1.num, &f1.den, &op, 1, &f2.num, &f2.den) != 5) {
			printf("ERROR 형식 오류\n");
			while (getchar() != '\n');
		}
		else {
			int pass = 0;
			switch (op) {
			case '+':result = Add(f1, f2); break;
			case '-':result = Subtract(f1, f2); break;
			case '*':result = Multiply(f1, f2); break;
			case '/':result = Divide(f1, f2); break;
			default: printf("ERROR 연산자 오류\n"); pass = 1;
			}
			if (pass == 0) break;
		}
	}
	Print(result);
	return 0;
}