#include <string.h>

int flow_chk(const char *str, int i)
{
	int lo = 0;
	int flag = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		lo = 1;
		flag = (str[i] == '-');
	}
	while (str[i + lo])
	{
		if (str[i + lo] < '0' || str[i + lo] > '9')
			return 0;
		lo++;
	}
	if (lo - 1 > 10)
		return 0;
	if (lo - 1 < 10)
		return 1;
	if (flag == 0)
		return (strcmp(str, "2147483647") <= 0);
	else
		return (strcmp(str, "2147483648") <= 0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	sum;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (flow_chk(str, i) == 0)
		return 0;
	else
	{
		sum = 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			sum = sum * 10 + (str[i] - '0');
			i++;
		}
		return (sign * sum);
	}
}

#include <stdio.h>

int main(){
	char *str = "1247483650";
	int rst;

	rst = ft_atoi(str);
	printf("%d\n", rst);
	return 0;
}

// #include <stdio.h>
// int main(){
// 	char str[][12] = {"0", "125", "-3612", "2147483647", "2147483648", "2147483649", "-2147483648", "-2147483649", "-2147483650"};
// 	int rst[9];
// 	int i = 0;

// 	while (str[i])
// 	{
// 		rst[i] = ft_atoi(str[i]);
// 		printf("%d\n", rst[i]);
// 		i++;
// 	}
// 	return 0;
// }