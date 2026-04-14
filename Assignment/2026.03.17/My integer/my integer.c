#include <stdio.h>
#include <stdlib.h>

#include "my_integer.h"

my_integer add(my_integer i, my_integer j) {
	return i + j;
}
my_integer minus(my_integer i, my_integer j) {
	return i - j;
}
my_integer mult(my_integer i, my_integer j) {
	return i * j;
}
my_integer divid(my_integer i, my_integer j) {
	if (i % j != 0) {
		printf("Divide error\n");
		return 0;
	}
	return i / j;
}