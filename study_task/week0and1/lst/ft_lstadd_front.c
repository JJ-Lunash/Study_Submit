#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (lst == NULL || new == NULL)
        return;
    else 
        new -> next = *lst;
        *lst = new;
}

/*
- lst는 t_list 포인터의 주소를 가리키는 변수
- new느 추가할 노드의 주소를 가리키는 t_list의 포인터
-즉, lst는 t_list 포인터를 가리키며 현재 *lst가 가리키는 곳은 연결 리스트의 제일 첫 번째 노드
*/