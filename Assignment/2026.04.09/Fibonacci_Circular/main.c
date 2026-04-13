#include <stdio.h>
#include <time.h>

unsigned long long fibo(int n) {
	unsigned long long f1 = 1;
	unsigned long long f2 = 1;

	if (n == 1) {
		return f1;
	}
	else if (n == 2) {
		return f2;
	}
	else {
		unsigned long long fn = 0;
		for (int i = 3; i <= n; i++) {
			fn = f1 + f2;
			f1 = f2;
			f2 = fn;
		}
		return fn;
	}
}


int main() {
	int N;
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &N);
	clock_t start, end;
	double current_time;
	unsigned long long result;
	FILE* file;
	fopen_s(&file, "FiboCircular.csv", "w");

	if (file == NULL) {
		printf("파일을 열 수 없습니다\n");
		return 1;
	}

	for (int i = 1; i <= N; i++) {
		start = clock();
		for (int j = 0; j <= 5000000; j++) {
			result = fibo(i);
		}
		end = clock();
		current_time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("%3.d 번째 | %20.llu | %.3lf초\n", i, result, current_time);
		fprintf(file, "%d,%llu,%lf\n", i, result, current_time);
	}

	fclose(file);
	return 0;
}