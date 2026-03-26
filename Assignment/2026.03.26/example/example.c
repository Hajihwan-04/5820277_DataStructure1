#include <stdio.h>

#define COUNT 100000

int main()
{
    // 1~1000의 숫자를 랜덤하게 가지는 배열
    int data[COUNT];
    for (int i = 0; i < COUNT; i++) {
        data[i] = COUNT - i;
    }
    //정렬되지 않은 데이터 출력
    printf("랜덤하게 섞여있는 데이터 값 : ");
    for (int i = 0; i < COUNT; i++)
    {
        printf("%d ", data[i]);
    }
    //오름차순 정렬
    for (int i = 0; i < COUNT - 1; i++)
    {
        for (int j = 0; j < COUNT - 1 - i; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    //오름차순 정렬된 출력
    printf("\n\n버블 정렬을 사용하여 오름차순한 결과 : ");
    for (int i = 0; i < COUNT; i++)

    {

        printf("%d ", data[i]);

    }
    return 0;
}

