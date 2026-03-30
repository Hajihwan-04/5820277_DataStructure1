/*
#include <time.h>

int main() {
    unsigned long long f1, f2, GCD;
    clock_t start_fib, end_fib, start_GCD, end_GCD;
    double current_time1, current_time2;
    FILE* file;

    fopen_s(&file, "result.csv", "w");

    if (file == NULL) {
        printf("파일을 열 수 없습니다\n");
        return 1;
    }

    fprintf(file, "번호,시간,최대공약수,피보나치수\n");
    f1 = 2; f2 = 3;
    for (int i = 5; i <= 93; i++) {

        start_fib = clock();

        //f1 = Get_Fib(i - 1);
        //f2 = Get_Fib(i);

        unsigned long long fn = f1 + f2;
        f1 = f2;
        f2 = fn;
        end_fib = clock();
        current_time1 = (float)(end_fib - start_fib) / CLOCKS_PER_SEC;

        start_GCD = clock();

        for (int j = 0; j <= 1000000; j++) {
            GCD = Get_GCD(f1, f2);
        }

        end_GCD = clock();
        current_time2 = (float)(end_GCD - start_GCD) / CLOCKS_PER_SEC;

        printf("%d번째 피보나치시간 : %f초 피보나치 : %llu, GCD시간 : %f초 GCD : %llu\n", i, current_time1, f2, current_time2, GCD);
        fprintf(file, "%d,%f,%llu,%f,%llu\n", i, current_time1, f2, current_time2, GCD);
    }

    fclose(file);
    return 0;
}
*/