#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *dest = malloc(sizeof(char) * (len + 1));
    int i;

    if (!s || !dest)
        return (0);
    i = 0;
    while (i < len)
    {
        dest[i] = s[start + i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}