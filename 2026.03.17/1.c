#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int c, char** v) {

	printf("c: %d\n", c);
	for (int i = 0; i < c; i++) {
		printf("v%d: %s\n",i, v[i]);
	}
	int a = atoi(v[1]), b = atoi(v[2]);
	printf("sum : %d", a + b);
	//ㅁㄴㅇㅁㄴㅇ
}