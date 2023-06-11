#include <stdio.h>

int rec(int *arr, int N, int M, int cnt)
{
    int cnt = 0, i;

    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    
    for (int i = 1; i <= N; i++)
    {
        int exist = 0; // 필요한 부분에서 선언하기
        for (int j = 0; j < cnt; j++)
        {
            if (arr[j] == i)
                exist = 1;
        }
        if(exist == 0)
        {
            arr[cnt] = i;
            rec(arr, cnt + 1, N, M);
        }
    }
    }
}

int main(){
    int N, M;
    int intArr[8] = {0};

    scanf("%d %d", &N, &M);
    if (M < 1 || N < M || N > 8) return 0;

    rec(intArr, N, M, 0); // 꼭 변수만 매개변수로 넣을 수 있는게 아님 상수도 사용 가능

    return 0;
}

// 시간 복잡도의 경우, 재귀함수를 사용하기 때문에 상대적으로 크다.
/*
< 시간복잡도 외울거 >
- N^N : 중복이 가능, N = 8까지 가능
- N! : 중복이 불가, N = 10까지 가능
- 즉, 백트래킹은 숫자 10 언저리까지만 가능하다! 알고 사용하기!
*/

/* 문제풀때 항상 습관으로 적고 시작할 것
1. 아이디어
    - 백트래킹 재귀함수 안에서 for문 돌면서 숫자 선택
    (이때 방문여부 확인)
    - 재귀함수에서 M개를 선택할 경우 print
2. 시간복잡도
    - N! -> 문제에서 최대8이니까 백트래킹 가능
3. 자료구조
- 방문 여부 확인 배열 : bool[]
- 선택한 값 입력 배열 : int[]
*/