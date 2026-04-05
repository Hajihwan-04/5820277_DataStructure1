#include <stdio.h>

#define N 5

int main() {
	if (N % 2 == 0 || N < 0) {
		printf("짝수, 음수는 불가"); return 1;
	}
	printf("[%d x %d 마방진]\n\n",N, N);
	

	int arr[N][N] = {0}, size = N * N;
	int x = ((N - 1) / 2) - 1, y = 1;
	for (int i = 1; i < size + 1; i++) {
		y--;
		if (y < 0) { y = N -1; }
		x++;
		if (x > N - 1) { x = 0; }

		if (arr[y][x] != 0) {
			y += 2;
			x -= 1;
			if (y > N - 1) { y -= N; }
			if (x < 0) { x = N - 1; }
		}
		arr[y][x] = i;
	}
	int sumArrX[N] = { 0 }, sumArrY[N] = { 0 }, sumArrD[2] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("|%3d ", arr[i][j]);
			
			for (int x1 = 0; x1 < N; x1++) {
				if (i == x1) { sumArrX[x1] += arr[i][j]; }
			}
			for (int y1 = 0; y1 < N; y1++) {
				if (j == y1) { sumArrY[y1] += arr[i][j]; }
			}
			if (i == j) { sumArrD[0] += arr[i][j]; }
			if (i + j == N - 1) { sumArrD[1] += arr[i][j]; }
		}
		printf("|\n");
		for (int dash = 0; dash < (N * 5 + 1); dash++) { printf("-"); }
		printf("\n");
	}
	
	for (int x2 = 0; x2 < N; x2++) {
		printf("가로 %2d열 합 : %d\n", x2, sumArrX[x2]);
	}
	printf("\n");
	for (int y2 = 0; y2 < N; y2++) {
		printf("세로 %2d행 합 : %d\n",  y2, sumArrY[y2]);
	}
	
	
	printf("\n");
	printf("0, 0에서 %d, %d방향 대각선 : %d\n", N - 1, N - 1, sumArrD[0]);
	printf("%d, 0에서 0, %d방향 대각선 : %d\n", N - 1, N - 1, sumArrD[1]);
}