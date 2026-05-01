#include "arrayList.h"

typedef arrayList polynomial;

extern polynomial* getPolynomial();
extern polynomial* createPolynomial(int capacity);
extern polynomial* addItemPolynomial(polynomial* po, elementType item);
extern polynomial* addPolynomial(polynomial* p1, polynomial* p2);
extern polynomial* multiplePolynomial(polynomial* p1, polynomial* p2);

extern void printPolynomial(polynomial* po);