#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 0, K = 0;
    int *newList = 0;
    int size = 0, maxK = 1, now = 0, Now = 0, turn = 0;
    int i = 0;

    scanf("%d %d", &N, &K);
    if (K < 1 || N < K || N > 5000) return 0;

    newList = (int *)malloc(sizeof(int) * N);
    while (i < N) {
        newList[i] = i + 1;
        i++;
    }
    size = N;

    printf("%d ", newList[K - 1]);
    newList[K - 1] = -1;
    size--;

    now = K;
    while(size > 0) {
        Now = (N * turn + now) % N;
        if (newList[Now] != -1 && maxK < K)
            maxK++;
        else if (newList[Now] != -1 && maxK == K) {
            printf("%d ", newList[now]);
            newList[now] = -1;
            maxK = 1;
            size--;
        }

        if (now < N - 1)
            now++;
        else {
            now = 0;
            turn++;
        }
    }
    return 0;
}