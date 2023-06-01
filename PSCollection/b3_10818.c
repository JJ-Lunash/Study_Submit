#include <stdio.h>

int main(){
    int N, num;
    int min = 0, max = 0;
    int i;

    scanf("%d", &N);
    if (N < 1 || N > 1000000) return 0;
    for(i = 0; i < N; i++)
    {
        scanf("%d", &num);
        if (i == 0) // 가장 마지막에 추가한 줄
            min = max = num;
        min = min > num ? num : min;
        max = max < num ? num : max;

    }
    printf("%d %d", min, max);

    return 0;
}

/*
< 마주했던 문제점 및 해결>
- 문제점: max값이 제대로 저장이 안되고 min값을 따라가는 것 같았음
- 이유 : 난 처음 시작할때만 일단 min=max=num해두고 그걸 기준으로
        min과 max를 계속 업데이트하고 싶었던건데, 그냥 min=max=num만 써주면
        자꾸 그 줄에서 다시 num으로 초기화 됨
- 해결 : min = max = num의 조건으로 if(i==0)을 붙여주자.
        처음에만 작용되도록!*/