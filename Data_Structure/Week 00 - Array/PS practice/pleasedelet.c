#include <stdio.h>

int main() {
    int n, m, i, start, end, mid, t, tree_arr[1000000]; //end == max
    scanf("%d %d", &n, &m);
    start = end = max = 0;
    i = 0;

    while (i < n)
    {
        scanf("%d", &tree_arr[i]);
        max = (max < tree_arr[i]) ? tree_arr[i] : max;
        i++;
    }
    //
    while (start < end) {
        t = m, r = (p + q) >> 1; -> r은 mid
        //아하 그러면 p는 left, q는 right네!
        for (i = 0; i < n && t > 0; ++i)
            if (a[i] > r) t -= (a[i] - r);
        if (t > 0) q = r;//자르는 나무의 길이의 합이 m보다 크면 left = r
        else p = r + 1;
    }
    printf("%d", p - 1);
    return 0;
}