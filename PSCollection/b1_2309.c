#include <stdio.h>
#include <stdlib.h>

int *ftMinToMax(int *arr, int h, int i)
{
    int flag = 0, tmp = 0;

    if (i == 0) arr[i] = h;

    if (i != 0 && h > arr[i - 1]) arr[i] = h;
    else
        while (arr[i - 1] > h) // 처음에 arr[i] 라고 잘못 생각
        {
            if (flag == 0)
            {
                arr[i] = arr[i - 1];
                arr[i - 1] = h;
                flag = 1;
            }
            else if (flag == 1)
            {
                tmp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = tmp;
            }
            i--;
        }

    return (arr);
}

void ftFindSeven(int *arr)
{
    int sum = 0, i, j;

    for (i = 0; i <9; i++)
        sum += arr[i];

    for (i = 0; i < 8; i++)
    {
        for (j = 1; j < 9; j++)
        {
            if (sum - arr[i] - arr[j] == 100)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k == i || k == j) continue; // 의미적으로는 알면서 끝까지 생각 못했던 줄
                    printf("%d\n", arr[k]);
                }
                return; // 실행결과 오류보고 마지막에 추가
            }
        }
    }
}

int main() {
    int h;
    int i;
    int *arr = 0;

    arr = (int *)malloc((sizeof(int)) * 9);
    for (i = 0; i < 9; i++)
    {
        scanf("%d", &h);
        if (h < 0 || h > 100) return 0;
        arr = ftMinToMax(arr, h, i);
    }
    ftFindSeven(arr);
    free(arr);

    return 0;
}