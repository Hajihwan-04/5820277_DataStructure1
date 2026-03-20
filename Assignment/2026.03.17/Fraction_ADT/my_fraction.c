#include <stdio.h>

#include "my_fraction.h"

Fraction Create(int num, int den) {
	Fraction f = { num, den };
	return f;
}
Fraction Add(Fraction f1, Fraction f2) {
	Fraction result;
	result.num = (f1.num * f2.den) + (f2.num * f1.den);
	result.den = f1.den * f2.den;
	result = Simplify(result.num, result.den);
	return result;
}

Fraction Subtract(Fraction f1, Fraction f2) {
	Fraction result;
	result.num = (f1.num * f2.den) - (f2.num * f1.den);
	result.den = f1.den * f2.den;
	result = Simplify(result.num, result.den);
	return result;
}

Fraction Multiply(Fraction f1, Fraction f2) {
	Fraction result;
	result.num = f1.num * f2.num;
	result.den = f1.den * f2.den;
	result = Simplify(result.num, result.den);
	return result;
}

Fraction Divide(Fraction f1, Fraction f2) {
	Fraction result;
	result.num = f1.num * f2.den;
	result.den = f1.den * f2.num;
	result = Simplify(result.num, result.den);
	return result;
}

Fraction Simplify(int num, int den) {
	Fraction result;
	int nums = num, dens = den, remain;
	while (dens != 0) {
		remain = nums % dens;
		nums = dens;
		dens = remain;
	}
	result.num = num / nums;
	result.den = den / nums;
	return result;
}

Fraction Print(Fraction f1) {
	if(f1.den == 1) printf("%d", f1.num);
	else printf("%d/%d", f1.num, f1.den);
}

