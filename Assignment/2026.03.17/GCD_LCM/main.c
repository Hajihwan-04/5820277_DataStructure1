#include <stdio.h>

#include "my_math.h"

int main() {
	Function num1, num2, GCD, LCM;
	while (1) {
		printf("GCD와 LCD을 구할 정수 두 개를 입력하시오 : ");
		scanf_s("%d %d", &num1, &num2);
		if (num1 == 0 || num2 == 0) { printf("ERROR 잘못 입력하셨습니다\n");  continue; }
		if (num1 < 0 || num2 < 0) { printf("음수를 양수로 변환하여 진행 ••• \n"); num1 = abs(num1); num2 = abs(num2); }	
		GCD = Get_GCD(num1, num2);
		LCM = Get_LCM(num1, num2);
		break;
	}

	printf("GCD: %d, LCM: %d", GCD, LCM);

	return 0;
}