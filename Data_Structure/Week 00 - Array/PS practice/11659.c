#include <stdio.h>

int main(){
		int presum[100000] = {0};
		int n = 0, m = 0;
		int i = 0, j = 0;
		int k = 0;
		// n: 수의 총 개수, m: 합을 구해야하는 횟수
		// i: start 위치, j: end 위치
		
		scanf("%d %d", &n, &m);
		
		while (k < n)
		{
				scanf("%d", &i);
                if (i < 0)
                    return 0;
                if (k == 0)
                    presum[0] = i;
				presum[k] = presum[k - 1] + i;
				k++;
		}
		
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

/* 처음 코드 짤 때, presumA - presumB에서 B가 맨 첫 번째 칸일 때의 경우를
생각을 못하고 경우를 안나눠줘서 틀림 */