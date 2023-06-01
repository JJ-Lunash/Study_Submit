#include <stdio.h>

int ft_isFactor(int N, int i)
{
    if (i == 1)
        return (1);
    
    else if (i == N)
        return (N);

    else if (N % i == 0)
        return (i);

    return 0; 
}

int main(){
    int N = 0, K = 0;
    int arr[10000] = {0};
    int i = 1, cnt = 0;

    scanf("%d %d", &N, &K);
    if (N < 1 || N > 10000 || K < 1 || K > N)
        return 0;

    while (i <= N)
    {
        if (ft_isFactor(N, i))
        {
            arr[cnt] = ft_isFactor(N, i);
            cnt++;
        }
        i++;
    }

    if (cnt >= K)
        printf("%d", arr[K - 1]);
    else
        printf("0");

    return 0;
}

/*
<흐름>
경우1: N의 약수의 개수가 K보다 크거나같을때
    -> K번째인 약수 출력

경우2: N의 약수 개수가 K보다 작을 때
    -> 0 출력
    */


/* 
<필요한 재료들, 순서>

약수구하는 함수();

main함수(){
    배열 10000칸짜리 = {0};
    int 약수개수 = 0;

    while (N보다 작, 같을때까지)
    {
        if (약수구하는함수)
            배열[약수개수] = 약수구하는함수
    }

    if (약수개수 >= K)
        배열[K+1]번째가 답
    else
        0출력

    return 0;
}
*/