#include <stdio.h>

int main(){
    int N = 0;
    int max = 0;
    float avg = 0;
    int i = 0;

    scanf("%d", &N);
    int score[N];

    while (i < N)
    {
        scanf("%d", &score[i]);
        if (max < score [i])
            max = score[i];
        i++;
    }

    i = 0;
    while(i < N)
    {
        avg += (float)score[i] / max * 100;
        i++;
    }

    printf("%f\n", avg / N);

    return 0;
}
