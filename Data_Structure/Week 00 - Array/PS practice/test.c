#include <stdio.h>

ft_prefix_sum(int *arr)
{
    int idx = 0;
    int *sum[6] = {0}; // 과거엔 {0, }으로만 가능했음
    
	while (idx < 6)
	{
			if (idx == 0)
					sum[idx] = arr[idx];
			else
					sum[idx] = sum[idx - 1] + arr[idx];
	}
}

int main(){
	int arr[6] = {0, 1, 2, 3, 4, 5};
	int i = 0, j = 0, ans = 0;

	scanf("%d %d", &i, &j);
	ans = sum[j] - sum[i - 1];
       printf("%d", ans);

		return 0;
}