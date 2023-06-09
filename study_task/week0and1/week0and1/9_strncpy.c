#include <sys/types.h>

char *ft_strncpy(char *dest, char *src, size_t n)
{
	size_t i = 0;

	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}