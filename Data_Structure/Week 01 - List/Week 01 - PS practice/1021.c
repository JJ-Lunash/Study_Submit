#include <stdio.h>



int main(){
    int N = 0, M = 0;
    int position = 0;
    int i = 1;

    scanf("%d %d", &N, &M);
    if (N < 0 || N > 50 || M < 0 || M > N)
        return 0;
    int arr[N];
    while (i <= N) // 크기가 N인 배열 만들기
    {
        arr[i] = i;
        i++;
    }

    i = 0; // 뽑을 개수만큼 첫 위치 입력받기
    while (i < M)
    {
        scanf("%d", &position);
        if (position < 1 || position > N)
            return 0;
        i++;
    }

    

}

// 덱( = 양방향 큐) 사용 문제
