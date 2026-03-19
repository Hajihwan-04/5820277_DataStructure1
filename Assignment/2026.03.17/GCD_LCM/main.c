#include <stdio.h>

#include "my_math.h"

int main() {
	Function num1, num2, GCD, LCM;

	printf("GCD와 LCD을 구할 정수 두 개를 입력하시오 : ");
	scanf_s("%d %d", &num1, &num2);

	GCD = Get_GCD(num1, num2);
	LCM = Get_LCM(num1, num2);

	printf("GCD: %d, LCM: %d", GCD, LCM);

	return 0;
}