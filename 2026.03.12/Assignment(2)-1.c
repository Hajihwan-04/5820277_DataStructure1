#include <stdio.h>

int main() {
	float fnum = 0;
	int sign = 0;
	int binary[32] = { 0 };

	printf("실수를 입력하세요 : ");
	scanf_s("%f", &fnum);

	//부호비트지정 이후 실수가 음수면 양수로 바꿈
	if (fnum < 0) sign = 1, fnum *= -1;
	else sign = 0;
	binary[0] = sign;

	//실수의 정수부와 소수부를 나눔
	int usfnum = fnum;
	float decimal_fnum = fnum - usfnum;

	// 양수화된 실수가 1 이상인 경우와 미만인 경우로 나눔
	if (fnum >= 1) { //실수 1 이상
		//정수부를 이진법으로 변환함 
		int remainder[127] = { 0 }, count = -1; //count 변수는 지수부를 위함
		while (usfnum >= 1) {
			count++;
			remainder[count] = usfnum % 2;
			usfnum /= 2;
		}

		//정수부를 가수부로
		int putRema = count, countRema = putRema;
		for (int remaInt = 9; remaInt < 9 + countRema; remaInt++, putRema--) {
			binary[remaInt] = remainder[putRema - 1];
		}

		//소수부를 가수부로
		int countDeci = 9 + countRema;
		while (decimal_fnum != 1) {
			if (decimal_fnum == 0) break;
			decimal_fnum *= 2;
			if (decimal_fnum > 1) {
				binary[countDeci] = 1;
				decimal_fnum -= 1;
			}
			else if (decimal_fnum < 1) binary[countDeci] = 0;
			else binary[countDeci] = 1;
			countDeci++;
		}


		//지수부
		int exponent = 127 + count;
		for (int expoInt = 8; expoInt >= 1; expoInt--) {
			binary[expoInt] = exponent % 2;
			exponent /= 2;
		}
	}

	else { //실수 1 미만
		//정수는 없으므로 소수부를 이진법으로 변환
		int position = 0, count = 0, oneCount = 0; //count 변수는 지수부를 위함
		while (decimal_fnum != 1) {
			decimal_fnum *= 2;
			if (decimal_fnum > 1) {
				decimal_fnum -= 1;
				if (oneCount == 0) {
					oneCount = 1;
					count++;
				}
				else {
					position++;
					binary[8 + position] = 1;
				}

			}
			else if (decimal_fnum < 1) {
				if (oneCount == 0) {
					count++;
				}
				else {
					position++;
					binary[8 + position] = 0;
				}
			}
			else {
				if (oneCount == 0) {
					count++;
				}
				else {
					position++;
					binary[8 + position] = 1;
				}
			}

		}
		//지수부
		int exponent = 127 - count;
		for (int expoInt = 8; expoInt >= 1; expoInt--) {
			binary[expoInt] = exponent % 2;
			exponent /= 2;
		}
	}

	//IEEE 754 단정도로 출력
	for (int i = 0; i <= 31; i++) {
		printf("%d", binary[i]);
		if (i == 0 || i == 8) printf("/");
		else if ((i % 4) == 0) printf(" ");
	}
	return 0;
}
