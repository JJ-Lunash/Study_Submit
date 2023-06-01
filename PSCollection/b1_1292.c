#include <stdio.h>

void ftFillValue(int *arr)
{
    int cnt = 0, i, j;

    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (cnt == 1000) break;
            arr[cnt] = i;
            cnt++;
        }
    }
}

int main(){
    int A, B, sum = 0, i;
    int arr[1000] = {0};

    scanf("%d %d", &A, &B);
    if (A < 1 || A > B || B > 1000) return 0;

    ftFillValue(arr);
    for (i = A - 1; i < B; i++) // 처음에 i = A; i <= B 라고 써서 인덱스가 하나씩 더 크게 밀려남
        sum += arr[i];
    printf("%d\n", sum);

    return 0;
}