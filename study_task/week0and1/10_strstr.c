#include <stdlib.h>
#include "libft.h"

char *ft_strstr(char *str, char *to_find)
{
	int	now_idx;
	int	find_idx;
	int	i;

	now_idx = 0;
	i = 0;
	if (!to_find || to_find[0] == '\0')
		return (str);
	while (str[now_idx])
	{
		find_idx = now_idx;
		while (str[find_idx] == to_find[i] && str[find_idx])
		{
			find_idx++;
			i++;
		}
		if (to_find[i] == '\0')
			return (&str[now_idx]);
		now_idx++;
	}
	return (0);
}

// if 문에서 && || 조건이 많을 때 ...

/*

if (a || b || c || d) .. 라면
	- 하나의 조건이 맞을때 까지 체크
	- 하나라도 맞으면 조건 체크를 중단함
	- 만약에 위의 예시에서 b가 맞으면 c, d는 체크하지 않음

if (a && b && c && d) .. 라면
	- 모두가 맞을때 까지 체크
	- 하나라도 틀리면 조건 체크를 중단함
	- 만약에 위의 예시에서 b가 틀리면 c, d는 체크하지 않음

*/