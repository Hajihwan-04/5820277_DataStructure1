#include <stdio.h>
#include <stdlib.h>

int main() {
	char c[10];
	scanf_s("%s", c, (unsigned)sizeof(c));
	int i = atoi(c);
	printf("%s\n", c);
	printf("%d", i);

	return 0;
}