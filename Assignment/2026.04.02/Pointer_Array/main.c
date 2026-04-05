#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &N);
	int sum = 0, big = 0, small = N;

	int* arr = (int*)malloc(sizeof(int) * N);

	if (arr == NULL) {
		printf("No more memory");
		return 1;
	}

	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		*(arr + i) = rand() % N;
	}
	printf("순서대로 출력\n");
	for (int i = 0; i < N; i++) {
		printf("%3d: %4d  |", i + 1, *(arr + i));
		if ((i + 1) % 5 == 0 && i != 0) printf("\n");
	}
	printf("------------------------------------------------------------\n");


	printf("뒤에서부터 출력\n");
	for (int i = 99; i >= 0; i--) {
		printf("%3d: %4d  |", i + 1, *(arr + i));
		if (i % 5 == 0 && i != 99) printf("\n");
	}
	printf("------------------------------------------------------------\n");


	for (int i = 0; i < 100; i++) {
		sum += *(arr + i);
		if (big < *(arr + i)) big = *(arr + i);
		if (small > *(arr + i)) small = *(arr + i);
	}
	printf("------------------------------------------------------------\n");

	printf("배열총합 : %ld\n최대값   : %d\n최소값   : %d\n", sum, big, small);

	free(arr);
	return 0;
}