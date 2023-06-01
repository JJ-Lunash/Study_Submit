#include <stdio.h>

int main() {
    int out, in, sum = 0, max = 0;
    int i;

    for (i = 0; i < 10; i++)
    {
        scanf("%d %d", &out, &in);
        sum += in - out; // 인원 수 업데이트
        max = sum > max ? sum : max;
    }
    printf("%d", max);

    return 0;
}