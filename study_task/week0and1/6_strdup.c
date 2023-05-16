#include <stdlib.h>

// static 함수 : 해당 파일 내에서만 사용되는 함수.
static int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	int		i;
	int		src_len;
	char	*dest;
	char	*temp;

	i = 0;
	src_len = ft_strlen(src);
	dest = malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (NULL);
	temp = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp);
}