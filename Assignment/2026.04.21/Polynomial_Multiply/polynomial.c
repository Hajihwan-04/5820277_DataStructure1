#include "polynomial.h"

polynomial* getPolynomial() {
	polynomial* po = createPolynomial(100);
	char s1[100] = {0};
	printf("다항식을 입력하시오 : ");
	scanf_s("%s", s1,(unsigned)sizeof(s1));
	int pos = 0;
	char s2[10] = {0};
	for (int i = 0, j = 0; i < 100 && j < 10; i++) {
		if (s1[i] == '+' || s1[i] == '\0') {
			s2[j] = '\0';
			sscanf_s(s2, "%dX^%d", &po->data[pos].coef, &po->data[pos].expo);
			s2[0] = '\0';
			j = 0;
			po->size++;
			pos++;
			if (s1[i] == '\0') break;
		}
		else {
			s2[j] = s1[i];
			j++;
		}
	}
	return po;
}

polynomial* createPolynomial(int capacity) {
	polynomial* po = (polynomial*)createArrayList(capacity);
	return po;
}
polynomial* addItemPolynomial(polynomial* po, elementType item) {
	int i;
	for (i = 0; i < sizeArrayList(po); i++) {
		if (po->data[i].expo <= item.expo) {
			break;
		}
	}

	if (i == sizeArrayList(po)) {
		insertArrayList(po, i, item);
	}

	else if (po->data[i].expo == item.expo) {
		po->data[i].coef += item.coef;
	}
	else {
		insertArrayList(po, i, item);
	}
	return po;
}

polynomial* addPolynomial(polynomial* p1, polynomial* p2) {
	polynomial* r = createPolynomial(100);
	int i = 0, j = 0;

	while (i < sizeArrayList(p1) && j < sizeArrayList(p2)) {
		if (p1->data[i].expo < p2->data[j].expo) {
			addItemPolynomial(r, p2->data[j]);
			j++;
		}
		else if (p1->data[i].expo > p2->data[j].expo) {
			addItemPolynomial(r, p1->data[i]);
			i++;
			
		}
		else {
			addItemPolynomial(r, (elementType) { p1->data[i].coef + p2->data[j].coef, p1->data[i].expo });
			i++;
			j++;
		}
	}
	if (i >= sizeArrayList(p1)) {
		for (; j < sizeArrayList(p2); j++) {
			addItemPolynomial(r, p2->data[j]);
		}
	}
	if (j >= sizeArrayList(p2)) {
		for (; i < sizeArrayList(p1); i++) {
			addItemPolynomial(r, p1->data[i]);
		}
	}
	return r;
}

polynomial* multiplePolynomial(polynomial* p1, polynomial* p2) {
	polynomial* po1 = (polynomial*)createPolynomial(100);
	polynomial* po2 = (polynomial*)createPolynomial(100);
	polynomial* result = (polynomial*)createPolynomial(100);

	for (int i = 0; i < p1->size; i++) {
		for (int j = 0; j < p2->size; j++) {
			addItemPolynomial(result, (elementType) { p1->data[i].coef * p2->data[j].coef, p1->data[i].expo + p1->data[j].expo });
		}
	}
	return result;
}

void printPolynomial(polynomial* po) {
	printf("Polynomial: \n");

	printArrayList(po);
	printf("\n");
}