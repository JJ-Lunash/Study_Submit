// // part2 (2023.06.02.Fri ~ 2023.06.04.Sun)
#include <stdio.h>
// #include <stdlib.h>

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

    return (sum);
}

int ftFindMin(int *arr)
{
    int  i = 1, min = arr[0], flag = 0;
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

    return (min);
}

int main(){
	int i = 0, j = 60;
	int arr[41] = {0};

	while(i < 41)
	{
		arr[i] = j;
		i++; j++;
	}

    int sum = ftSum(arr);
    int min = ftFindMin(arr);

    if (sum == -1 || min == -1)
    {
        printf("-1");
        return 0;
    }
    printf("%d\n%d\n", sum, min);
    // free(arr);

    return 0;
}