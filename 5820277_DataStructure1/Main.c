#include <stdio.h>
#include <stdlib.h>

int main() {
	int f1 = 1, f2 = 1;
	for (int i = 3; i < 20; i++) {
		int fn = f1 + f2;
		f1 = f2;
		f2 = fn;
		printf("%d: %d\n", i, fn);
	}
	return 0;
}