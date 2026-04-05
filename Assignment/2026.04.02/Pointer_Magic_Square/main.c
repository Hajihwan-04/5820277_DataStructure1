#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	printf("마방진 크기 : ");
	scanf_s("%d", &N);
	printf("\n");
	if (N <= 0 || N % 2 == 0) { printf("0, 음수, 짝수는 불가"); return 1; }

	int** matrix = (int**)malloc(sizeof(int*) * N);
	if (matrix == NULL) { printf("No more memory!"); return 1; }

	for (int y = 0; y < N; y++) {
		*(matrix + y) = (int*)calloc(N, sizeof(int));
		if (*(matrix + y) == NULL) { printf("No more memory!"); return 1; }
	}

	int x = ((N - 1) / 2) - 1, y = 1;
	for (int i = 1; i < N * N + 1; i++) {
		y--;
		if (y < 0) { y = N - 1; }
		x++;
		if (x > N - 1) { x = 0; }

		if (*(*(matrix + y) + x) != 0) {
			y += 2;
			x -= 1;
			if (y > N - 1) { y -= N; }
			if (x < 0) { x = N - 1; }
		}
		*(*(matrix + y) + x) = i;
	}

	int* sumArrX = (int*)calloc(N, sizeof(int));
	if (sumArrX == NULL) { printf("No more memory!"); return 1; }
	int* sumArrY = (int*)calloc(N, sizeof(int));
	if (sumArrY == NULL) { printf("No more memory!"); return 1; }
	int sumArrD[2] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("|%3d ", *(*(matrix + i) + j));

			for (int x1 = 0; x1 < N; x1++) {
				if (i == x1) { *(sumArrX + x1) += *(*(matrix + i) + j); }
			}
			for (int y1 = 0; y1 < N; y1++) {
				if (j == y1) { *(sumArrY + y1) += *(*(matrix + i) + j); }
			}
			if (i == j) { sumArrD[0] += *(*(matrix + i) + j); }
			if (i + j == N - 1) { sumArrD[1] += *(*(matrix + i) + j); }
		}

		printf("|\n");
		for (int dash = 0; dash < (N * 5 + 1); dash++) { printf("-"); }
		printf("\n");
	}

	for (int x2 = 0; x2 < N; x2++) {
		printf("가로 %2d열 합 : %d\n", x2, *(sumArrX + x2));
	}
	printf("\n");
	for (int y2 = 0; y2 < N; y2++) {
		printf("세로 %2d행 합 : %d\n", y2, *(sumArrY + y2));
	}
	
	
	printf("\n");
	printf("0, 0에서 %d, %d방향 대각선 : %d\n", N - 1, N - 1, sumArrD[0]);
	printf("%d, 0에서 0, %d방향 대각선 : %d\n", N - 1, N - 1, sumArrD[1]);

	free(sumArrY);
	free(sumArrX);

	for (int y = 0; y < N; y++) {
		free(*(matrix + y));
	}
	free(matrix);
	return 0;
}