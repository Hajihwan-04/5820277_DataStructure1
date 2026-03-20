#include <stdio.h>
#include <stdlib.h>

int main() {
	char c[10];
	scanf_s("%s", c, (unsigned)sizeof(c));
	printf("%d", c[0]);

	return 0;
}