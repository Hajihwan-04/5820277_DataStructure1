#include <stdio.h>
#include <stdlib.h>

int getFibo(int n) {
	int f1 = 1, f2 = 1;
	int fn = 1;
	for (int i = 3; i <= n; i++) {
		fn = f1 + f2;
		f1 = f2;
		f2 = fn;
		printf("%d: %d\n", i, fn);
	}
	return fn;
}

int main() {
	printf("%d", getFibo(2));
	return 0;
}