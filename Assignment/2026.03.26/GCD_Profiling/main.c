#include <stdio.h>

#include "GCD.h"

int main() {
	Function num1, num2, GCD;
	while (1) {
		printf("GCD를 구할 정수 두 개를 입력하시오 : ");
		scanf_s("%d %d", &num1, &num2);
		if (num1 == 0 || num2 == 0) { printf("ERROR 잘못 입력하셨습니다\n");  continue; }
		if (num1 < 0 || num2 < 0) { printf("음수를 양수로 변환하여 진행 ••• \n"); num1 = abs(num1); num2 = abs(num2); }
		break;
	}
	GCD = Get_GCD(num1, num2);

	printf("GCD: %d", GCD);

	return 0;
}