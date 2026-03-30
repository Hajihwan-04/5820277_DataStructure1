# 2) 피보나치 수열의 시 복잡도 분석 및 프로파일링

## 1. 알고리즘 구현 코드
피보나치 수열 생성 및 유클리드 호제법을 수행하기 위해 작성된 C 언어 코드는 다음과 같다.
피보나치 수열 생성을 하는 $Get_Fib$ 함수는 $n$번째인 피보나치 수를 찾는 가능한 많은 연산을 거치는 방식 중 하나이고, 유클리드 호제법을 이용한 $Get_GCD$ 함수를 1,000,000번 반복하는 것은 걸리는 시간이 너무 짧아 시각화 하기 위함이다. 

```c
GCD.h

typedef unsigned long long Function;

//최대공약수를 구함
extern Function Get_GCD(Function num1, Function num2);
//피보나치 수열
extern unsigned long long Get_Fib(int fib);
```
```c
GCD.c

#include <stdio.h>
#include <stdlib.h>

#include "GCD.h"

Function Get_GCD(Function num1, Function num2) {
	if (num2 == 0) return num1;
	return Get_GCD(num2, num1 % num2);
}

unsigned long long Get_Fib(int fib) {
	if (fib <= 1) return fib;
	return Get_Fib(fib - 1) + Get_Fib(fib - 2);
}
```

```c
main.c

int main() {
    unsigned long long f1, f2, GCD;
    for (int i = 5; i <= 93; i++) {
        f1 = Get_Fib(i - 1);
        f2 = Get_Fib(i);
        
        // 프로파일링 측정을 위해 연산 반복
        for (int j = 0; j <= 1000000; j++) {
            GCD = Get_GCD(f1, f2);
        }
        
        printf("%d>> GCD : %llu Fibonacci : %llu\n", i, GCD, f2);
    }
    return 0;
}
```

## 2. 프로파일링 결과
$n$을 5부터 증가시키며 측정한 연산 시간 및 메모리 사용량의 추이는 다음과 같다.

### CPU 사용량 분석 및 메모리 사용량 분석
<img width="1278" height="659" alt="프로파일링 자료" src="https://github.com/user-attachments/assets/b67e46dd-d52e-4947-8d1b-722b4da04e94" />
<img width="1280" height="656" alt="CPU 사용량" src="https://github.com/user-attachments/assets/02201447-1930-47ba-8ef4-4edb55245d44" />

### 1) 에 대한 검증

#### • GCD 연산 시간 복잡도의 수학적 증명 (라메의 정리)
유클리드 호제법의 일반적인 시간 복잡도는 입력되는 두 수 중 작은 수를 $b$라고 할 때 $O(\log b)$이다. 즉, 입력값의 비트 수(자릿수)에 비례하여 연산 시간이 늘어난다.

본 과제에서는 피보나치 수열의 연속된 두 항 $F(n)$과 $F(n-1)$을 입력값으로 사용한다. 라메의 정리(Lamé's Theorem)에 따르면, 연속된 피보나치 수를 입력하는 것은 유클리드 호제법에서 가장 많은 나눗셈 연산을 발생시키는 최악의 경우(Worst Case)이다.

본 증명의 목표는 입력값 자체의 크기($F(n)$)가 아닌, **피보나치 수열의 인덱스 $n$을 기준으로 보았을 때 순수 GCD 연산의 시간 복잡도가 어떤 형태를 띠는지 수학적으로 도출**하는 것이다.

#### • 수학적 유도 과정
입력값의 크기($F(n)$)와 인덱스($n$) 사이의 수학적 연결 고리를 만들기 위해 피보나치 수열의 일반항 근사식을 이용한다.

1. **피보나치 수열의 일반항 근사식:**
   피보나치 수열은 $n$이 증가함에 따라 기하급수적으로 증가하며, 비네의 공식에 의해 다음과 같이 근사할 수 있다.
   $$F(n) \approx \frac{\phi^n}{\sqrt{5}}$$ 
   (단, $\phi$는 황금비 $\frac{1 + \sqrt{5}}{2} \approx 1.618$)

2. **이론적 시간 복잡도에 입력값 대입:**
   입력값 중 작은 수인 $b = F(n-1)$을 유클리드 호제법의 이론적 시간 복잡도 수식에 대입한다.
   $$T(n) = O(\log(F(n-1)))$$

3. **근사식 대입 및 로그 식 전개:**
   입력값 $F(n-1)$ 자리에 피보나치 근사식을 대입한다.
   $$T(n) = O\left(\log\left(\frac{\phi^{n-1}}{\sqrt{5}}\right)\right)$$
   로그의 성질($\log(a/b) = \log a - \log b$, $\log(a^b) = b\log a$)을 이용하여 위 식을 전개하면 다음과 같다.
   $$T(n) = O((n-1)\log\phi - \log\sqrt{5})$$

4. **빅오(Big-O) 표기법 적용:**
   빅오 표기법에서는 $n$에 무관한 상수항 ($-\log\sqrt{5}$, $-\log\phi$)과 상수의 곱 ($\log\phi$)은 무시하고 가장 높은 차수의 항만 남긴다.
   $$T(n) = O(n)$$

#### • 증명 결론
수학적 유도 결과, 입력값 자체의 크기에 대해서는 로그 $O(\log b)$ 복잡도를 가지지만, 연속된 피보나치 수의 **인덱스 $n$을 기준으로 보았을 때 순수 GCD 연산 단계는 선형 시간 복잡도인 $O(n)$** 으로 증가함을 알 수 있다.
<img width="533" height="319" alt="GCD_TIME" src="https://github.com/user-attachments/assets/bfd52de4-ab56-4f57-a681-b6d9b9468eda" />


## 3. 빅오(Big-O) 계산식 및 이론적 배경
유클리드 호제법의 시간 복잡도는 두 수 $a, b$가 주어졌을 때 $O(\log(\min(a, b)))$이다. 

특히, 유클리드 알고리즘에서 가장 많은 나눗셈 연산을 수행하게 되는 최악의 경우는 바로 연속된 두 피보나치 수를 입력했을 때이다. 이를 수학적으로 증명한 것이 라메의 정리(Lamé's Theorem)이다.

$F(n)$과 $F(n-1)$의 최대공약수를 구할 때, 유클리드 호제법은 정확히 $n-2$번의 나눗셈을 수행한다. 따라서 입력값의 크기가 아닌 인덱스 $n$을 기준으로 보았을 때, 연산 횟수는 $n$에 비례하여 선형적으로 증가하므로 시간 복잡도는 $O(n)$으로 표현할 수 있다.

(참고사항: 본 과제의 코드에서는 피보나치 수를 구하는 `Get_Fib` 함수가 재귀로 구현되어 있어 피보나치 계산 자체의 시간 복잡도는 $O(2^n)$이다. 따라서 실제 전체 프로파일링 시간은 피보나치 연산 시간에 큰 영향을 받게 된다.)


## 5. 결론 및 가설 검증
프로파일링 결과, 이론적인 계산식의 추세와 실제 자원 사용량의 변화가 일치하는지 확인할 수 있었다. 특히 연속된 피보나치 수가 유클리드 호제법의 최악의 경우를 만들어낸다는 라메의 정리를 실제 코드를 통해 실증하였으며, 이를 통해 앞선 1) 과제에서 세웠던 시간 복잡도 가설이 참임을 검증하였다.
