#include <stdio.h>

int main(){
    int presum[100000] = {0};
    int n = 0, m = 0;
    int i = 0, j = 0;
    int k = 0;

    scanf("%d", &n);
    while (k < n)
    {
        scanf("%d", &i);
        if (i < -1000 || i > 1000)
            return 0;
        if (k == 0)
            presum[k] = i;
        presum[k] = presum[k - 1] + i;
        k++;
    }
    scanf("%d", &m);
    k = 0;
		while (k < m)
		{
			scanf("%d %d", &i, &j);
            if (i < 1 || j > n || i > j)
                return 0;
               i--; // ~
                j--; 
            if (i == 0) 
			    printf("%d\n", presum[j]);
            else
                printf("%d\n", presum[j] - presum[i - 1]);
			k++; // .
		}
		
		return 0;
}