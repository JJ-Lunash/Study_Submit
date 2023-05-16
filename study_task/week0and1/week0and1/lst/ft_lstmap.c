//구글링의 도움을 많이받아서 써둔 코드, 
//아직 이해를 완벽히 하지 못했으나 이해를 다하고 올리기엔 너무 오래걸릴거같아서
//올리고 마저 이해해보겠습니당

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *newnode;
    t_list *rst_node;

    rst_node = NULL;
    while (lst)
    {
        newnode = ft_lstnew(f(lst->content));
        if (!newnode)
        {
            ft_lstclear(&rst_node, del);
            return ((void*)(0));//특히 이 줄은 내가 생각해서 쓴 코드 X
        }
        ft_lstclear(&rst_node, newnode);
        lst = lst->next;
    }
    newnode = NULL;
    return (rst_node);
}