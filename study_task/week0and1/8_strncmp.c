#include <sys/types.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i = 0;

	while (((s1[i] != '\0') || (s2[i] != '\0')) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}	
	return (0);
}

/* 세 번째 인자에서 unsinged int로 명시해주는 이유는?
    : 길이는 양수만 가능하기 때문에 unsinged로 명시해줌 */

/* 리턴값에서 unsigned를 붙여주는 이유는?
    : */