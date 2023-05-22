#include <stdio.h>
#include <stdlib.h>

long long binSearch (long long *treeList, long long N, long long M, long long right)
{
    long long left = 1, mid = 0, sum = 0, cutMax = 0;
    long long i = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;
        i = 0;
        sum = 0; // 이거 빼먹고 못찾아서 꽤나 고생
        while (i < N) // long long형 배열에서는 while(treeList[i]) 쑬 수 없나
        {
            if (treeList[i] > mid)
                sum += (treeList[i] - mid);
            i++;
        }
        if ((sum >= M && (rights - left == 0 || right - left == 1)) || sum == M)
        {
            cutMax = mid;
            break;
        }
        else
        {
            if (sum > M)
                left = mid + 1;
            else if (sum < M)
                right = mid - 1;
        }
    }

    return (cutMax);
}

int main(){
    long long N = 4, M = 7, eachNum = 0, i = 0;
    long long right = 0, cutMax = 0;

    scanf("%lld %lld", &N, &M);
    if (N < 1 || N > 1000000 || M < 1 || M > 2000000000)
        return 0;
    long long *treeList = (long long *)malloc(sizeof(long long) * N);
    while (i < N)
    {
        scanf("%lld", &eachNum); // 처음엔 eachNum이라는 변수를 따로 만들어줬었음
        if (eachNum < 0 || eachNum > 1000000000)
            return 0;
        treeList[i] = eachNum;
        right = eachNum > right ? eachNum : right;
        i++;
    }

    cutMax = binSearch(treeList, N, M, right);
    free(treeList);
    printf("%lld", cutMax);

    return 0;
}