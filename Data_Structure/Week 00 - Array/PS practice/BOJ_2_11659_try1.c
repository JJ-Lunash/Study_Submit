#include <stdio.h>

int main(){
    int N = 0; // 입력받을 수
    int M = 0; // 합을 구해야하는 횟수
    int num = 0; // N개만큼 입력받을 각각의 수
    int i = 0, j = 0; // M개의 줄만큼 주어질 합을 구해야 하는 구간 i와 j
    int k = 0;
    int sum = 0;
    int *num_arr = 0, *sum_arr = 0;

    scanf("%d %d", &N, &M);
    if (N < 0 || N > 1000 || M == 0)
        return 0;

    while (k < N)
    {
        scanf("%d", &num);
        num_arr[k] = num;
        k++;
    }

    k = 0;
    while (k < M)
    {
        scanf("%d %d", &i, &j);
        if (i >= N || j > N)
            return 0;
        while (i <= j)
        {
            sum += num_arr[i - 1];
            i++;
        }
        sum_arr[k] = sum;
        sum = 0;
        k++;
    }

    k = 0;
    while(sum_arr[k])
    {
        printf("%d\n", sum_arr[k]);
        k++;
    }

    return 0;
}