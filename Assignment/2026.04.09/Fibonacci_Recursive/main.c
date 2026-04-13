#include <stdio.h>
#include <time.h>

unsigned long long fibo(int n) {

	if (n <= 2) {
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}


int main() {
	int N;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &N);
	clock_t start, end;
	double current_time;
	unsigned long long result;
	FILE* file;
	fopen_s(&file, "FiboRecursive.csv", "w");

	if (file == NULL) {
		printf("파일을 열 수 없습니다\n");
		return 1;
	}
	for (int i = 1; i <= N; i++) {
		start = clock();
		result = fibo(i);
		end = clock();
		current_time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("%3.d 번째 | %20.llu | %.3lf초\n", i, result, current_time);
		fprintf(file, "%d,%llu,%lf\n", i, result, current_time);
	}
	fclose(file);
	return 0;
}