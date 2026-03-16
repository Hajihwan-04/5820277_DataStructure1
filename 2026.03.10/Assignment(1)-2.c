#include <stdio.h>

int main() {
	float fnum;
	printf("실수를 입력하세요 : ");
	scanf_s("%f", &fnum);
	int num = fnum * 256;

	for (int i = 15; i >= 0; i--) {
		int bit = (num >> i) & 1;
		printf("%d", bit);

		if (i == 8) printf(".");
	}
	return 0;
}
