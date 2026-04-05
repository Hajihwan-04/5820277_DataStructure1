#include <stdio.h>
#include <stdlib.h>

#define N 100

int main() {
	int arr[N], big = 0, small = N;
	long sum = 0;

	//N개의 배열에 임의의 수 채움
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % N;
	}

	printf("순서대로 출력\n");
	for (int i = 0; i < N; i++) {
		printf("|%3d: %3d|", i + 1, arr[i]);
		if ((i + 1) % 5 == 0 && i != 0) printf("\n");
	}

	printf("--------------------------------------------------\n");

	printf("뒤에서부터 출력\n");
	for (int i = 99; i >= 0; i--) {
		printf("|%3d: %3d|", i + 1, arr[i]);
		if (i % 5 == 0 && i != 99) printf("\n");
	}

	for (int i = 0; i < 100; i++) {
		sum += arr[i];
		if (big < arr[i]) big = arr[i];
		if (small > arr[i]) small = arr[i];
	}

	printf("--------------------------------------------------\n");

	printf("배열총합 : %ld\n최대값   : %d\n최소값   : %d", sum, big, small);

	return 0;
}