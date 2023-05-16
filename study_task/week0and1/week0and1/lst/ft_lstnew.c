#include "libft.h"

t_list *ft_lstnew(void const *content)
{
    t_list *new;

    new = (t_list*)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new -> content = content;
    new -> next = NULL;
    return (new);
}

/*
1. 새 노드를 저장할 t_list 포인터 변수 new를 선언
2. malloc을 통하여 new에 t_list의 크기만큼 메모리 할당
   (할당에 실패하는 경우 NULL 반환)
3. 할당한 뒤, new의 next에는 NULL을, content에는 인자로 받은 content를 대입
4. new를 return해주기
*/