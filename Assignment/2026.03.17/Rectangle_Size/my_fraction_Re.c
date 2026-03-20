#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_fraction_Re.h"

Fraction Create(char*  str) {
	Fraction f1 = { f1.num = 0, f1.den = 1 };
	if (strchr(str, '/') != NULL) {
		sscanf_s(str, "%d/%d", &f1.num, &f1.den);
		if (f1.den == 0) {
			printf("ERROR 분모에 0 불가능\n\n");
			return f1;
		}
		f1 = Simplify(f1.num, f1.den);
		return f1;
	}
	else if (strchr(str, '.') != NULL) {
		int count = strlen(strchr(str, '.') + 1);
		for (int i = 0; i < count; i++) { f1.den *= 10; }
		float fnum = atof(str);
		f1.num = fnum * f1.den;
		f1 = Simplify(f1.num, f1.den);
		return f1;
	}
	else if (str[0] == '0' || (atoi(str) > 0 && str[1] > 47 && str[1] < 58)) {
		f1.num = atoi(str);
		return f1;
	}
	else {
		printf("ERROR 형식 오류\n\n");
		f1.den = 0;
		return f1;
	}
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
	if (f2.num == 0) { printf("ERROR 0으로 나누기 불가능\n\n"); }
	result.num = f1.num * f2.den;
	result.den = f1.den * f2.num;
	result = Simplify(result.num, result.den);
	return result;
}

Fraction Simplify(int num, int den) {
	Fraction result;
	int nums = num, dens = den, remain;
	if (den < 0) { num *= -1; den *= -1; }
	while (dens != 0) {
		remain = nums % dens;
		nums = dens;
		dens = remain;
	}
	
	result.num = num / nums;
	result.den = den / nums;
	return result;
}

void Print(Fraction f1) {
	if(f1.den == 1) printf("%d", f1.num);
	else printf("%d/%d", f1.num, f1.den);
}

