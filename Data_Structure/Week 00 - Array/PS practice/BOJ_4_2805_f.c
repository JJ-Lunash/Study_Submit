#include <stdio.h>

int ft_binsearch(int arr[], int start, int end, int key)
{
	int mid = 0;
	int i = 0;

	while (start <= end) // while(1)로 써도 될 듯
	{
			mid = (start + end) / 2;
			if (arr[mid] < key)
				start = mid + 1;
			else if (arr[mid] > key)
				end = mid - 1;
			else
				return (mid);
	}

	return (-1); // unsuccessful
}

int main(){
    long long n = 0, m = 0; // n: 나무 개수,  m:잘라 가져가려는 길이
    int i = 0;
    int h = 0; // h: 절단기 높이
    int tree_arr[1000000] = {0}; // 각 나무의 높이
    int max = 0; // 가장 높은 나무의 길이

    scanf("%d %d", &n, &m);
    if (n < 0 || n > 1000000 || m < 0 || m > 2000000000)
        return 0;

    while (i < n) // 나무의 개수만큼 각 나무의 길이를 배열에 저장 & 가장 높은 나무 길이 max 찾기
    {
        scanf("%d", &tree_arr[i]);
        if (tree_arr[i] < 0 || tree_arr[i] > 2000000000)
            return 0;
        max = (max < tree_arr[i]) ? tree_arr[i] : max;
    }



}