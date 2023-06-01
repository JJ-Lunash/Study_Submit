#include <stdio.h>

int ftFindGreatestCommonDiv(int n, int m)
{
    int small, i;
    small = n < m ? n : m;
    i = small;

    while (i > 0)
    {
        if ((n % i == 0 && m % i == 0))
            return (i);
        i--;
    }
    return (1);
}

int ftFindLeastCommonMul(int n, int m)
{
    if (n == m)
        return (n);

    else if (ftFindGreatestCommonDiv(n ,m) == 1)
        return (n * m);

    int originSmall, originBig, small, big;
    int i = 2, j = 2;
    originSmall = n < m ? n : m;
    originBig = n > m ? n : m;
    small = originSmall;
    big = originBig;

    while (1)
    {
        if (small < big)
            small = originSmall * i;
        else if (small == big)
            return (small);
        else
        {
            big = originBig * j;
            small = originSmall * i;
            j++;
        }
        i++;
    }

    return 0;
    // Q. while문 안의 return에서 무조건적으로 끝나는 경우, 마지막 리턴은 아무값이나 상관없다고 생각했는데 맞는지, 주로 어떻게 처리하는지 궁금
}

int main(){
    int n = 0, m = 0;
    int greatDiv = 0, leastMul = 0;

    scanf("%d %d", &n, &m);
    if (n < 0 || n > 10000 || m < 0 || m > 10000) return 0;

    greatDiv = ftFindGreatestCommonDiv(n, m);
    leastMul = ftFindLeastCommonMul(n, m);
    printf("%d\n%d", greatDiv, leastMul);

    return 0;
}