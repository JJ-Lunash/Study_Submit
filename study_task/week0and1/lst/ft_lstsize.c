#include "libft.h"

size_t ft_lstsize(t_list *lst)
{
    int size = 0;

    if (!lst)
        return (0);
    while (lst)
    {
        size++;
        lst = lst->next;
    }
    return (size);
}