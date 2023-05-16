#include "./libft.h"

void *ft_memcpy(void *dest, const void *source, size_t n)
{
    size_t i = 0;
    unsigned char *temp_dest = (unsigned char *)dest;
    unsigned char *temp_source = (unsigned char *)source;

    while (i < n)
    {
        *temp_dest = *temp_source;
        temp_dest++;
        temp_source++;
        i++;
    }
    return (dest);
}