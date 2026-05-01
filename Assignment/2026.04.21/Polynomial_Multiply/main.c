#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

int main() {
	polynomial* p1;
	p1 = getPolynomial();
	printf("다항식 1\n");
	printPolynomial(p1);

	polynomial* p2;
	p2 = getPolynomial();
	printf("다항식 2\n");
	printPolynomial(p2);

	polynomial* p3 = addPolynomial(p1, p2);
	printf("합 결과 값\n");
	printPolynomial(p3);

	polynomial* p4 = multiplePolynomial(p1, p2);
	printf("곱셈 결과 값\n");
	printPolynomial(p4);

	destoryArrayList(p1);
	destoryArrayList(p2);
	destoryArrayList(p3);
	destoryArrayList(p4);
	return 0;
}