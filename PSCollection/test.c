#include <stdio.h>

int	ft_is_prime(int num)
{
    int i; 
	if (num < 0)
		return (0);
	if (num == 0 || num == 1)
		return (0);

	i = 2;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(){

    printf("%d", ft_is_prime(2));
    return 0;

}