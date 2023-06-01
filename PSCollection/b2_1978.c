#include <stdio.h>
#include <stdlib.h>

int ftFindPrimeNum(int *arr, int N)
{
    int i, j, primeNum = 0;

    for(i = 0; i < N; i++)
    {
        for (j = arr[i] - 1; j > 0; j--)
        {
            if (arr[i] == 1 || (arr[i] % j == 0 && j != 1))
                break;
            else if (j == 1)
                primeNum++;
        }
    }

    return (primeNum);
}

int main(){
    int N, i;
    int *arr = 0;

    scanf("%d", &N);
    if (N < 0 || N > 100) return 0;

    arr = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < 0 || arr[i] > 1000) return 0;
    }
    printf("%d", ftFindPrimeNum(arr, N));
    free(arr);

    return 0;
}