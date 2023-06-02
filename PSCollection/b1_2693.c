#include <stdio.h>
#include <stdlib.h>

void ftAscending(int *arr)
{
    int i, j, tmp = 0;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 9; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(){
    int T, i, j;
    int *arr = 0;

    scanf("%d", &T);
    if (T < 1 || T > 1000) return 0;

    arr = (int *)malloc(sizeof(int) * 10);
    for (i = 0; i < T; i++)
    {
        for (j = 0; j < 10; j++)
        {
            scanf("%d", &arr[j]);
            if (arr[j] < 1 || arr[j] > 1000) return 0;
        }
        ftAscending(arr);
        printf("%d\n", arr[7]);
    }
    free(arr);

    return 0;
}