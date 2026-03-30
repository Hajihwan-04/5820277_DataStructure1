#include <stdio.h>

#include "GCD.h"

int main() {
	unsigned long long f1, f2, GCD;


	for (int i = 5; i <= 93; i++) {
		f1 = Get_Fib(i - 1);
		f2 = Get_Fib(i);

		for (int j = 0; j <= 1000000; j++) {
			GCD = Get_GCD(f1, f2);
		}
		printf("%d>> GCD : %llu Fibonacci : %llu\n",i, GCD, f2);
		

	}
	return 0;
}