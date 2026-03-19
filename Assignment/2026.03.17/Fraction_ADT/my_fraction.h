typedef struct Fraction { int num; int den; } Fraction;

//분수를 구조체를 이용해 하나의 자료로 생성
extern Fraction Create(int num, int den);
//분수의 덧셈
extern Fraction Add(Fraction f1, Fraction f2);
//분수의 뺄셈
extern Fraction Subtract(Fraction f1, Fraction f2);
//분수의 곱셈
extern Fraction Multiply(Fraction f1, Fraction f2);
//분수의 나눗셈
extern Fraction Divide(Fraction f1, Fraction f2);
//기약분수로 변형
extern Fraction Simplify(int num, int den);
//분수를 출력함
extern Fraction Print(Fraction f1);

