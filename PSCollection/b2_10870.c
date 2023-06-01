#include <stdio.h>

int	ftFibo(int index)
{
	if (index < 0) return (-1);
	else if (index == 0) return (0);
	else if (index == 1 || index == 2) return (1);

	return (ftFibo(index - 1) + ftFibo(index - 2));
}

int main(){
    int n;

    scanf("%d", &n);
    if (n < 2 || n > 20) return 0;
    printf("%d", ftFibo(n));

    return 0;
}