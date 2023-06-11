// part2 (2023.06.02.Fri ~ 2023.06.04.Sun)
#include <stdio.h>
#include <stdlib.h>

int ftPrime(int n)
{
	int i = 2;

	if (n <= 0 || n == 1)	return (0);
	while (i * i <= n)
	{
		if (n % i == 0) return 0;
		i++;
	}

	return (1);
}

int ftSum(int *arr)
{
    int i = 0, sum = 0;

    while(arr[i])
    {
        if (ftPrime(arr[i]))
            sum += arr[i];
        i++;
    }

    if (sum == 0) return (0);

    return (sum);
}

int ftFindMin(int *arr)
{
    int  i = 1, min = 0, flag = 0;
    while (arr[i])
    {
        if (ftPrime(arr[i]) == 1 && flag == 0)
		{
            min = arr[i];
			flag = 1;
		}
		else if (ftPrime(arr[i]) == 1 && flag == 1)
			min = min > arr[i] ? arr[i] : min;
        i++;
    }

    if (min == 0) return (0);

    return (min);
}

int main(){
    int M = 0, N = 0, i = 0;
    int *arr = 0;

    scanf("%d", &M);
    scanf("%d", &N);
    if (M < 0 || M > 10000 || N < 0 || N > 10000 || M > N) return 0;
    int size = N - M + 1;
    arr = (int *)malloc(sizeof(int) * size);
    for (i = 0; i < size; i++)
    {
        arr[i] = M;
        M++;
    }
    int sum = ftSum(arr);
    int min = ftFindMin(arr);

    if (sum == 0 || min == 0)
    {
        printf("-1");
        return 0;
    }
    printf("%d\n%d\n", sum, min);
    free(arr);

    return 0;
}

// min 구하는 함수에서 flag 안쓰고 min을 가장 큰 값으로 초기화 하는 방법도 있음