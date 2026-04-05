#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	printf("마방진 크기 : ");
	scanf_s("%d", &N);
	if (N <= 0 || N % 2 == 0) { printf("0, 음수, 짝수는 불가"); return 1; }

	int** matrix = (int**)malloc(sizeof(int*) * N);
	if (matrix == NULL) { printf("No more memory!"); return 1; }

	for (int y = 0; y < N; y++) {
		*(matrix + y) = (int*)malloc(sizeof(int) * N);
		if (*(matrix + y) == NULL) { printf("No more memory!"); return 1; }
	}

	int x = ((N - 1) / 2) - 1, y = 1;
	for (int i = 1; i < N + 1; i++) {
		y--;
		if (y < 0) { y = N - 1; }
		x++;
		if (x > N - 1) { x = 0; }

		if (**((matrix + y) + x) != 0) {
			y += 2;
			x -= 1;
			if (y > N - 1) { y -= N; }
			if (x < 0) { x = N - 1; }
		}
		**((matrix + y) + x) = i;
	}

	int* sumArrY = (int*)malloc(sizeof(int) * N);
	int* sumArrX = (int*)malloc(sizeof(int) * N);
	int sumArrD = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("|%3d ", **((matrix + y) + x));
		}
	}

	

	
	free(sumArrY);
	free(sumArrX);

	for (int y = 0; y < N; y++) {
		free(*(matrix + y));
	}
	free(matrix);
	return 0;
}